#include <stdio.h>
#include <string>
#include "com/ianmann56/equations/linear_equation.h"

int main(int argc, char** args)
{
  int var_ids[3][2] = {{1, 1}, {2, 4}, {-2, 1}};
  int var_ids2[3][2] = {{1, 1}, {-2, 1}};
  Term t(5, var_ids);
  Term a(4, var_ids2);
  printf("%s\n", t.str().c_str());
  printf("%d", t.is_like_term(a));
  return 0;
}
