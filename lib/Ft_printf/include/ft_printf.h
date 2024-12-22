/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:06:38 by pmachado          #+#    #+#             */
/*   Updated: 2024/06/05 11:06:38 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
FT_PRINTF/
├── include/
│	└── ft_printf.h
├── Libft/
│	├── ft_*.c
│	└── Makefile
├── src/
│	├── ft_printf.c
│	├── ft_printf_utils.c
│	├── ft_printf_utils2.c
│	└── main.c
└── Makefile
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../Libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_specifiers(char c, va_list args);

int	ft_putchar(int c);
int	ft_print_ptr(unsigned long nbr);
int	ft_putnbr(int nbr);
int	ft_print_hex(unsigned long nbr, const char c);
int	ft_putstr(char *str);
int	ft_utoa(unsigned int nbr);

#endif