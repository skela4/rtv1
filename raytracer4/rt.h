/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 13:42:17 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/14 18:21:33 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "minilibx_macos/mlx.h"
# include "libmath/libmath.h"
# include "get_next_line/libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800

double			*g_ro;
double			*g_rd;

typedef enum	e_quadratic_index
{
	a = 0,
	b = 1,
	c = 2,
	d = 3
}				t_quadratic_index;

typedef struct	s_ray
{
	t_tuple		origin;
	t_tuple		direction;
}				t_ray;

typedef struct	s_light
{
	t_tuple		position;
	t_color_d	intensity;
}				t_light;

typedef struct	s_material
{
	t_color_d	color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}				t_material;

typedef enum				e_type
{
	E_CAMERA = 1,
	E_LIGHT = 2,
	E_SHPERE = 3,
	E_PLANE = 4,
	E_CYLINDER = 5,
	E_CONE = 6,
	E_COUNT
}							t_type;

typedef struct				s_parse
{
	double					pxs2;
	int						fd;
	char					*file;
	int						parsing;
	int						wrong_format;
	int						look_for_object;
	int						look_for_option;
	char					*prev_line;
	char					*current_line;
}							t_parse;

typedef struct				s_linked_list
{
	int						type;
	size_t					data_size;
	void					*data;
	struct s_linked_list	*next;
}							t_linked_list;

// pixel size == 0.115470
// world x == -0.057735 world y == -0.057735

typedef	struct				s_object
{
	int						id;
	t_type					type;
	t_matrix_4				transformation;
	t_matrix_4				inverse_transformation;
	t_matrix_4				transpose_inverse_transformation;
	t_material				material;
}							t_object;

typedef struct				s_intersection
{
	double					t;
	t_object				*object;
}							t_intersection;

typedef struct				s_intersections
{
	int						count;
	t_intersection			*intersection;
}							t_intersections;

typedef struct				s_world
{
	int						n_objects;
	int						n_lights;
	t_object				**objects;
	t_light					*lights;
}							t_world;

typedef struct				s_camera
{
	t_tuple					from;
	t_tuple					to;
	double					hsize;
	double					vsize;
	double					field_of_view;
	double					half_width;
	double					half_height;
	double					pixel_size;
	double					pxs2;
	double					half_pixel_size;
	t_matrix_4				transform;
	t_matrix_4				inv_transform;
}							t_camera;

typedef struct				s_computation
{
	int						inside;
	int						shadow;
	double					t;
	t_object				*obj;
	t_tuple					point;
	t_tuple					eyev;
	t_tuple					normalv;
	t_tuple					over_point;
}							t_computation;

typedef struct				s_light_computation
{
	double					factor;
	t_tuple					lightv;
	t_tuple					reflectv;
	double					light_dot_normal;
	double					reflect_dot_eye;
}							t_light_computation;

typedef struct	s_img
{
	int			bpp;
	int			size_l;
	int			endian;
	int			*data_p;
	void		*img_p;
}				t_img;

typedef struct	s_mlx
{
	t_img		img;
	void		*win_p;
	void		*mlx_p;
}				t_mlx;

/*
** ray
*/

t_ray				ray(t_tuple origin, t_tuple direction);

void				position(t_tuple out, t_ray *r, double t);

t_ray				transform(t_ray *r, t_matrix_4 transformation);

/*
** object
*/

void				default_camera(t_tuple from, t_tuple to);

void				default_light(t_tuple position, t_color_d intensity);

void				default_transformation(t_tuple translate, double *rotate);

t_material			material(void);

void				set_transform(t_object *s, t_matrix_4 transformation);


/*
** sphere
*/

t_object			*sphere(void);

// void					intersect_sphere(t_lst_intersect **xs, t_object *s, t_ray r);
void				intersect_sphere(t_intersections *xs, t_object *obj, t_ray *r);

void				normal_sphere(t_tuple normal, t_object *s, t_tuple world_point);


/*
** plane
*/

t_object			*plane(void);

void				intersect_plane(t_intersections *xs, t_object *obj, t_ray *r);

void				normal_plane(t_tuple world_normal, t_object *obj, t_tuple world_point);


/*
** cylinder
*/

t_object			*cylinder(void);

void				intersect_cylinder(t_intersections *xs, t_object *obj, t_ray *r);

void				normal_cylinder(t_tuple world_normal, t_object *s, t_tuple world_point);

/*
** cone
*/

t_object			*cone(void);

void				intersect_cone(t_intersections *xs, t_object *obj, t_ray *r);

void				normal_cone(t_tuple world_normal, t_object *s, t_tuple world_point);

/*
** intersection
*/

void				insert(t_intersection inter, t_intersections *xs);

int					hit(t_intersection *arr, int size);

/*
** reflection
*/

void				reflect(t_tuple reflected_vec, t_tuple in_vec, t_tuple normal);

/*
** light
*/

t_light				point_light(t_tuple position, t_color_d intensity);

void				lighting(t_color_d clr, t_material obj_mat, t_computation *comp, t_light light);

int					is_shadowed(t_world *w, t_tuple point);

void				shade_hit(t_color_d clr, t_world *w, t_computation *comp);


/*
** world
*/

t_world				world(void);

t_intersections		intersect_world(t_world *w, t_ray *r);

void				color_at(t_color_d clr, t_world *w, t_ray *r);

void				destroy_shapes(t_object ***shapes, int size);

void				destroy_world(t_world *w);

/*
** computations
*/

t_computation		prepare_computations(t_intersection i, t_ray *r);


/*
** camera
*/

t_camera			camera(void);

void				view_transformation(t_camera *cam, t_tuple from, t_tuple to, t_tuple up);

t_ray				ray_for_pixel(t_camera cam, int x, int y);


/*
** create_camera
*/

int					create_camera(int fd, t_camera *c);

int					create_light(int fd, t_world *w);

void				add_shape(t_world *w, t_object **obj);

int					create_shape(int fd, t_world *w, int type);

int					create_object(int type, int fd, t_camera *c, t_world *w);

/*
** parse_file
*/


/*
** parse_infos
*/


typedef t_object	*(*t_object_pf)(void);
typedef t_object	*(*t_create_object_pf)(int fd, char *line);

static t_object_pf	g_object[] = {
	[1] = &sphere,
	[2] = &plane,
	[3] = &cylinder,
	[4] = &cone,
};

#endif
