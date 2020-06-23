/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 18:24:29 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/08 16:19:49 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				default_camera(t_tuple from, t_tuple to)
{
	vector(from, 0, 0, -WIDTH);
	vector(to, 0, 0, 0);
}

void				default_light(t_tuple position, t_color_d intensity)
{
	point(position, -WIDTH, WIDTH, -WIDTH);
	color(intensity, 1, 1, 1);
}

void				default_transformation(t_tuple translate, double *rotate)
{
	vector(translate, 0, 0, 0);
	*rotate = 0;
}

t_material			material(void)
{
	return ((t_material)
	{
		.color[R] = 1.0f,
		.color[G] = 1.0f,
		.color[B] = 1.0f,
		.ambient = 0.1f,
		.diffuse = 0.9f,
		.specular = 0.9f,
		.shininess = 200.0f,
	});
}

/*
** mul_mm(obj->transformation, obj->transformation, transformation);
*/

void				set_transform(t_object *obj, t_matrix_4 transformation)
{
	(void)transformation;
	inverse_matrix(obj->inverse_transformation, obj->transformation);
	transpose(obj->transpose_inverse_transformation,
	obj->inverse_transformation);
}
