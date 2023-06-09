/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khboutah <khboutah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:52:42 by khboutah          #+#    #+#             */
/*   Updated: 2023/03/17 04:48:33 by khboutah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_get_c_pid = 0;

int	ft_power(int n)
{
	int	num;

	if (n == 0)
		return (1);
	if (n == 1)
		return (2);
	num = 2;
	while (n > 1)
	{
		num *= 2;
		n--;
	}
	return (num);
}

char	conv_to_char(char *bits)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (bits[i])
	{
		if (bits[i] == '1')
			num += ft_power(8 - i);
		i++;
	}
	return (num);
}

void	handle_signal2(int *num, int *global)
{
	if (*global == 8)
	{
		if (*num == 0)
			ft_putstr_fd("\n", 1);
		else
			ft_putchar_fd((char)(*num), 1);
		*global = 0;
		*num = 0;
	}
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int	num;
	static int	global;

	context = 0;
	if (g_get_c_pid != info->si_pid)
	{
		g_get_c_pid = info->si_pid;
		global = 0;
		num = 0;
	}
	if (signal == SIGUSR1)
		global++;
	else if (signal == SIGUSR2)
	{
		num += ft_power(7 - global);
		global++;
	}
	handle_signal2(&num, &global);
}

int	main(int ac, char **av)
{
	struct sigaction	act;

	(void)**av;
	if (ac == 1)
	{
		act.sa_sigaction = handle_signal;
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		ft_putstr_fd("PID: ", 1);
		ft_putnbr_fd(getpid(), 1);
		ft_putstr_fd("\n\n", 1);
		while (1)
			pause();
	}
	else
	{
		ft_putstr_fd("server: unexpected error.\n", 1);
		exit(EXIT_FAILURE);
	}	
	return (0);
}
