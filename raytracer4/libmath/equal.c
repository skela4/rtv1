/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:41:45 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/05/26 17:28:40 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

inline	int			equal(const double a, const double b)
{
	return (fabs(a - b) < EPSILON);
}