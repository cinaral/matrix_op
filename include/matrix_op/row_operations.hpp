/*
 * matrix_op
 *
 * MIT License
 *
 * Copyright (c) 2022 Cinar, A. L.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef ROW_OPERATIONS_HPP_CINARAL_220924_1502
#define ROW_OPERATIONS_HPP_CINARAL_220924_1502

#include "types.hpp"

namespace matrix_op
{
/* `replace_row<OPT:N_ROW, M_COL>(row_idx, row, mat)`:
 * Replaces a row of an matrix by a vector.
 */
template <size_t N_ROW, size_t M_COL>
static void
replace_row(const size_t row_idx, const Real_T (&row)[M_COL], Real_T (&mat)[N_ROW][M_COL])
{
	for (size_t i = 0; i < M_COL; ++i) {
		mat[row_idx][i] = row[i];
	}
}
} // namespace matrix_op

#endif
