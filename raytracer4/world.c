/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 01:00:47 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/08 15:54:17 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_world					world(void)
{
	t_world				w;

	w.n_objects = 0;
	w.n_lights = 0;
	w.objects = NULL;
	w.lights = NULL;
	return (w);
}

t_intersections			intersect_world(t_world *w, t_ray *r)
{
	int					i;
	t_intersections		xs;
	int					n_sphere = 4;
	int					n_sphere_intersection = 2;
	int					total = n_sphere * n_sphere_intersection;

	i = 0;
	xs.count = 0;
	xs.intersection = malloc(sizeof(*(xs.intersection)) * (size_t)total);
	while (i < w->n_objects)
	{
		if (w->objects[i]->type == E_SHPERE)
			intersect_sphere(&xs, w->objects[i], r);
		else if (w->objects[i]->type == E_PLANE)
			intersect_plane(&xs, w->objects[i], r);
		else if (w->objects[i]->type == E_CYLINDER)
			intersect_cylinder(&xs, w->objects[i], r);
		else if (w->objects[i]->type == E_CONE)
			intersect_cone(&xs, w->objects[i], r);

		i++;
	}
	return (xs);
}

void					color_at(t_color_d clr, t_world *w, t_ray *r)
{
	int					index;
	t_intersections		xs;
	t_computation		comp;

	xs = intersect_world(w, r);
	index = hit(xs.intersection, xs.count);
	if (index == -1)
	{
		free(xs.intersection);
		xs.intersection = NULL;
		color(clr, 0, 0, 0);
		return ;
	}
	comp = prepare_computations(xs.intersection[index], r);
	free(xs.intersection);
	xs.intersection = NULL;
	shade_hit(clr, w, &comp);
}

void					destroy_shapes(t_object ***shapes, int size)
{
	int					i;

	i = 0;
	if (shapes && *shapes)
	{
		while (i < size)
		{
			if (*shapes[i])
			{
				free(*shapes[i]);
				*shapes[i] = NULL;
			}
			++i;
		}
		free(*shapes);
		*shapes = NULL;
	}
}

void					destroy_world(t_world *w)
{
	int					i;

	i = 0;
	if (w->n_objects > 0)
	{
		while (i < w->n_objects)
		{
			free(w->objects[i]);
			w->objects[i] = NULL;
			++i;
		}
		free(w->objects);
		w->objects = NULL;
	}
	if (w->n_lights > 0)
	{
		free(w->lights);
		w->lights = NULL;
	}
}
