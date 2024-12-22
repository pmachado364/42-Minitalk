/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:17:40 by pmachado          #+#    #+#             */
/*   Updated: 2024/06/04 11:17:40 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_specifiers(char c, va_list args)
{
	int	result;

	result = 0;
	if (!c)
		return (0);
	else if (c == 'c')
		result += ft_putchar(va_arg(args, int));
	else if (c == 's')
		result += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		result += ft_print_ptr(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		result += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		result += ft_utoa(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		result += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		result += write(1, "%", 1);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed_chars;

	i = 0;
	printed_chars = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			printed_chars += ft_specifiers(format[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}
