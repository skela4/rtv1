/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:09:13 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/08 18:55:37 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

#include "get_next_line/get_next_line.h"
#include "get_next_line/libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

double			clampd(double x, double min, double max)
{
	if (x < min)
		x = min;
	else if (x > max)
		x = max;
	return (x);
}

t_mlx			canvas(void)
{
	t_mlx		mlx;

	mlx.mlx_p = mlx_init();
	mlx.win_p = mlx_new_window(mlx.mlx_p, WIDTH, HEIGHT, "rtv1");
	mlx.img.img_p = mlx_new_image(mlx.mlx_p, WIDTH, HEIGHT);
	mlx.img.data_p = (int*)mlx_get_data_addr(\
	mlx.img.img_p, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
	return (mlx);
}

void			write_pixel(int *canvas, int idx, t_color_d color)
{
	t_color_i	rgb;

	color[R] = clampd(color[R], 0.0f, 1.0f);
	color[G] = clampd(color[G], 0.0f, 1.0f);
	color[B] = clampd(color[B], 0.0f, 1.0f);
	rgb[R] = (int)(color[R] * 255.0f);
	rgb[G] = (int)(color[G] * 255.0f);
	rgb[B] = (int)(color[B] * 255.0f);
	canvas[idx] = (rgb[R] << 16) + (rgb[G] << 8) + rgb[B];
}

void			render(t_camera c, t_world w)
{
	t_mlx		cvs;
	t_ray		r;
	t_color_d	clr;
	int			y;
	int			x;

	y = 0;
	x = 0;
	cvs = canvas();
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			r = ray_for_pixel(c, x, y);
			color_at(clr, &w, &r);
			write_pixel(cvs.img.data_p, y * WIDTH + x, clr);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cvs.mlx_p, cvs.win_p, cvs.img.img_p, 0, 0);
	mlx_loop(cvs.mlx_p);
}

int				main(int argc, char *argv[])
{
	t_world		w;
	t_camera	c;

	if (argc < 2)
		return (0);
	w = world();
	w.n_lights = 1;
	w.lights = malloc(sizeof(*w.lights) * (size_t)w.n_lights);
	argc = open(argv[1], O_RDONLY);
	if (!(read_file(argc, &c, &w)))
	{
		destroy_world(&w);
		return (0);
	}
	render(c, w);
	destroy_world(&w);
	return (0);
}
// nika lenina russian singer
// bottleneck ?

//    2 (464 bytes) ROOT LEAK: 0x7f89c9c0d1c0 [16]
//        1 (448 bytes) 0x7f89c9c0e7b0 [448]

//   2 (464 bytes) ROOT LEAK: 0x7fbc2ed04280 [16]
//        1 (448 bytes) 0x7fbc2ed07ad0 [448]

void	__attribute__((destructor))	lala(void)
{
	while (1)
		;
}