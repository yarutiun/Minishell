/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:38:17 by dsas              #+#    #+#             */
/*   Updated: 2023/03/24 19:15:58 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void	echo_putstr_fd(char *arg, int fd)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '\\')
			i++;
		write(fd, &arg[i], 1);
		i++;
	}
}

int	b_echo(char **args)
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	if (!args[1])
	{
		ft_putstr_fd("\n", 1);
		return (0);
	}
	if (args[1][0] == '-' && args[1][1] == 'n' && !args[1][2])
	{
		i = 2;
		n = 1;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		i++;
		if (args[i])
			write(1, " ", 1);
	}
	if (!n)
		ft_putstr_fd("\n", 1);
	return (0);
}
