/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:36:23 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/08 16:20:17 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				terminate(char *s, char **line, int ret)
{
	ft_putendl_fd(s, 2);
	ft_strdel(line);
	return (ret);
}

int				is_object_exist(char *object)
{
	object = object + 5;
	while (*object == ' ')
		object++;
	if (ft_strncmp(object, "camera", 6) == 0 && !*(object + 6))
		return (E_CAMERA);
	else if (ft_strncmp(object, "light", 5) == 0 && !*(object + 5))
		return (E_LIGHT);
	else if (ft_strncmp(object, "sphere", 6) == 0 && !*(object + 6))
		return (E_SHPERE);
	else if (ft_strncmp(object, "cylinder", 8) == 0 && !*(object + 8))
		return (E_CYLINDER);
	return (0);
}

int				read_file(int fd, t_camera *c, t_world *w)
{
	int			ret;
	char		*h_line;
	char		*t_line;
	int			object_type;
	int			read;

	h_line = NULL;
	object_type = 0;
	read = 0;
	while ((ret = get_next_line(fd, &h_line)) > 0)
	{
		read = 1;
		if (!(t_line = ft_strnstr(h_line, "-add:", 5)))
			return (terminate("wrong option", &h_line, 0));
		if (!(object_type = is_object_exist(t_line)))
			return (terminate("object does not exist", &h_line, 0));
		if (!create_object(object_type, fd, c, w))
			return (terminate("wrong format", &h_line, 0));
		ft_strdel(&h_line);
	}
	(!read) ? terminate("Error file is empty", &h_line, 0) : 0;
	return (1);
}
