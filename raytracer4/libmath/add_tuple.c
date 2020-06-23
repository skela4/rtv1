/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tuple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:33:46 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/05 17:45:39 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

inline	void		add_tt(t_tuple out, const t_tuple a, const t_tuple b)
{
	t_tuple			add;

	add[X] = a[X] + b[X];
	add[Y] = a[Y] + b[Y];
	add[Z] = a[Z] + b[Z];
	add[W] = a[W] + b[W];
	out[X] = add[X];
	out[Y] = add[Y];
	out[Z] = add[Z];
	out[W] = add[W];
}
