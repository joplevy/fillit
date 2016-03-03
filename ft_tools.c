/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:32:01 by jplevy            #+#    #+#             */
/*   Updated: 2016/03/03 09:32:24 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_memdel(void *mem)
{
	if (mem)
		free(mem);
	else
		mem = NULL;
}

int		ft_list_size(t_tets *begin_list)
{
	if (!(begin_list))
		return (0);
	if (!(begin_list->next))
		return (1);
	else
		return (1 + ft_list_size(begin_list->next));
}

int		ft_tab_size(void)
{
	int		tot;
	int		nb;

	tot = ft_list_size(g_tetriminos) * 4;
	nb = 1;
	while ((nb * nb) < tot)
		nb++;
	return (nb);
}

void	ft_erase_tet(char id, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (g_square[i][j] == id)
				g_square[i][j] = '.';
	}
}
