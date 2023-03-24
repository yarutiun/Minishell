/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:26:23 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/24 19:16:21 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	ft_env(void)
{
	int	i;

	i = 0;
	while (i < shell_h->current_env)
	{
		if (shell_h->envp[i] == NULL)
		{
			i++;
			continue ;
		}
		printf("%s\n", shell_h->envp[i]);
		i++;
	}
	return (0);
}
