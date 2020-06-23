/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:38:26 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/14 18:32:02 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// ◦ open
// ◦ read
// ◦ write
// ◦ close
// ◦ malloc
// ◦ free
// ◦ perror
// ◦ strerror
// ◦ exit

void		assign_double(double *a, double *b)
{
	a[0] = b[0];
	a[1] = b[1];
	a[2] = b[2];
}

void		init_parse_st(t_parse *parse, char *file)
{
	parse->fd = 0;
	parse->file = file;
	parse->parsing = 1;
	parse->wrong_format = 0;
	parse->look_for_object = 1;
	parse->look_for_option = 0;
	parse->prev_line = NULL;
	parse->current_line = NULL;
}

void		display_error_and_quit(const char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	exit(-1);
}

void		skip_space(char **str)
{
	while (**str && ft_isspace(**str))
		(*str)++;
}

int					atoi_modified(char **str)
{
	long	int		sign;
	long	int		nb;

	sign = 1;
	nb = 0;
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
	if (**str == '-' || **str == '+')
		sign = (*((*str)++) == '-') ? -1 : 1;
	while (**str >= '0' && **str <= '9')
		nb = nb * 10 + *((*str)++) - '0';
	return (nb * sign);
}

int			change_str(char **strA, char **strB)
{
	if (!(*strA = ft_strdup(*strB)))
		return (0);
	ft_strdel(&(*strB));
	return (1);
}

void			apply_translation(double *array3, double pxs2, double *option)
{
	t_matrix_4	transformation;

	translation(transformation,
	array3[0] * pxs2, array3[1] * pxs2, array3[2] * pxs2);
	mul_mm(option, option, transformation);
}

void			apply_rotation_x(double *array1, double pxs2, double *option)
{
	// clamp -180 to 180
	t_matrix_4	transformation;

	rotation_x(transformation, array1[0]);
	mul_mm(option, option, transformation);
}

void			apply_rotation_y(double *array1, double pxs2, double *option)
{
	t_matrix_4	transformation;

	rotation_y(transformation, array1[0]);
	mul_mm(option, option, transformation);
}

void			apply_rotation_z(double *array1, double pxs2, double *option)
{
	t_matrix_4	transformation;

	rotation_z(transformation, array1[0]);
	mul_mm(option, option, transformation);
}

void			apply_change(t_parse *parse, double *array1, double *array3, double *option)
{
	if (strcmp(parse->current_line, "  translate: [") == 0)
		apply_translation(array3, parse->pxs2, option);
	else if (strcmp(parse->current_line, "  rotate_x: ") == 0)
		apply_rotation_x(array1, parse->pxs2, option);
	else if (strcmp(parse->current_line, "  rotate_y: ") == 0)
		apply_rotation_y(array1, parse->pxs2, option);
	else if (strcmp(parse->current_line, "  rotate_z: ") == 0)
		apply_rotation_z(array1, parse->pxs2, option);
	else
		assign_double(option, array3);
}

void			parse_array(char *line, t_parse *parse, int array, int *option)
{
	double		array1[1];
	double		array3[3];

	if (array)
	{
		array3[0] = atoi_modified(&line);
		if (*line++ != ',' && !(parse->parsing = 0))
			return ;
		array3[1] = atoi_modified(&line);
		if (*line++ != ',' && !(parse->parsing = 0))
			return ;
		array3[2] = atoi_modified(&line);
		if (*line++ != ']' && !(parse->parsing = 0))
			return ;
		if (*line != '\0')
			parse->parsing = 0;
	}
	else
	{
		array1[0] = atoi_modified(&line);
		if (*line++ != '\0' && !(parse->parsing = 0))
			return ;
	}
	apply_change(parse, array1, array3, option);
}

void		parse_camera_option(t_parse *parse, t_camera *cam)
{
	if (ft_strncmp("  from: [", parse->current_line, 9) == 0)
		parse_array(parse->current_line + 9, parse, 1, cam->from);
	else if (ft_strncmp("  to: [", parse->current_line, 7) == 0)
		parse_array(parse->current_line + 7, parse, 1, cam->to);
	else if (*parse->current_line != '\0')
		parse->parsing = 0;
	else
		parse->look_for_option = 0;
}

