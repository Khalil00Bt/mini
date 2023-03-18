/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khboutah <khboutah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:52:09 by khboutah          #+#    #+#             */
/*   Updated: 2023/03/17 21:17:33 by khboutah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				i;
	int				np;

	np = 1;
	i = 0;
	num = 0;
	while ((str[i] == 8 && str[i] == 13) || str[i] == 32)
			i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(np * num));
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

void	segs_sender(char *bits, pid_t pid)
{
	int	i;

	i = 0;
	while (bits[i])
	{
		if (bits[i] == '0')
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(write(2, "->\tError PID\n", 14));
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(write(2, "->\tError PID\n", 14));
		}
		usleep(880);
		i++;
	}
}

void	conv_to_bits(unsigned char c, pid_t pid)
{
	char			*str;
	unsigned int	i;
	unsigned int	num;

	i = 0;
	num = (unsigned int)c;
	str = ft_strdup("00000000\0");
	if (!str)
		return ;
	while (i < 8)
	{
		if (num % 2 != 0)
			str[7 - i] = '1';
		num /= 2;
		i++;
	}
	segs_sender(str, pid);
	free(str);
}

int	main(int argc, char **argv)
{
	char	*text;
	int		i;
	int		a;
	pid_t	pid;

	if (argc != 3)
		return (write(2, "\e[033;0;31m→  Error: Wrong  Format\e[0m\n", 42));
	pid = ft_atoi(argv[1]);
	a = -1;
	while (argv[1][++a])
	{
		if (ft_isdigit(argv[1]))
			return (write(2, "ERROR !!", 9));
	}
	text = argv[2];
	i = 0;
	if (pid < 0)
		return (write(2, "PID NOT CORRECT !!", 19));
	while (text[i])
	{
		conv_to_bits(text[i], pid);
		i++;
	}
	conv_to_bits(0, pid);
	return (0);
}
