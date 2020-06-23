/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:52:30 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/06 19:33:12 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

double			*rotation_x(t_matrix_4 out, double deg)
{
	double			radian;
	double			cos_r;
	double			sin_r;

	radian = deg * M_PI / 180.0f;
	cos_r = cos(radian);
	sin_r = sin(radian);
	out[0] = 1.0f;
	out[1] = 0.0f;
	out[2] = 0.0f;
	out[3] = 0.0f;
	out[4] = 0.0f;
	out[5] = cos_r;
	out[6] = -sin_r;
	out[7] = 0.0f;
	out[8] = 0.0f;
	out[9] = sin_r;
	out[10] = cos_r;
	out[11] = 0.0f;
	out[12] = 0.0f;
	out[13] = 0.0f;
	out[14] = 0.0f;
	out[15] = 1.0f;
	return (out);
}
