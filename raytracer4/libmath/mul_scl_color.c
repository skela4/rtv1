/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_scl_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:40:35 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/05 17:51:33 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

inline	void		mul_csc(t_color_d out, const t_color_d a, double n)
{
	t_color_d		mul;

	mul[R] = a[R] * n;
	mul[G] = a[G] * n;
	mul[B] = a[B] * n;
	out[R] = mul[R];
	out[G] = mul[G];
	out[B] = mul[B];
}
