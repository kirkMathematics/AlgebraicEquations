#include <stdio.h>
#include "matrix.h"

int main(int argc, char **argv) {
	int matrix_temp[3][100] = {{1,3,2}, {6,2,8}, {3,0,1}};
	Matrix m(matrix_temp);

	printf("Matrix is: \n%s", m.str().c_str());
}
