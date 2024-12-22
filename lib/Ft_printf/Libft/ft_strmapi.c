/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:00:11 by pmachado          #+#    #+#             */
/*   Updated: 2024/05/07 16:00:11 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		i;

	i = 0;
	if (NULL == s)
		return (NULL);
	ptr = malloc(ft_strlen(s) + 1);
	if (NULL == ptr)
		return (NULL);
	if (NULL == f)
	{
		ft_strlcpy(ptr, s, ft_strlen(s) + 1);
		return (ptr);
	}
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}
