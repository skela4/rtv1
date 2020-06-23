/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 22:12:55 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/08 16:23:11 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			reflect(t_tuple reflected_vec, t_tuple in_vec, t_tuple normal)
{
	double		n;

	n = 2 * dot(in_vec, normal);
	reflected_vec[X] = in_vec[X] - normal[X] * n;
	reflected_vec[Y] = in_vec[Y] - normal[Y] * n;
	reflected_vec[Z] = in_vec[Z] - normal[Z] * n;
	reflected_vec[W] = in_vec[W] - normal[W] * n;
}
