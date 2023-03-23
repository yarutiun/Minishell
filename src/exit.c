/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:33:14 by dsas              #+#    #+#             */
/*   Updated: 2023/03/23 21:13:27 by yarutiun         ###   ########.fr       */
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

int	b_exit(char **av)
{
	// int	ac;
	int	exit_status;

	// ac = get_str_arr_len(av);
	exit_status = 1;
	// if (ac > 2)
	// {
	// 	ft_putstr_fd("exit\nminishell: exit: too many arguments\n", 2);
	// 	return (1);
	// }
	// else if (ac == 1)
		// exit_status = 0;
	// exit_status = exit_error(1, av, exit_status);
	// if (exit_status)
		// exit_status = ft_atoi(av[1]);
	// free_strarr(g_env);
	// free_data_in_loop(data);
	// clear_history();
	exit(exit_status % 256);
	return (0);
}
