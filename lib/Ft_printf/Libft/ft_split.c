/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:37:03 by pmachado          #+#    #+#             */
/*   Updated: 2024/05/07 02:37:03 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count( char const *s, char c)
{
	size_t	count;
	int		flag;

	count = 0;
	while (*s)
	{
		flag = 0;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!flag)
			{
				++count;
				flag = 1;
			}
			++s;
		}
	}
	return (count);
}

static char	*ft_extract_word(char const *str, char c)
{
	const char	*end;
	size_t		length;
	char		*word;

	end = str;
	while (*end && *end != c)
		end++;
	length = end - str;
	word = (char *)malloc(length + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, length + 1);
	return (word);
}

static char	**ft_free(char **split, int i)
{
	while (i--)
		free(split[i]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**dest;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	dest = (char **)malloc(sizeof(char *) * (ft_word_count(str, c) + 1));
	if (!dest)
		return (NULL);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			dest[i++] = ft_extract_word(str, c);
			if (dest[i - 1] == NULL)
				return (ft_free(dest, i));
			while (*str && *str != c)
				str++;
		}
	}
	dest[i] = NULL;
	return (dest);
}
