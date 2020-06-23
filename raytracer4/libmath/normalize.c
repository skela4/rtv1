/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:37:06 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/05 17:48:46 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

inline	void		normalize(t_tuple v)
{
	double			length;

	length = sqrt(v[X] * v[X] + v[Y] * v[Y] + v[Z] * v[Z] + v[W] * v[W]);
	if (length != 0.0f)
	{
		length = 1.0f / length;
		v[X] = v[X] * length;
		v[Y] = v[Y] * length;
		v[Z] = v[Z] * length;
		v[W] = v[W] * length;
	}
}
