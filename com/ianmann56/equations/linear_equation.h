#include <stdbool.h>
#include <string>

class Term
{
  /*
    coefficient and var_ids work together to define the term.
    so 5(x^3) would have coefficient of 5, var_ids[0][0] of 1, var_ids[0][1] of 3
    and exponent of 1. while (3y)^5 would have coefficient of 3,
    var_ids[0][0] of 2, var_ids[0][1] of 1 and exponent of 5
  */
  public:
    Term(int _coefficient, int _var_ids[][2], int _exponent);
    Term(int _coefficient, int _var_ids[][2]);
    Term(int _coefficient);
    int coefficient;
    // ie. x1, x2, x3^2 would be represented as [1,1], [2,1], [3,2].
    // The first item in the pair represents the identifyer,
    // the second item represents the exponent for that variable
    int var_ids[50][2];
    int exponent;
    bool is_like_term(Term& o);
    std::string str();
    Term* add_term(Term& o);
    Term* subtract_term(Term& o);
    Term* multiply_term(Term& o);
    Term* divide_term(Term& o);
};

class LinearEquation
{
  public:
    //Terms defined on the left side of the "="
    Term left_terms[50];
    //Terms defined on the right side of the "="
    Term right_terms[50];
    void simplify();
    std::string str();
};