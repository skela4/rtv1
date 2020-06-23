/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 15:31:19 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/08 16:23:04 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_object		*plane(void)
{
	static int	id = 1;
	t_object	*obj;

	if (!(obj = malloc(sizeof(*obj))))
		return (NULL);
	obj->id = id++;
	obj->type = E_PLANE;
	identity_matrix(obj->transformation);
	identity_matrix(obj->inverse_transformation);
	identity_matrix(obj->transpose_inverse_transformation);
	obj->material = material();
	return (obj);
}

void			intersect_plane(t_intersections *xs, t_object *obj, t_ray *r)
{
	t_ray		r2;

	r2 = transform(r, obj->inverse_transformation);
	g_ro = r2.origin;
	if (fabs(g_ro[Y]) < EPSILON)
		return ;
	insert((t_intersection){-g_ro[Y] / r2.direction[Y], obj}, xs);
}

void			normal_plane(t_tuple world_normal, t_object *obj,
t_tuple world_point)
{
	(void)obj;
	(void)world_point;
	vector(world_normal, 0, 1, 0);
}
