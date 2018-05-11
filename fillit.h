/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 16:48:52 by vomelchu          #+#    #+#             */
/*   Updated: 2018/05/09 20:35:01 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_figur
{
	char			letter;
	int				row;
	int				col;
	char			**type;
	struct s_figur	*next;
}					t_figur;

typedef struct		s_map
{
	int				size;
	char			**field;
}					t_map;

void				ft_error(void);
int					ft_colum(char **str, int first);
int					ft_row(char **str, int first);
int					forsquare(char **str, int first);
int					rightfigure(char **str);
char				**ft_strsplit(char const *s, char c);
char				**cutfigure(char **str);
char				**fileopen(char *str);
int					checksize(char **str);
int					checksizemap(char **str);
int					checksymbol(char **str);
int					checkcountsymb(char **str);
size_t				ft_strlen(const char *str);
int					checkmulti(char *str);
int					sizearray(char **str);
int					ft_numrow(char **split, int index);
int					ft_numcol(char **split, int index);
char				*oneline(char **split, int first, int numcol, int numrow);
char				**cutfigure(char **split);
int					ft_colindex(char **split, int index);
int					ft_rowindex(char **split, int index);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				changeline(char **str);
char				ret_sumbol(char **str);
void				add_ls(t_figur *head, char **str, char **split, char sym);
t_figur				*first_list(char **str, char **split, char sym);
void				cpdt(t_figur *current, char **str, char **split, char sym);
void				fpast(t_figur *current, char **str, char **split, char sym);
int					ft_conect(char **str, int second, int first, int count);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strnew(size_t size);
void				ft_putendl(char const *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
t_map				*new_map(int size);
void				print_map(t_map *map);
int					get_min_squre(t_figur *list);
int					wall_col_check(t_map *map, t_figur *tetr, int x, int y);
int					collision_check (t_map *map, t_figur *tetr, int x, int y);
int					col_check(t_map *map, t_figur *tetri, int x, int y);
int					fseter(t_map *map, t_figur *tetr, int x, int y);
int					fclener (t_map *map, t_figur *tetr, int x, int y);
int					map_solver(t_map *map, t_figur *list);
void				solve(t_figur *list);

#endif
