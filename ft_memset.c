/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhromads <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:01:39 by dhromads          #+#    #+#             */
/*   Updated: 2018/03/30 18:38:59 by dhromads         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*t;

	if (len < 1)
		return (b);
	i = 0;
	t = (unsigned char *)b;
	while (len--)
		t[i++] = c;
	return (b);
}
