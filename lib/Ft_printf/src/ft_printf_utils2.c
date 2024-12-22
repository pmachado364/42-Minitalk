/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:51:45 by pedro             #+#    #+#             */
/*   Updated: 2024/07/17 20:58:30 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../Libft/libft.h"

unsigned int	ft_nbr_len(unsigned int nbr)
{
	unsigned int	count;

	count = 0;
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

int	ft_utoa(unsigned int nbr)
{
	char	*newstr;
	int		size;
	int		result;

	size = ft_nbr_len(nbr);
	newstr = (char *)malloc(sizeof(char) * (1 + size));
	if (!newstr)
		return (0);
	newstr[size] = '\0';
	if (nbr == 0)
		newstr[0] = '0';
	while (nbr != 0)
	{
		size--;
		newstr[size] = (nbr % 10) + 48;
		nbr /= 10;
	}
	result = ft_putstr(newstr);
	free(newstr);
	return (result);
}

int	ft_putnbr(int nbr)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(nbr);
	len = ft_putstr(num);
	free(num);
	return (len);
}
