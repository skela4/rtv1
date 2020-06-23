/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:28:10 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/08 16:22:43 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		find_info(double *info, char *line)
{
	char		*array;
	char		*bracket;

	if (!(bracket = ft_strchr(line, '[')))
		return (0);
	array = line + (bracket - line);
	if (*array == '[')
	{
		++array;
		info[0] = (double)ft_atoi(array);
		if (!(array = ft_strchr(array, ',')))
			return (0);
		++array;
		info[1] = (double)ft_atoi(array);
		if (!(array = ft_strchr(array, ',')))
			return (0);
		++array;
		info[2] = (double)ft_atoi(array);
		if (!(bracket = ft_strchr(array, ']')))
			return (0);
		++bracket;
		if (*bracket != 0)
			return (0);
	}
	return (1);
}

int				get_camera_info(int fd, t_tuple from, t_tuple to, double pxs)
{
	char		*line;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strnstr(line, "from:", 5))
		{
			if (!find_info(from, line))
				return (terminate("", &line, 0));
			vector(from, from[0] * pxs, from[1] * pxs, from[2] * pxs);
		}
		else if (ft_strnstr(line, "to:", 3))
		{
			if (!find_info(to, line))
				return (terminate("", &line, 0));
			vector(to, to[0] * pxs, to[1] * pxs, to[2] * pxs);
		}
		else if (*line == '\0')
			return (terminate("", &line, 1));
		else
			return (terminate("", &line, 0));
		ft_strdel(&line);
	}
	return (1);
}

int				get_light_info(int fd, t_tuple pos, t_tuple inten,
double pxs)
{
	char		*line;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strnstr(line, "position:", 8))
		{
			if (!(find_info(position, line)))
				return (terminate("", &line, 0));
			vector(position, pos[0] * pxs, pos[1] * pxs, pos[2] * pxs);
		}
		else if (ft_strnstr(line, "intensity:", 11))
		{
			if (!(find_info(inten, line)))
				return (terminate("", &line, 0));
			color(inten, inten[0] / 255, inten[1] / 255, inten[2] / 255);
		}
		else if (*line == '\0')
			return (terminate("", &line, 1));
		else
			return (terminate("", &line, 0));
		ft_strdel(&line);
	}
	return (1);
}

int				get_shape_info(int fd, t_matrix_4 obj_transformation,
double pxs)
{
	char		*line;
	t_tuple		translate;
	t_matrix_4	transformation;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strnstr(line, "translate:", 10))
		{
			if (!find_info(translate, line))
				return (terminate("", &line, 0));
			mul_mm(obj_transformation,
			obj_transformation,
			translation(transformation,
			translate[0] * pxs, translate[1] * pxs, translate[2] * pxs));
		}
		else if (*line == '\0')
			return (terminate("", &line, 1));
		else
			return (terminate("", &line, 0));
		ft_strdel(&line);
	}
	return (1);
}
