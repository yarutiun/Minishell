/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:53:08 by dsas              #+#    #+#             */
/*   Updated: 2023/03/24 19:53:29 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	b_export(char **args)
{
	int	i;

	if (!args[1])
	{
		print_export();
		return (1);
	}
	i = 0;
	if (check_keyword(args[1]) || !args[2])
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(args[i], 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	set_new(ft_strjoin(args[1], args[2]));
	return (0);
}
