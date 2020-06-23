/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:27:50 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/06 19:32:58 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H

# include <math.h>
# include <stdio.h>

# define EPSILON 0.00001
# define SIZE_M16 16

typedef int		t_color_i[3];
typedef double	t_color_d[3];
typedef double	t_tuple[4];
typedef double	t_matrix_4[16];

typedef enum	e_tuple_type
{
	VECTOR = 0,
	POINT = 1
}				t_tuple_type;

typedef enum	e_tuple_index
{
	X = 0,
	Y = 1,
	Z = 2,
	W = 3
}				t_tuple_index;

typedef enum	e_color_index
{
	R = 0,
	G = 1,
	B = 2,
}				t_color_index;

typedef enum	e_matrix_4_index
{
	M00, M01, M02, M03,
	M10, M11, M12, M13,
	M20, M21, M22, M23,
	M30, M31, M32, M33
}				t_matrix_4_index;

/*
** math_helper
*/

int				equal(const double a, const double b);

/*
** int				is_tuple_equal(t_tuple a, t_tuple b);
*/

/*
** double			deg_to_rad(double deg);
*/

/*
** double			rad_to_deg(double rad);
*/

/*
** double			clampd(double x, double min, double max);
*/

/*
** tuple
*/

void			display_tuple(const t_tuple t);

/*
** void			assign_tuple(t_tuple a, const t_tuple b);
*/

double			*point(t_tuple p, double x, double y, double z);

double			*vector(t_tuple v, double x, double y, double z);

/*
** tuple_operations
*/

void			add_tt(t_tuple out, const t_tuple a, const t_tuple b);

void			sub_tt(t_tuple out, const t_tuple a, const t_tuple b);

void			negate_t(t_tuple out, t_tuple a);

void			mul_tsc(t_tuple out, const t_tuple t, const double n);

void			div_tsc(t_tuple out, const t_tuple t, double n);

double			magnitude(t_tuple v);

void			normalize(t_tuple v);

double			dot(const t_tuple a, const t_tuple b);

void			cross(t_tuple out, const t_tuple a, const t_tuple b);

/*
** color
*/

void			color(t_color_d c, double r, double g, double b);

/*
** color_operations
*/

void			add_cc(t_color_d out, const t_color_d a, const t_color_d b);

void			sub_cc(t_color_d out, const t_color_d a, const t_color_d b);

void			mul_csc(t_color_d out, const t_color_d a, double n);

void			mul_cc(t_color_d out, const t_color_d a, const t_color_d b);

/*
** matrix
*/

void			display_matrix_4(const t_matrix_4 m);

void			zero_matrix(t_matrix_4 m);

void			identity_matrix(t_matrix_4 m);

/*
** matrix_operations
*/

void			mul_mm(t_matrix_4 out, const t_matrix_4 a, const t_matrix_4 b);

void			mul_mt(t_tuple out, const t_matrix_4 m, const t_tuple t);

void			transpose(t_matrix_4 out, const t_matrix_4 m);

void			inverse_matrix(t_matrix_4 r, const t_matrix_4 m);

/*
** matrix_transformation
*/

double			*translation(t_matrix_4 out, double x, double y, double z);

void			scaling(t_matrix_4 out, double x, double y, double z);

double			*rotation_x(t_matrix_4 out, double deg);

double			*rotation_y(t_matrix_4 out, double deg);

double			*rotation_z(t_matrix_4 out, double deg);

#endif
