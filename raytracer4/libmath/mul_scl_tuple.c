/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_scl_tuple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:35:21 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/05 18:02:55 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

inline	void		mul_tsc(t_tuple out, const t_tuple t, const double n)
{
	t_tuple			mul;

	mul[X] = t[X] * n;
	mul[Y] = t[Y] * n;
	mul[Z] = t[Z] * n;
	mul[W] = t[W] * n;
	out[X] = mul[X];
	out[Y] = mul[Y];
	out[Z] = mul[Z];
	out[W] = mul[W];
}
