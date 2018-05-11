/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pastlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:16:26 by vomelchu          #+#    #+#             */
/*   Updated: 2018/05/08 11:17:19 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		cpdt(t_figur *current, char **str, char **split, char sym)
{
	int ind;
	int q;
	int count;
	int len;

	ind = 0;
	q = 0;
	count = ft_numrow(split, (sym - 'A') * 4);
	len = (ft_strlen(str[sym - 'A']) - (count - 1)) / count;
	current->next->letter = sym;
	current->next->col = len;
	current->next->row = count;
	while (q < count)
	{
		current->next->type[q] = (char*)malloc(sizeof(char) * (len + 1));
		current->next->type[q] = ft_strsub(str[sym - 'A'], ind, len);
		ind += len + 1;
		q++;
	}
}

void		fpast(t_figur *current, char **str, char **split, char sym)
{
	int ind;
	int q;
	int count;
	int len;

	ind = 0;
	q = 0;
	count = ft_numrow(split, (sym - 'A') * 4);
	len = (ft_strlen(str[sym - 'A']) - (count - 1)) / count;
	current->col = len;
	current->row = count;
	current->letter = sym;
	while (q < count)
	{
		current->type[q] = (char*)malloc(sizeof(char) * (len + 1));
		current->type[q] = ft_strsub(str[sym - 'A'], ind, len);
		ind += len + 1;
		q++;
	}
}

void		add_ls(t_figur *current, char **str, char **split, char sym)
{
	int len;
	int count;
	int ind;

	ind = 0;
	count = ft_numrow(split, (sym - 'A') * 4);
	len = (ft_strlen(str[sym - 'A']) - (count - 1)) / count;
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_figur));
	current->next->type = (char**)malloc(sizeof(char*) * (count + 1));
	current->next->type[count] = 0;
	cpdt(current, str, split, sym);
	current->next->next = NULL;
}

t_figur		*first_list(char **str, char **split, char sym)
{
	t_figur *current;
	t_figur *head;
	int		len;
	int		count;

	count = ft_numrow(split, (sym - 'A') * 4);
	len = (ft_strlen(str[sym - 'A']) - (count - 1)) / count;
	if (!(current = malloc(sizeof(t_figur))) ||
		!(current->type = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	current->type[count] = 0;
	head = current;
	fpast(current, str, split, sym);
	current->next = NULL;
	return (head);
}
