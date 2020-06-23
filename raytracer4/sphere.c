/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 01:37:09 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/08 16:23:37 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_object		*sphere(void)
{
	static int	id = 1;
	t_object	*obj;

	if (!(obj = malloc(sizeof(*obj))))
		return (NULL);
	obj->id = id++;
	obj->type = E_SHPERE;
	identity_matrix(obj->transformation);
	identity_matrix(obj->inverse_transformation);
	identity_matrix(obj->transpose_inverse_transformation);
	obj->material = material();
	color(obj->material.color, 1, 0, 0.3);
	return (obj);
}

void			intersect_sphere(t_intersections *xs, t_object *obj,
t_ray *r)
{
	t_tuple		sphere_to_ray;
	t_ray		r2;
	double		quad[4];

	r2 = transform(r, obj->inverse_transformation);
	g_ro = r2.origin;
	g_rd = r2.direction;
	vector(sphere_to_ray, g_ro[X], g_ro[Y], g_ro[Z]);
	quad[a] = dot(g_rd, g_rd);
	quad[b] = dot(g_rd, sphere_to_ray);
	quad[c] = dot(sphere_to_ray, sphere_to_ray) - 1;
	quad[d] = quad[b] * quad[b] - quad[a] * quad[c];
	if (quad[d] < 0.0f)
		return ;
	quad[d] = sqrt(quad[d]);
	insert((t_intersection){(-quad[b] - quad[d]) / quad[a], obj}, xs);
	insert((t_intersection){(-quad[b] + quad[d]) / quad[a], obj}, xs);
}

void			normal_sphere(t_tuple world_normal, t_object *s,
t_tuple world_point)
{
	t_tuple		object_normal;

	mul_mt(object_normal, s->inverse_transformation, world_point);
	object_normal[W] = 0.0f;
	mul_mt(world_normal, s->transpose_inverse_transformation, object_normal);
	world_normal[W] = 0.0f;
	normalize(world_normal);
}
