/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_tuple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:34:15 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/06/05 17:46:23 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

inline	void		sub_tt(t_tuple out, const t_tuple a, const t_tuple b)
{
	t_tuple			sub;

	sub[X] = a[X] - b[X];
	sub[Y] = a[Y] - b[Y];
	sub[Z] = a[Z] - b[Z];
	sub[W] = a[W] - b[W];
	out[X] = sub[X];
	out[Y] = sub[Y];
	out[Z] = sub[Z];
	out[W] = sub[W];
}
