/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 00:09:39 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/05/30 19:09:56 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray				ray(t_tuple origin, t_tuple direction)
{
	return ((t_ray)
	{
		.origin[X] = origin[X],
		.origin[Y] = origin[Y],
		.origin[Z] = origin[Z],
		.origin[W] = origin[W],
		.direction[X] = direction[X],
		.direction[Y] = direction[Y],
		.direction[Z] = direction[Z],
		.direction[W] = direction[W]
	});
}

void				position(t_tuple out, t_ray *r, double t)
{
	g_ro = r->origin;
	g_rd = r->direction;
	out[X] = g_ro[X] + g_rd[X] * t;
	out[Y] = g_ro[Y] + g_rd[Y] * t;
	out[Z] = g_ro[Z] + g_rd[Z] * t;
	out[W] = g_ro[W] + g_rd[W] * t;
}

t_ray				transform(t_ray *r, t_matrix_4 transformation)
{
	t_ray			new_r;

	mul_mt(new_r.origin, transformation, r->origin);
	mul_mt(new_r.direction, transformation, r->direction);
	return (new_r);
}
