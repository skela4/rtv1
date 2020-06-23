/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:51:41 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/05 17:58:07 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

inline double	*translation(t_matrix_4 out, double x, double y, double z)
{
	out[0] = 1.0f;
	out[1] = 0.0f;
	out[2] = 0.0f;
	out[3] = x;
	out[4] = 0.0f;
	out[5] = 1.0f;
	out[6] = 0.0f;
	out[7] = y;
	out[8] = 0.0f;
	out[9] = 0.0f;
	out[10] = 1.0f;
	out[11] = z;
	out[12] = 0.0f;
	out[13] = 0.0f;
	out[14] = 0.0f;
	out[15] = 1.0f;
	return (out);
}
