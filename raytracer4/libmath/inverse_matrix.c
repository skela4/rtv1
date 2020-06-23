/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 16:37:14 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/05 18:02:33 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

static	void	inverse_matrix_part_3_4(t_matrix_4 inv, const t_matrix_4 m)
{
	inv[M20] = m[M01] * m[M12] * m[M33] + m[M02] * m[M13] * m[M31] +
	m[M03] * m[M11] * m[M32] - m[M31] * m[M12] * m[M03] -
	m[M32] * m[M13] * m[M01] - m[M33] * m[M11] * m[M02];
	inv[M21] = m[M00] * m[M12] * m[M33] + m[M02] * m[M13] * m[M30] +
	m[M03] * m[M10] * m[M32] - m[M30] * m[M12] * m[M03] -
	m[M32] * m[M13] * m[M00] - m[M33] * m[M10] * m[M02];
	inv[M22] = m[M00] * m[M11] * m[M33] + m[M01] * m[M13] * m[M30] +
	m[M03] * m[M10] * m[M31] - m[M30] * m[M11] * m[M03] -
	m[M31] * m[M13] * m[M00] - m[M33] * m[M10] * m[M01];
	inv[M23] = m[M00] * m[M11] * m[M32] + m[M01] * m[M12] * m[M30] +
	m[M02] * m[M10] * m[M31] - m[M30] * m[M11] * m[M02] -
	m[M31] * m[M12] * m[M00] - m[M32] * m[M10] * m[M01];
	inv[M30] = m[M01] * m[M12] * m[M23] + m[M02] * m[M13] * m[M21] +
	m[M03] * m[M11] * m[M22] - m[M21] * m[M12] * m[M03] -
	m[M22] * m[M13] * m[M01] - m[M23] * m[M11] * m[M02];
	inv[M31] = m[M00] * m[M12] * m[M23] + m[M02] * m[M13] * m[M20] +
	m[M03] * m[M10] * m[M22] - m[M20] * m[M12] * m[M03] -
	m[M22] * m[M13] * m[M00] - m[M23] * m[M10] * m[M02];
	inv[M32] = m[M00] * m[M11] * m[M23] + m[M01] * m[M13] * m[M20] +
	m[M03] * m[M10] * m[M21] - m[M20] * m[M11] * m[M03] -
	m[M21] * m[M13] * m[M00] - m[M23] * m[M10] * m[M01];
	inv[M33] = m[M00] * m[M11] * m[M22] + m[M01] * m[M12] * m[M20] +
	m[M02] * m[M10] * m[M21] - m[M20] * m[M11] * m[M02] -
	m[M21] * m[M12] * m[M00] - m[M22] * m[M10] * m[M01];
}

static	void	inverse_matrix_part_1_2(t_matrix_4 inv, const t_matrix_4 m)
{
	inv[M00] = m[M11] * m[M22] * m[M33] + m[M12] * m[M23] * m[M31] +
	m[M13] * m[M21] * m[M32] - m[M31] * m[M22] * m[M13] -
	m[M32] * m[M23] * m[M11] - m[M33] * m[M21] * m[M12];
	inv[M01] = m[M10] * m[M22] * m[M33] + m[M12] * m[M23] * m[M30] +
	m[M13] * m[M20] * m[M32] - m[M30] * m[M22] * m[M13] -
	m[M32] * m[M23] * m[M10] - m[M33] * m[M20] * m[M12];
	inv[M02] = m[M10] * m[M21] * m[M33] + m[M11] * m[M23] * m[M30] +
	m[M13] * m[M20] * m[M31] - m[M30] * m[M21] * m[M13] -
	m[M31] * m[M23] * m[M10] - m[M33] * m[M20] * m[M11];
	inv[M03] = m[M10] * m[M21] * m[M32] + m[M11] * m[M22] * m[M30] +
	m[M12] * m[M20] * m[M31] - m[M30] * m[M21] * m[M12] -
	m[M31] * m[M22] * m[M10] - m[M32] * m[M20] * m[M11];
	inv[M10] = m[M01] * m[M22] * m[M33] + m[M02] * m[M23] * m[M31] +
	m[M03] * m[M21] * m[M32] - m[M31] * m[M22] * m[M03] -
	m[M32] * m[M23] * m[M01] - m[M33] * m[M21] * m[M02];
	inv[M11] = m[M00] * m[M22] * m[M33] + m[M02] * m[M23] * m[M30] +
	m[M03] * m[M20] * m[M32] - m[M30] * m[M22] * m[M03] -
	m[M32] * m[M23] * m[M00] - m[M33] * m[M20] * m[M02];
	inv[M12] = m[M00] * m[M21] * m[M33] + m[M01] * m[M23] * m[M30] +
	m[M03] * m[M20] * m[M31] - m[M30] * m[M21] * m[M03] -
	m[M31] * m[M23] * m[M00] - m[M33] * m[M20] * m[M01];
	inv[M13] = m[M00] * m[M21] * m[M32] + m[M01] * m[M22] * m[M30] +
	m[M02] * m[M20] * m[M31] - m[M30] * m[M21] * m[M02] -
	m[M31] * m[M22] * m[M00] - m[M32] * m[M20] * m[M01];
}

void			inverse_matrix(t_matrix_4 out, const t_matrix_4 m)
{
	t_matrix_4	inv;
	double		determinant;

	inverse_matrix_part_1_2(inv, m);
	inverse_matrix_part_3_4(inv, m);
	determinant = m[M00] * inv[M00] - m[M01] * inv[M01] +
	m[M02] * inv[M02] - m[M03] * inv[M03];
	if (determinant == 0.0f)
		return ;
	out[M00] = inv[M00] / determinant;
	out[M01] = -inv[M10] / determinant;
	out[M02] = inv[M20] / determinant;
	out[M03] = -inv[M30] / determinant;
	out[M10] = -inv[M01] / determinant;
	out[M11] = inv[M11] / determinant;
	out[M12] = -inv[M21] / determinant;
	out[M13] = inv[M31] / determinant;
	out[M20] = inv[M02] / determinant;
	out[M21] = -inv[M12] / determinant;
	out[M22] = inv[M22] / determinant;
	out[M23] = -inv[M32] / determinant;
	out[M30] = -inv[M03] / determinant;
	out[M31] = inv[M13] / determinant;
	out[M32] = -inv[M23] / determinant;
	out[M33] = inv[M33] / determinant;
}
