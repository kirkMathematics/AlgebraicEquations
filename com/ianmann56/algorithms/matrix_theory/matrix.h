#include <stdbool.h>
#include <string>

class Matrix
{
	public:
		Matrix(int matrix[][100]);
		/*
		 * The layout of the matrix will be columns
		 * that contain each member of each row for
		 * that column. So to access an element,
		 * indexing is as follows: column ---> row
		 */
		int columns[100][100];
		/*
     * convert this matrix to reduced
     * row echelon form
     */
    int to_rre();
		std::string str();
};

class AugmentedMatrix : public Matrix
{
	public:
		/*
		 * This 2D array represents the right
		 * side of the matrix or in the case of
		 * linear equations, the constants on the
		 * right side of the equal sign.
		 */
		int right_matrix[1][100];
	private:
		/*
		 * solve this matrix for each row.
		 * Assume that each row will be solved for
		 * the variable following the one above it.
		 *
		 * For example:
		 *   if a matrix has three rows of three columns
		 *   and one answer column, then the rows resulting
		 *   when solved will have the first row for
		 *   the first column variable, the second row for
		 *   the second column variable and the third row
		 *   for the third column variable.
		 */
		void solve();
};

/*
 * Returns the number of equations in a matrix. This
 * assumes that all existing equations are above any
 * "all zero" equations.
 */
int rows_in_matrix(int matrix[][100]);
