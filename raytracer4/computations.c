/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:25:44 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/08 16:09:52 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_computation				prepare_computations(t_intersection i, t_ray *r)
{
	t_computation			comp;
	t_tuple					result;

	comp.t = i.t;
	comp.obj = i.object;
	comp.inside = 0;
	position(comp.point, r, comp.t);
	negate_t(comp.eyev, r->direction);
	if (comp.obj->type == E_SHPERE)
		normal_sphere(comp.normalv, comp.obj, comp.point);
	else if (comp.obj->type == E_PLANE)
		normal_plane(comp.normalv, comp.obj, comp.point);
	else if (comp.obj->type == E_CYLINDER)
		normal_cylinder(comp.normalv, comp.obj, comp.point);
	else if (comp.obj->type == E_CONE)
		normal_cone(comp.normalv, comp.obj, comp.point);
	if (dot(comp.normalv, comp.eyev) < 0.0f)
	{
		comp.inside = 1;
		negate_t(comp.normalv, comp.normalv);
	}
	mul_tsc(result, comp.normalv, EPSILON);
	add_tt(comp.over_point, comp.point, result);
	return (comp);
}
