/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khboutah <khboutah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 03:52:54 by khboutah          #+#    #+#             */
/*   Updated: 2023/03/17 21:20:46 by khboutah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(char *c)
{
	int	i;

	i = -1;
	while (c[++i])
	{
		if (c[i] < '0' || c[i] > '9')
			return (1);
	}
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	check_pid(char *av)
{
	int	i;

	i = -1;
	while (av[++i])
	{
		if (ft_isdigit(av))
		{
			write(2, "ERROR !!", 9);
			exit (1);
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	out;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		out = (nb % 10) + '0';
	}
	else
	{
		out = (nb % 10) + '0';
	}
	write(fd, &out, 1);
}
