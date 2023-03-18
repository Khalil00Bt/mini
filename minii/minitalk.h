/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khboutah <khboutah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:56:16 by khboutah          #+#    #+#             */
/*   Updated: 2023/03/17 21:30:12 by khboutah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include    <unistd.h>
# include    <stdio.h>
# include    <signal.h>
# include    <stdlib.h>
# include    <fcntl.h>
# include    <string.h>

void	check_pid(char *av);
int		ft_isdigit(char *c);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

#endif
