/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 22:15:26 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/05 17:14:09 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_light					point_light(t_tuple position, t_color_d intensity)
{
	return ((t_light)
	{
		.position[X] = position[X],
		.position[Y] = position[Y],
		.position[Z] = position[Z],
		.position[W] = position[W],
		.intensity[R] = intensity[R],
		.intensity[G] = intensity[G],
		.intensity[B] = intensity[B]
	});
}

static	void			set_zero(t_color_d diffuse, t_color_d specu)
{
	color(diffuse, 0, 0, 0);
	color(specu, 0, 0, 0);
}

void					lighting(t_color_d clr, t_material obj_mat,
t_computation *comp, t_light light)
{
	t_color_d			eff_color;
	t_color_d			ambient;
	t_color_d			diffuse;
	t_color_d			specu;
	t_light_computation	l_comp;

	mul_cc(eff_color, obj_mat.color, light.intensity);
	sub_tt(l_comp.lightv, light.position, comp->point);
	normalize(l_comp.lightv);
	mul_csc(ambient, eff_color, obj_mat.ambient);
	set_zero(diffuse, specu);
	if ((l_comp.light_dot_normal = dot(l_comp.lightv, comp->normalv)) >= 0.0f
	&& !comp->shadow)
	{
		mul_csc(diffuse, eff_color, obj_mat.diffuse * l_comp.light_dot_normal);
		negate_t(l_comp.lightv, l_comp.lightv);
		reflect(l_comp.reflectv, l_comp.lightv, comp->normalv);
		if ((l_comp.reflect_dot_eye = dot(l_comp.reflectv, comp->eyev)) > 0.0f)
		{
			l_comp.factor = pow(l_comp.reflect_dot_eye, obj_mat.shininess);
			mul_csc(specu, light.intensity, obj_mat.specular * l_comp.factor);
		}
	}
	add_cc(clr, diffuse, specu);
	add_cc(clr, clr, ambient);
}

void					shade_hit(t_color_d clr, t_world *w,
t_computation *comp)
{
	comp->shadow = is_shadowed(w, comp->over_point);
	if (w->n_lights > 0)
		lighting(clr, comp->obj->material, comp, w->lights[0]);
}

int						is_shadowed(t_world *w, t_tuple point)
{
	double				distance;
	t_ray				r;
	t_tuple				point_to_light;
	int					index;
	t_intersections		xs;

	sub_tt(point_to_light, w->lights[0].position, point);
	distance = magnitude(point_to_light);
	normalize(point_to_light);
	r = ray(point, point_to_light);
	xs = intersect_world(w, &r);
	index = hit(xs.intersection, xs.count);
	if (index != -1
	&& (equal(xs.intersection[index].t, distance)
	|| xs.intersection[index].t < distance))
	{
		free(xs.intersection);
		xs.intersection = NULL;
		return (1);
	}
	free(xs.intersection);
	xs.intersection = NULL;
	return (0);
}
