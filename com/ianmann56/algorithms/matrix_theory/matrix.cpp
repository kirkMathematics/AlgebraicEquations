#include "matrix.h"
#include <string>
#include <stdio.h>

Matrix::Matrix(int _matrix[][100]) {
  int num_rows = rows_in_matrix(this->columns);
  for (int column = 0; column < sizeof(this->columns); column++) {
    for (int row = 0; row < num_rows; row++) {
      this->columns[column][row] = _matrix[column][row];
    }
  }
}

std::string Matrix::str() {
  int num_rows = rows_in_matrix(this->columns);
  std::string s = "[ ";

  for (int row = 0; row < num_rows; row++) {
    for (int column = 0; column < sizeof(&this->columns); column++) {
      s = s + std::to_string(this->columns[column][row]) + ",";
    }
    if (row < num_rows) {
      s = s + "\n";
    }
  }

  return s + " ]";
}

int rows_in_matrix(int matrix[][100]) {
	for(int row = 0; row < 100; row ++) {
		for(int column = 0; column < sizeof(&matrix); column ++) {
			if(matrix[column][row] != 0) {
				continue;
			}
		}
		/*
		 * If loop ends, all columns are 0 which represents
		 * a non existant equation. So we just return row.
		 */
		return row;
	}
	/*
	 * If loop ends, there really are 100 equations.
	 */
	return 100;
}
