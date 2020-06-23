/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_tuple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:35:57 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/05 17:48:07 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

inline	void		div_tsc(t_tuple out, const t_tuple t, double n)
{
	t_tuple			div;

	n = 1.0f / n;
	div[X] = t[X] * n;
	div[Y] = t[Y] * n;
	div[Z] = t[Z] * n;
	div[W] = t[W] * n;
	out[X] = div[X];
	out[Y] = div[Y];
	out[Z] = div[Z];
	out[W] = div[W];
}
