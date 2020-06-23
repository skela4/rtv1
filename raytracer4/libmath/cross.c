/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:37:50 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/05 17:49:12 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

inline	void		cross(t_tuple out, const t_tuple a, const t_tuple b)
{
	t_tuple			crossed;

	crossed[X] = a[Y] * b[Z] - a[Z] * b[Y];
	crossed[Y] = a[Z] * b[X] - a[X] * b[Z];
	crossed[Z] = a[X] * b[Y] - a[Y] * b[X];
	crossed[W] = VECTOR;
	out[X] = crossed[X];
	out[Y] = crossed[Y];
	out[Z] = crossed[Z];
	out[W] = crossed[W];
}
