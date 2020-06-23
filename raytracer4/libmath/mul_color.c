/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:40:09 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/05 17:51:24 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

inline	void	mul_cc(t_color_d out, const t_color_d a, const t_color_d b)
{
	t_color_d	mul;

	mul[R] = a[R] * b[R];
	mul[G] = a[G] * b[G];
	mul[B] = a[B] * b[B];
	out[R] = mul[R];
	out[G] = mul[G];
	out[B] = mul[B];
}
