/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:37:05 by jplevy            #+#    #+#             */
/*   Updated: 2016/03/03 09:52:19 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

t_tets	*ft_create_elem(t_coord *data, t_coord max, char id)
{
	t_tets	*el;

	if ((el = (t_tets*)malloc(sizeof(t_tets))))
	{
		el->tetrimino = data;
		el->next = NULL;
		el->height = max.y + 1;
		el->width = max.x + 1;
		el->id = id;
	}
	return (el);
}

void	ft_list_push_back(t_tets **begin_list, t_coord *data, t_coord max, \
char id)
{
	t_tets *list;

	list = *begin_list;
	if (!(list))
		*begin_list = ft_create_elem(data, max, id);
	else
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(data, max, id);
	}
}

void	ft_print_square(int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_putchar(g_square[i][j]);
		ft_putchar('\n');
	}
}

int		main(int ac, char **av)
{
	if (ac != 2)
		write(1, "usage :fillit input_file\n", 25);
	else
	{
		if (ft_read(av[1]) == -1)
		{
			write(1, "error\n", 6);
			return (0);
		}
		else
			ft_resolution();
	}
	return (0);
}
