/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:28:29 by pmachado          #+#    #+#             */
/*   Updated: 2024/04/29 15:28:29 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[h] != 0 && h < len)
	{
		n = 0;
		while (haystack[h + n] == needle[n] && needle[n] && (h + n) < len)
		{
			n++;
		}
		if (n == ft_strlen(needle))
			return ((char *)&haystack[h]);
		h++;
	}
	return (0);
}
