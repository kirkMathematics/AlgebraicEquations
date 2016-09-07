#include <stdbool.h>
#include <string>
#include "linear_equation.h"

Term::Term(int _coefficient, int _var_ids[][2], int _exponent)
{
  this->coefficient = _coefficient;
  for (int i = 0; i < sizeof(this->var_ids); i++) {
    if (_var_ids[i][0] != -2) {
      this->var_ids[i][0] = _var_ids[i][0];
      this->var_ids[i][1] = _var_ids[i][1];
    } else {
      break;
    }
  }
  this->exponent = _exponent;
}

Term::Term(int _coefficient, int _var_ids[][2])
{
  this->coefficient = _coefficient;
  for (int i = 0; i < sizeof(this->var_ids); i++) {
    if (_var_ids[i][0] != -2) {
      this->var_ids[i][0] = _var_ids[i][0];
      this->var_ids[i][1] = _var_ids[i][1];
    } else {
      break;
    }
  }
  this->exponent = 1;
}

Term::Term(int _coefficient)
{
  this->coefficient = _coefficient;
  this->var_ids[0][0] = 0;
  this->var_ids[0][1] = 0;
  this->exponent = 1;
}

bool Term::is_like_term(Term& o)
{
  if (o.var_ids == this->var_ids && o.exponent == this->exponent) {
    return true;
  } else {
    return false;
  }
}

Term Term::add_term(Term& o)
{
  /*
   * Can only add like terms.
   */
  if (this.is_like_term(o) == 1) {
    int new_coefficient = this->coefficient + o.coefficient;
    Term new_term(new_coefficient, this->var_ids, this->exponent);
    return new_term;
  } else {
    Term null_term(0, this->var_ids, this->exponent);
    return null_term;
  }
}

std::string Term::str()
{
  if (this->coefficient == 0) {
    std::string str1 = "0";
    return str1;
  }
  
  std::string str = std::to_string(this->coefficient);
  
  for (int i = 0; i < sizeof(this->var_ids); i++) {
    int var_id = this->var_ids[i][0];
    int var_exp = this->var_ids[i][1];
    if (var_id != 0) {
      str = str + "(x" + std::to_string(var_id);
      if (var_exp > 1) {
        str = str + "^" + std::to_string(var_exp);
      }
      str = str + ")";
    } else {
      break;
    }
  }
  
  if (this->exponent != 1) {
    str = "(" + str + ")^" + std::to_string(this->exponent);
  }
  return str;
}