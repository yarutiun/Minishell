/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:37:38 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/16 18:53:02 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

/* create echo function without arguments */
int	builtin_echo_with_no_args(char **args)
{
	if (args[1] == NULL)
		printf("\n");
	return (0);
}

/* create echo function with -n argument */
int	builtin_echo_with_flag_n(t_minishell *ms_data)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	if (ms_data->args[1][0] == '-')
	{
		i++;
		if (ms_data->args[1][1] == 'n')
			n_flag = 1;
	}
	printf("n_flag: %d\n", n_flag);
	return (0);
}
