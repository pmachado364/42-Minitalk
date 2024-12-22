/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:26:24 by pmachado          #+#    #+#             */
/*   Updated: 2024/04/29 15:26:24 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		ch;

	p = (const unsigned char *)s;
	ch = (unsigned char)c;
	while (n-- > 0)
	{
		if (*p == ch)
		{
			return ((void *)p);
		}
		p++;
	}
	return (0);
}
