/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_matrix_16_equal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:42:42 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/04/03 23:42:51 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

inline	int		is_matrix_16_equal(t_matrix_16 a, t_matrix_16 b)
{
	int			i;
	int			is_equal;

	i = 0;
	is_equal = 0;
	while (i < SIZE_M16)
	{
		is_equal += fabs((a[i] - b[i]));
		++i;
	}
	return (is_equal < EPSILON);
}
