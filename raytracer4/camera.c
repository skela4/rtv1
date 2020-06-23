/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 03:09:43 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/08 16:09:41 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray				ray_for_pixel(t_camera cam, int x, int y)
{
	double			world_x;
	double			world_y;
	t_tuple			pixel;
	t_tuple			origin;
	t_tuple			direction;

	world_x = cam.half_width - (((double)x + 0.5f) * cam.pixel_size);
	world_y = cam.half_height - (((double)y + 0.5f) * cam.pixel_size);
	mul_mt(pixel, cam.inv_transform, (double[]){world_x, world_y, -1, 1});
	mul_mt(origin, cam.inv_transform, (double[]){0, 0, 0, 1});
	sub_tt(direction, pixel, origin);
	direction[W] = 0;
	normalize(direction);
	return (ray(origin, direction));
}

void				view_transformation(t_camera *cam,
t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple			forward;
	t_tuple			left;
	t_matrix_4		orientation;
	t_matrix_4		translate;

	sub_tt(forward, to, from);
	normalize(forward);
	normalize(up);
	cross(left, forward, up);
	cross(up, left, forward);
	identity_matrix(orientation);
	orientation[0] = left[X];
	orientation[1] = left[Y];
	orientation[2] = left[Z];
	orientation[4] = up[X];
	orientation[5] = up[Y];
	orientation[6] = up[Z];
	orientation[8] = -forward[X];
	orientation[9] = -forward[Y];
	orientation[10] = -forward[Z];
	translation(translate, -from[X], -from[Y], -from[Z]);
	mul_mm(cam->transform, orientation, translate);
	inverse_matrix(cam->inv_transform, cam->transform);
}

t_camera			camera(void)
{
	t_camera		c;
	double			aspect;
	double			half_view;

	c.hsize = (double)WIDTH;
	c.vsize = (double)HEIGHT;
	c.field_of_view = (180 / 3) * M_PI / 180.0f;
	identity_matrix(c.transform);
	identity_matrix(c.inv_transform);
	half_view = tan(c.field_of_view / 2);
	aspect = c.hsize / c.vsize;
	if (aspect >= 1.0f)
	{
		c.half_width = half_view;
		c.half_height = half_view / aspect;
	}
	else
	{
		c.half_width = half_view * aspect;
		c.half_height = half_view;
	}
	c.pixel_size = (c.half_width * 2) / c.hsize;
	c.pxs2 = c.pixel_size * 2;
	return (c);
}
