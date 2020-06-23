/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:27:23 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/08 16:19:21 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_object				*cylinder(void)
{
	static int	id = 1;
	t_object	*obj;

	if (!(obj = malloc(sizeof(*obj))))
		return (NULL);
	obj->id = id++;
	obj->type = E_CYLINDER;
	identity_matrix(obj->transformation);
	identity_matrix(obj->inverse_transformation);
	identity_matrix(obj->transpose_inverse_transformation);
	obj->material = material();
	return (obj);
}

void					intersect_cylinder(t_intersections *xs, t_object *obj,
t_ray *r)
{
	t_ray				r2;
	double				quad[4];

	r2 = transform(r, obj->inverse_transformation);
	g_ro = r2.origin;
	g_rd = r2.direction;
	quad[a] = g_rd[X] * g_rd[X] + g_rd[Z] * g_rd[Z];
	if (equal(quad[a], 0.0))
		return ;
	quad[b] = g_ro[X] * g_rd[X] + g_ro[Z] * g_rd[Z];
	quad[c] = g_ro[X] * g_ro[X] + g_ro[Z] * g_ro[Z] - 1;
	quad[d] = quad[b] * quad[b] - quad[a] * quad[c];
	if (quad[d] < 0.0f)
		return ;
	quad[d] = sqrt(quad[d]);
	insert((t_intersection){(-quad[b] - quad[d]) / quad[a], obj}, xs);
	insert((t_intersection){(-quad[b] + quad[d]) / quad[a], obj}, xs);
}

void					normal_cylinder(t_tuple world_normal, t_object *s,
t_tuple world_point)
{
	t_tuple		object_normal;

	mul_mt(object_normal, s->inverse_transformation, world_point);
	object_normal[W] = 0.0f;
	object_normal[Y] = 0.0f;
	mul_mt(world_normal,
	s->transpose_inverse_transformation, object_normal);
	world_normal[W] = 0.0f;
	normalize(world_normal);
}
