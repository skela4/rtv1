/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 03:15:02 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/08 16:11:55 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int					hit(t_intersection *arr, int size)
{
	int				i;

	i = 0;
	while (i < size)
	{
		if (arr[i].t >= 0.0f)
			return (i);
		++i;
	}
	return (-1);
}

void				insert(t_intersection inter, t_intersections *xs)
{
	int				i;

	i = xs->count - 1;
	while (i >= 0 && xs->intersection[i].t > inter.t)
	{
		xs->intersection[i + 1] = xs->intersection[i];
		--i;
	}
	xs->intersection[i + 1] = inter;
	++xs->count;
}
