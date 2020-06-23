/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:39:08 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/05 17:50:10 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

inline	void	add_cc(t_color_d out, const t_color_d a, const t_color_d b)
{
	t_color_d	add;

	add[R] = a[R] + b[R];
	add[G] = a[G] + b[G];
	add[B] = a[B] + b[B];
	out[R] = add[R];
	out[G] = add[G];
	out[B] = add[B];
}
