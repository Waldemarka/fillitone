/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhromads <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:01:50 by dhromads          #+#    #+#             */
/*   Updated: 2018/04/16 15:02:51 by dhromads         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(*str) * size + 1);
	if (str == (NULL))
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}
