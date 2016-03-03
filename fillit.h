/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:31:48 by jplevy            #+#    #+#             */
/*   Updated: 2016/03/03 09:40:07 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_tets
{
	char			id;
	int				height;
	int				width;
	struct s_tets	*next;
	t_coord			*tetrimino;
}					t_tets;

extern char			**g_square;
extern t_tets		*g_tetriminos;

t_tets				*ft_create_elem(t_coord *data, t_coord max, char id);
void				ft_list_push_back(t_tets **begin_list, t_coord *data, \
		t_coord max, char id);
int					ft_strlen(char *str);
void				ft_resolution(void);
int					ft_get_tetrimino(char *str, char id);
int					ft_read(char *input);
t_coord				ft_max_tet(t_coord *tet);
int					ft_create_tet(t_coord *tet);
int					ft_fill_tet(t_coord **tet, char *str);
int					ft_list_size(t_tets *begin_list);
int					ft_tab_size(void);
int					ft_resolve(t_tets *tetrimino, int size);
int					ft_collide(t_coord pos, t_tets *tet, int size);
void				ft_initiate_square(int size, int alloc);
t_coord				ft_place_tet(t_coord pos, t_tets *tet, int size);
void				ft_print_square(int size);
void				ft_putchar(char c);
void				ft_memdel(void *mem);
void				ft_erase_tet(char id, int size);
#endif
