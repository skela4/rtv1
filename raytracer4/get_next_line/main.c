/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:57:27 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/08 16:03:41 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

enum
{
	camera = 1,
	light = 2,
	sphere = 3,
	plane = 4,
	cone = 5,
	cylindr = 6
};

int		is_object_exist(char *object)
{
	if ( ft_strncmp(object, "camera", 5) == 0)
		return (1);
	else if ( ft_strcmp(object, "light") == 0)
		return (2);
	else if ( ft_strcmp(object, "sphere") == 0)
		return (3);
	// else if ( ft_strcmp(object, "plane"))
	// 	return (4);
	// else if ( ft_strcmp(object, "cone"))
	// 	return (5);
	// else if ( ft_strcmp(object, "cylinder"))
	// 	return (6);
	return (0);
}

void			put_in_array(double *array, char **string)
{
	array[0] = (double)ft_atoi(*string);
	*string = ft_strchr(*string, ',') + 1;
	array[1] = (double)ft_atoi(*string);
	*string = ft_strchr(*string, ',') + 1;
	array[2] = (double)ft_atoi(*string);
	*string = ft_strchr(*string, ']') + 1;
}

void			find_info(double *position, char *line)
{
	char		*array;
	char		*bracket;

	if (!(bracket = ft_strchr(line, '[')))
		return ;
	array = line + (bracket - line);
	while (ft_isspace(*array))
		++array;
	if (*array == '[')
	{
		++array;
		put_in_array(position, &array);
		printf("%f, %f, %f \n", position[0], position[1], position[2]);
		if (*array != 0)
			printf("error\n");
	}
}

void			create_light(int fd, char *line)
{
	char		*array;
	double		position[4];
	double		intensity[3];

	while (get_next_line(fd, &line))
	{
		if ( ft_strstr(line, "position:"))
		{
			find_info(position, line);
			position[3] = 1.0f;
		}
		else if ( ft_strstr(line, "intensity:"))
			find_info(intensity, line);
		else
		{
			break ;
			printf("%s\n", line);
		}
		free(line);
		line = NULL;
	}
}

void			create_camera(int fd, char *line)
{
	char		*array;
	double		from[4];
	double		to[4];


	while (get_next_line(fd, &line) > 0)
	{
		if ( ft_strstr(line, "from:"))
		{
			find_info(from, line);
			from[3] = 1.0f;
		}
		else if ( ft_strstr(line, "to:"))
		{
			find_info(to, line);
			to[3] = 1.0f;
		}
		else
		{
			printf("%s\n", line);
			return ;
		}
		free(line);
		line = NULL;
	}
}

int		main(int argc, char **argv)
{
	char	*line;
	int		ret;
	int		fd;

	char	*option;
	char	*object;
	int		object_type = 0;

	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		if ( (option = ft_strnstr(line, "-add:", 5)) )
		{
			object = option + 5;
			while (*object == ' ')
				object++;
			if ((object_type = is_object_exist(object)) == 0)
				ft_putendl("error object does not exist\n", 2);
			else
			{
				if (object_type == 1)
				{
					free(line);
					line = NULL;
					create_camera(fd, line);
				}
				if (object_type == 2)
				{
					free(line);
					line = NULL;
					create_light(fd, line);
				}
			}
		}
		if (line)
		{
			free(line);
			line = NULL;
		}
	}
	return (0);
}

// void	__attribute__((destructor)) lala(void)
// {
// 	while (1)
// 	;
// }
