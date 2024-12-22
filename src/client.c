/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:02:49 by pmachado          #+#    #+#             */
/*   Updated: 2024/08/27 10:16:04 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	ft_client_sig_handler(int sig, siginfo_t *info, void *context);
static void	ft_send_signal(int pid, char *str);
static void	ft_send_char_signal(int pid, char c);

int	g_signal_reception = 0;

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa_client;

	if (argc != 3)
	{
		ft_printf("Wrong format. Use: ./client <PID> <String>\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID: %s\n", argv[1]);
		return (1);
	}
	sa_client.sa_flags = SA_SIGINFO;
	sa_client.sa_sigaction = ft_client_sig_handler;
	sigemptyset(&sa_client.sa_mask);
	if (sigaction(SIGUSR1, &sa_client, NULL) == -1)
		exit(1);
	ft_send_signal(pid, argv[2]);
	while (!g_signal_reception)
		pause();
	return (0);
}

static void	ft_client_sig_handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGUSR1)
		g_signal_reception = 1;
}

static void	ft_send_signal(int pid, char *str)
{
	while (*str)
	{
		ft_send_char_signal(pid, *str);
		str++;
	}
	ft_send_char_signal(pid, '\0');
}

static void	ft_send_char_signal(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_signal_reception = 0;
		if (c >> bit & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		bit--;
		while (!g_signal_reception)
			pause();
	}
}
