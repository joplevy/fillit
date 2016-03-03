/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:43:57 by jplevy            #+#    #+#             */
/*   Updated: 2016/03/03 09:47:41 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_collide(t_coord pos, t_tets *tet, int size)
{
	int		i;

	if (pos.y + tet->height > size)
		return (3);
	if (pos.x + tet->width > size)
		return (2);
	i = -1;
	while (++i < 4)
		if (g_square[pos.y + (tet->tetrimino[i]).y]\
				[pos.x + (tet->tetrimino[i]).x] != '.')
			return (1);
	return (0);
}

void		ft_initiate_square(int size, int alloc)
{
	int		i;
	int		j;

	if (alloc == 1)
	{
		i = -1;
		while (++i < size)
			ft_memdel(g_square[i]);
		ft_memdel(g_square);
	}
	if (alloc > 0)
	{
		g_square = (char**)malloc(sizeof(char*) * size + 1);
		i = -1;
		while (++i < size)
			g_square[i] = (char*)malloc(sizeof(char) * size + 1);
		i = -1;
		while (++i < size)
		{
			j = -1;
			while (++j < size)
				g_square[i][j] = '.';
			g_square[i][j] = '\0';
		}
	}
}

t_coord		ft_place_tet(t_coord pos, t_tets *tet, int size)
{
	int		collision;
	int		cpt;

	while ((collision = ft_collide(pos, tet, size)) != 0)
	{
		if (collision == 3)
		{
			pos.y = -1;
			return (pos);
		}
		if (collision == 2)
		{
			pos.x = 0;
			pos.y += 1;
		}
		if (collision == 1)
			pos.x += 1;
	}
	cpt = -1;
	while (++cpt < 4)
	{
		g_square[pos.y + (tet->tetrimino[cpt]).y]\
			[pos.x + (tet->tetrimino[cpt]).x] = tet->id;
	}
	return (pos);
}

void		ft_resolution(void)
{
	int		size;

	size = ft_tab_size();
	ft_initiate_square(size, 2);
	while (ft_resolve(g_tetriminos, size) == 0)
	{
		size++;
		ft_initiate_square(size, 1);
	}
	ft_print_square(size);
	ft_initiate_square(size, 0);
}

int			ft_resolve(t_tets *tetriminos, int size)
{
	t_coord	pos;

	if (tetriminos != NULL)
	{
		pos.x = 0;
		pos.y = 0;
		while ((pos = ft_place_tet(pos, tetriminos, size)).y != -1)
		{
			if (ft_resolve(tetriminos->next, size) != 1)
			{
				ft_erase_tet(tetriminos->id, size);
				pos.x += 1;
			}
			else
				return (1);
		}
		return (0);
	}
	return (1);
}
