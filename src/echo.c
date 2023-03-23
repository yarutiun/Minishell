/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:38:17 by dsas              #+#    #+#             */
/*   Updated: 2023/03/23 21:13:52 by yarutiun         ###   ########.fr       */
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
	if (!args[1])
	{
		ft_putstr_fd("\n", 1);
		return (0);
	}
	if (args[1][0] == '-' && args[1][1] == 'n' && !args[1][2] && !args[2])
		return (0);
	if (i > 1)
		n = 1;
	while (args[i])
	{
		echo_putstr_fd(args[i], 1);
		i++;
		if (args[i])
			write(1, " ", 1);
	}
	if (!n)
		ft_putstr_fd("\n", 1);
	return (0);
}
