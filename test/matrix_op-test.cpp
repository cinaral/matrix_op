#include "matrix_op/matrix_operations.hpp"

using matrix_op::Real_T;
using matrix_op::size_t;

constexpr size_t n_row_A = 2;
constexpr size_t m_col_A = 3;
constexpr size_t m_col_B = 3;
constexpr Real_T A[n_row_A][m_col_A] = {{1., 2., 3.}, {4., 5., 6.}};
constexpr Real_T B[m_col_A][m_col_B] = {{1., 2., 3.}, {-1., -2., 3.}, {1., -1., 3.}};
constexpr Real_T x[n_row_A] = {1, -1};

constexpr Real_T mul_ref[m_col_A] = {-3., -3., -3.};
constexpr Real_T A_tr_ref[m_col_A][n_row_A] = {{1., 4.}, {2., 5.}, {3., 6.}};
constexpr Real_T AB_ref[n_row_A][m_col_B] = {{2., -5., 18.}, {5, -8, 45}};

int
main()
{
	Real_T A_tr[m_col_A][n_row_A];
	matrix_op::transpose<n_row_A, m_col_A>(A, A_tr);

	Real_T mul[m_col_A];
	matrix_op::right_multiply(A_tr, x, mul);

	Real_T AB[n_row_A][m_col_B];
	matrix_op::multiply<n_row_A, m_col_A, m_col_B>(A, B, AB);

	bool success = true;

	for (size_t i = 0; i < m_col_A; ++i) {
		for (size_t j = 0; j < m_col_A; ++j) {
			if (A_tr_ref[i][j] - A_tr[i][j]) {
				success = false;
			}
		}
	}

	for (size_t i = 0; i < m_col_A; ++i) {
		if (mul_ref[i] - mul[i]) {
			success = false;
		}
	}

	for (size_t i = 0; i < n_row_A; ++i) {
		for (size_t j = 0; j < m_col_B; ++j) {
			if (AB_ref[i][j] - AB[i][j]) {
				success = false;
			}
		}
	}

	if (success) {
		return 0;
	} else {
		return 1;
	}
}