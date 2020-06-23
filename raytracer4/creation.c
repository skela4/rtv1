/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:40:39 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/08 16:10:39 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int					create_camera(int fd, t_camera *c)
{
	char			*line;
	t_tuple			from;
	t_tuple			to;
	t_tuple			up;
	double			pxs;

	line = NULL;
	*c = camera();
	pxs = c->pxs2;
	default_camera(from, to);
	if (!get_camera_info(fd, from, to, pxs))
		return (0);
	view_transformation(c, from, to, vector(up, 0, 1, 0));
	return (1);
}

int					create_light(int fd, t_world *w)
{
	double			pxs;
	char			*line;
	t_tuple			position;
	t_tuple			intensity;
	t_camera		c;

	line = NULL;
	c = camera();
	pxs = c.pxs2;
	default_light(position, intensity);
	if (!get_light_info(fd, position, intensity, pxs))
		return (0);
	w->lights[0] = point_light(position, intensity);
	return (1);
}

void				add_shape(t_world *w, t_object **obj)
{
	int				i;
	t_object		**objects_tmp;

	i = 0;
	objects_tmp = malloc(sizeof(*w->objects) * (size_t)w->n_objects - 1);
	while (i < w->n_objects - 1)
	{
		objects_tmp[i] = g_object[w->objects[i]->type]();
		ft_memcpy(objects_tmp[i], w->objects[i], sizeof(t_object));
		i++;
	}
	destroy_shapes(&w->objects, w->n_objects - 1);
	w->objects = malloc(sizeof(*w->objects) * (size_t)w->n_objects);
	i = 0;
	while (i < w->n_objects - 1)
	{
		w->objects[i] = g_object[objects_tmp[i]->type]();
		ft_memcpy(w->objects[i], objects_tmp[i], sizeof(t_object));
		i++;
	}
	destroy_shapes(&objects_tmp, w->n_objects - 1);
	w->objects[i] = *obj;
}

int					create_shape(int fd, t_world *w, int type)
{
	char			*line;
	t_object		*obj;
	t_camera		c;

	line = NULL;
	c = camera();
	obj = g_object[type]();
	if (!(get_shape_info(fd, obj->transformation, c.pxs2)))
	{
		free(obj);
		obj = NULL;
		return (0);
	}
	w->n_objects += 1;
	set_transform(obj, obj->transformation);
	if (!w->objects)
	{
		w->objects = malloc(sizeof(*w->objects) * (size_t)w->n_objects);
		w->objects[w->n_objects - 1] = obj;
	}
	else
		add_shape(w, &obj);
	return (1);
}

int					create_object(int type, int fd, t_camera *c, t_world *w)
{
	if (type == E_CAMERA)
	{
		if (!(create_camera(fd, c)))
			return (0);
	}
	else if (type == E_LIGHT)
	{
		if (!(create_light(fd, w)))
			return (0);
	}
	else
	{
		if (!(create_shape(fd, w, type)))
			return (0);
	}
	return (1);
}
