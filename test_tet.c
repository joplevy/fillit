/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:03:12 by jplevy            #+#    #+#             */
/*   Updated: 2016/03/03 14:39:16 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_get_nb_touch(t_coord *lst, t_coord i, int c)
{
	int		cont;

	cont = 0;
	while (c < 4)
	{
		if ((i.x == lst[c].x && (i.y - lst[c].y == -1 || i.y - lst[c].y == 1))\
		|| (i.y == lst[c].y && (i.x - lst[c].x == -1 || i.x - lst[c].x == 1)))
			cont++;
		c++;
	}
	return (cont);
}

int		ft_test_tet(t_coord *tet)
{
	int		c;
	int		cpt;

	c = 0;
	cpt = 0;
	while (c < 4)
	{
		cpt += ft_get_nb_touch(tet, tet[c], c);
		c++;
	}
	return ((cpt >= 3) ? 0 : -1);
}
