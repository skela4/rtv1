/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tuple_equal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:42:18 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/04/03 23:42:27 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

inline	int		is_tuple_equal(t_tuple a, t_tuple b)
{
	return (fabs(a[X] - b[X])
	+ fabs(a[Y] - b[Y])
	+ fabs(a[Z] - b[Z])
	< EPSILON);
}
