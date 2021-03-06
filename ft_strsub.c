/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:38:01 by vomelchu          #+#    #+#             */
/*   Updated: 2018/05/07 16:38:09 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		q;
	int		i;

	q = 0;
	i = len;
	if (s == NULL)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (s[start] != '\0' && i != 0)
	{
		str[q] = s[start];
		i--;
		q++;
		start++;
	}
	str[q] = '\0';
	return (str);
}