void		parse_shape_option(t_parse *parse, t_object *shape)
{
	if (ft_strncmp("  color: [", parse->current_line, 11) == 0)
		parse_array(parse->current_line + 11, parse, 1, shape->material.color);
	else if (ft_strncmp("  translate: [", parse->current_line, 14) == 0)
		parse_array(parse->current_line + 14, parse, 1, shape->transformation);
	else if (ft_strncmp("  rotate_x: ", parse->current_line, 12) == 0)
		parse_array(parse->current_line + 12, parse, 0, shape->transformation);
	else if (ft_strncmp("  rotate_y: ", parse->current_line, 12) == 0)
		parse_array(parse->current_line + 12, parse, 0, shape->transformation);
	else if (ft_strncmp("  rotate_z: ", parse->current_line, 12) == 0)
		parse_array(parse->current_line + 12, parse, 0, shape->transformation);
	else if (*parse->current_line != '\0')
		parse->parsing = 0;
	else
		parse->look_for_option = 0;
}

void		parse_camera(t_parse *parse, t_linked_list **lst)
{
	t_camera	cam;

	if (!change_str(&parse->prev_line, &parse->current_line))
		return ;
	parse->look_for_object = 0;
	parse->look_for_option = 1;
	while (parse->look_for_option && parse->parsing
	&& get_next_line(parse->fd, &parse->current_line) > 0)
	{
		parse_camera_option(parse, &cam);
		ft_strdel(&parse->current_line);
	}
	parse->look_for_object = 1;
	parse->look_for_option = 0;
	append_lst(lst, &cam, sizeof(cam), E_CAMERA);
}

void		parse_sphere(t_parse *parse, t_linked_list **lst)
{
	t_object	shape;

	if (!change_str(&parse->prev_line, &parse->current_line))
		return ;
	parse->look_for_object = 0;
	parse->look_for_option = 1;
	while (parse->look_for_option && parse->parsing
	&& get_next_line(parse->fd, &parse->current_line) > 0)
	{
		parse_shape_option(parse, &shape);
		ft_strdel(&parse->current_line);
	}
	parse->look_for_object = 1;
	parse->look_for_option = 0;
	append_lst(lst, &shape, sizeof(shape), E_SHPERE);
}

void		parse_file(t_parse *parse, t_linked_list **lst)
{
	if ((parse->fd = open(parse->file, O_RDONLY)) == -1)
		display_error_and_quit("Couldn't open the file");
	while (parse->parsing
	&& get_next_line(parse->fd, &parse->current_line) > 0)
	{
		if (parse->look_for_object)
		{
			if (ft_strcmp(parse->current_line, "- type: camera") == 0)
				parse_camera(parse, lst);
			else if (ft_strcmp(parse->current_line, "- type: sphere") == 0)
				parse_sphere(parse, lst);
			else if (*parse->current_line != '\0')
				parse->parsing = 0;
		}
		ft_strdel(&parse->prev_line);
		ft_strdel(&parse->current_line);
	}
}

int			main(int argc, char **argv)
{
	t_camera	c;
	t_parse	parse;
	t_linked_list		*lst;
	t_linked_list		*tmp;

	c = camera();
	lst = NULL;
// 	// append_lst(&lst, &data, sizeof(data), data.type);

	check_file(argc, argv[1]);

	parse.pxs2 = c.pxs2;
	init_parse_st(&parse, argv[1]);
	parse_file(&parse, &lst);
	if (!parse.parsing)
	{
		ft_putstr("wrong format");
		return (0);
	}
	tmp = lst;
	// ft_putchar('\n');
	// int	n = 1;
	// while (tmp)
	// {
	// 	printf("\nobject number %d\n", n++);
	// 	if (tmp->type == E_CAMERA)
	// 	{
	// 		printf("from[0] == %d\n", ((t_camera_info *)(tmp->data))->from[0]);
	// 		printf("from[1] == %d\n", ((t_camera_info *)(tmp->data))->from[1]);
	// 		printf("from[2] == %d\n\n", ((t_camera_info *)(tmp->data))->from[2]);
	// 		printf("to[0] == %d\n", ((t_camera_info *)(tmp->data))->to[0]);
	// 		printf("to[1] == %d\n", ((t_camera_info *)(tmp->data))->to[1]);
	// 		printf("to[2] == %d\n", ((t_camera_info *)(tmp->data))->to[2]);
	// 	}
	// 	else if (tmp->type == E_SHPERE)
	// 	{
	// 		printf("translate[0] == %d\n", ((t_shape_info *)(tmp->data))->translate[0]);
	// 		printf("translate[1] == %d\n", ((t_shape_info *)(tmp->data))->translate[1]);
	// 		printf("translate[2] == %d\n\n", ((t_shape_info *)(tmp->data))->translate[2]);
	// 		printf("rotate == %d\n", ((t_shape_info *)(tmp->data))->rotate);
	// 	}
	// 	tmp = tmp->next;
	// }


	delete_lst(&lst);
	return (0);
}

void	__attribute__((destructor)) lala(void)
{
	while (1)
	;
}
