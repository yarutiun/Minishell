/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:33:14 by dsas              #+#    #+#             */
/*   Updated: 2023/04/03 10:29:50 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	exit_error(int ac, char **av, int exit_status)
{
	int	i;

	i = 0;
	while (ac == 2 && av[1][i])
	{
		if (!ft_isdigit(av[1][i]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(av[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit_status = 0;
			break ;
		}
		i++;
	}
	return (exit_status);
}

int	get_str_arr_len(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	b_exit(char **av)
{
	int	ac;
	int	exit_status;

	ac = get_str_arr_len(av);
	exit_status = 1;
	if (ac > 2)
	{
		ft_putstr_fd("exit\nminishell: exit: too many arguments\n", 2);
		return (1);
	}
	else if (ac == 1)
		exit_status = 0;
	else if (av[1])
	{
		if (!(ft_isdigit(av[1][0])))
		{
			ft_putstr_fd("exit\nminishell: argument is not a numebr\n", 2);
			return (1);
		}
		exit_status = ft_atoi(av[1]);
	}
	free_shell_h();
	exit(exit_status % 256);
	return (0);
}
