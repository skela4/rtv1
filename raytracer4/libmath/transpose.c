/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:49:04 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/05 17:53:30 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

static	void	assign(t_matrix_4 out, const t_matrix_4 m)
{
	out[0] = m[0];
	out[1] = m[1];
	out[2] = m[2];
	out[3] = m[3];
	out[4] = m[4];
	out[5] = m[5];
	out[6] = m[6];
	out[7] = m[7];
	out[8] = m[8];
	out[9] = m[9];
	out[10] = m[10];
	out[11] = m[11];
	out[12] = m[12];
	out[13] = m[13];
	out[14] = m[14];
	out[15] = m[15];
}

inline	void	transpose(t_matrix_4 out, const t_matrix_4 m)
{
	t_matrix_4	transposed;

	transposed[0] = m[0];
	transposed[1] = m[4];
	transposed[2] = m[8];
	transposed[3] = m[12];
	transposed[4] = m[1];
	transposed[5] = m[5];
	transposed[6] = m[9];
	transposed[7] = m[13];
	transposed[8] = m[2];
	transposed[9] = m[6];
	transposed[10] = m[10];
	transposed[11] = m[14];
	transposed[12] = m[3];
	transposed[13] = m[7];
	transposed[14] = m[11];
	transposed[15] = m[15];
	assign(out, transposed);
}
