/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:50:41 by pedro             #+#    #+#             */
/*   Updated: 2024/07/17 20:58:28 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (!str)
	{
		result += write(1, "(null)", 6);
		return (result);
	}
	while (str[i])
	{
		result += write(1, &str[i], 1);
		i++;
	}
	return (result);
}

int	ft_print_ptr(unsigned long nbr)
{
	int		result;

	result = 0;
	if (!nbr)
		return (write(1, "(nil)", 5));
	result += ft_putstr("0x");
	result += ft_print_hex(nbr, 'x');
	return (result);
}

int	ft_print_hex(unsigned long nbr, const char c)
{
	char	*base;
	int		result;

	result = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		result += ft_print_hex((nbr / 16), c);
		result += ft_print_hex((nbr % 16), c);
	}
	else
	{
		result += write(1, &base[nbr], 1);
	}
	return (result);
}
