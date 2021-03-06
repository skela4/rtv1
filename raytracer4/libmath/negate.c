/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:34:44 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/05/30 16:29:48 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

inline	void		negate_t(t_tuple out, t_tuple a)
{
	out[X] = -a[X];
	out[Y] = -a[Y];
	out[Z] = -a[Z];
	out[W] = -a[W];
}
