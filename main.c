/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 16:07:08 by vomelchu          #+#    #+#             */
/*   Updated: 2018/05/06 18:03:30 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_array(char **str)
{
	int q;

	q = 0;
	while (str[q])
	{
		free(str[q]);
		q++;
	}
	free(str[q]);
	free(str);
}

int		main(int argc, char **argv)
{
	char	**split;
	char	**line;
	t_figur *head;
	char	symbol;

	symbol = 'A';
	if (argc == 2)
	{
		split = fileopen(argv[1]);
		if (checksizemap(split) && checksize(split) && checksymbol(split)
			&& checkcountsymb(split) && rightfigure(split))
		{
			line = cutfigure(split);
			changeline(line);
			head = first_list(line, split, 'A');
			while (++symbol <= ret_sumbol(line))
				add_ls(head, line, split, symbol);
			free_array(split);
			free_array(line);
			solve(head);
		}
	}
	else
		write(1, "usage: fillit input_file\n", 25);
	return (0);
}
