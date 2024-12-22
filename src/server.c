/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:32:22 by pmachado          #+#    #+#             */
/*   Updated: 2024/08/27 10:16:03 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	ft_server_sig_handler(int sig, siginfo_t *info, void *context);
static void	ft_append_char(char **str, int *len, char c);
static void	ft_print_str(char **str, int *len);

int	main(void)
{
	struct sigaction	sa_server;

	sa_server.sa_flags = SA_SIGINFO;
	sa_server.sa_sigaction = ft_server_sig_handler;
	sigemptyset(&sa_server.sa_mask);
	if (sigaction(SIGUSR1, &sa_server, NULL) == -1
		|| sigaction(SIGUSR2, &sa_server, NULL) == -1)
		exit(1);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}

static void	ft_server_sig_handler(int sig, siginfo_t *info, void *context)
{
	static char		*message = NULL;
	static int		len = 0;
	static char		c;
	static int		bit_count;

	(void)context;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		c = (c << 1) | (sig == SIGUSR2);
		bit_count++;
		if (bit_count == 8)
		{
			ft_append_char(&message, &len, c);
			if (c == '\0')
			{
				ft_print_str(&message, &len);
			}
			c = 0;
			bit_count = 0;
		}
		kill(info->si_pid, SIGUSR1);
	}
}

static void	ft_append_char(char **str, int *len, char c)
{
	char	*new_str;
	int		new_len;

	new_len = *len + 1;
	new_str = malloc(new_len + 1);
	if (!new_str)
		exit(1);
	if (*str)
	{
		ft_memcpy(new_str, *str, *len);
		free(*str);
	}
	new_str[*len] = c;
	new_str[new_len] = '\0';
	*str = new_str;
	*len = new_len;
}

static void	ft_print_str(char **str, int *len)
{
	if (*str)
	{
		ft_printf("%s\n", *str);
		free(*str);
		*str = NULL;
		*len = 0;
	}
}
