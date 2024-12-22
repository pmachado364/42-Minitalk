/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:27:11 by pmachado          #+#    #+#             */
/*   Updated: 2024/04/29 15:27:11 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	i;

	i = (unsigned char)c;
	while (*s != '\0')
	{
		if ((unsigned char)*s == i)
		{
			return ((char *)s);
		}
		s++;
	}
	if (i == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
