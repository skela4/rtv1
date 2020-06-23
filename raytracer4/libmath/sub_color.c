/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:39:46 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/05 17:51:44 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

inline	void		sub_cc(t_color_d out, const t_color_d a, const t_color_d b)
{
	t_color_d		sub;

	sub[R] = a[R] - b[R];
	sub[G] = a[G] - b[G];
	sub[B] = a[B] - b[B];
	out[R] = sub[R];
	out[G] = sub[G];
	out[B] = sub[B];
}
