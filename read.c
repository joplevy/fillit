/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:50:49 by jplevy            #+#    #+#             */
/*   Updated: 2016/03/03 14:21:32 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coord		ft_max_tet(t_coord *tet)
{
	t_coord	max;
	int		cpt;

	max.x = 0;
	max.y = 0;
	cpt = -1;
	while (++cpt < 4)
	{
		max.x = ((max.x > tet[cpt].x) ? max.x : tet[cpt].x);
		max.y = ((max.y > tet[cpt].y) ? max.y : tet[cpt].y);
	}
	return (max);
}

int			ft_create_tet(t_coord *tet)
{
	t_coord	*tmp;
	int		mx;
	int		my;
	int		cpt;

	tmp = tet;
	cpt = -1;
	my = 3;
	mx = 3;
	while (++cpt < 4)
	{
		mx = ((mx < tet[cpt].x) ? mx : tet[cpt].x);
		my = ((my < tet[cpt].y) ? my : tet[cpt].y);
	}
	cpt = -1;
	while (++cpt < 4)
	{
		tmp[cpt].x -= mx;
		tmp[cpt].y -= my;
	}
	return (((ft_max_tet(tmp).x + ft_max_tet(tmp).y > 3) || \
				(ft_test_tet(tmp) == -1)) ? -1 : 0);
}

int			ft_fill_tet(t_coord **tet, char *str)
{
	int		x;
	int		y;
	int		cpt;

	cpt = 0;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if ((*str == '#' && cpt > 3) || (*str != '.' && *str != '#'))
				return (-1);
			if (*str == '#')
			{
				(*tet)[cpt].x = x;
				(*tet)[cpt++].y = y;
			}
			str++;
		}
		if (*str != '\n')
			return (-1);
		str++;
	}
	return ((cpt != 4) ? -1 : 0);
}

int			ft_get_tetrimino(char *str, char id)
{
	t_coord	*tet;
	int		i;

	i = -1;
	while (++i < 20)
		if (((i + 1) % 5 == 0 && str[i] != '\n') || ((i + 1) % 5 != 0 \
					&& str[i] != '.' && str[i] != '#'))
			return (-1);
	if (id > 'Z' || id < 'A')
		return (-1);
	if ((tet = (t_coord*)malloc(sizeof(t_coord) * 4)) == NULL)
		return (-1);
	if (ft_fill_tet(&tet, str) == -1)
		return (-1);
	if (ft_create_tet(tet) != -1)
	{
		ft_list_push_back(&g_tetriminos, tet, ft_max_tet(tet), id);
		i = -1;
		while (++i < 20)
			str[i] = '\0';
		return (0);
	}
	return (-1);
}

int			ft_read(char *input)
{
	char	*buff;
	int		fd;
	int		i;
	char	id;

	id = 'A';
	buff = (char*)malloc(sizeof(char) * 21);
	fd = open(input, O_RDONLY);
	if (errno != 0)
		return (-1);
	while (((i = read(fd, buff, 21)) != 20))
	{
		if (i == 0 || ft_get_tetrimino(buff, id++) == -1)
			return (-1);
	}
	i = read(fd, buff, 20);
	if (ft_get_tetrimino(buff, id) == -1)
		return (-1);
	return (0);
}
