/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:56:07 by dsas              #+#    #+#             */
/*   Updated: 2023/03/24 19:56:19 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	count_words(char *str)
{
	int	num_words;

	num_words = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		++num_words;
		if (*str == '\'' || *str == '\"' || *str == ' ')
		{
			++str;
			continue ;
		}
		while (*str != '\0' && *str != ' ' && *str != '\"'
			&& *str != '\t' && *str != '\n' && *str != '\'')
			++str;
	}
	return (num_words);
}

char	**ft_split_minishell(char *str)
{
	int		num_words;
	char	**array;

	num_words = count_words(str);
	array = malloc(sizeof(char *) * (num_words + 1));
	array[num_words] = 0;
	fill_words(array, str);
	return (array);
}

int	ft_lstsize_mod(t_token *lst)
{
	int		counter;
	t_token	*current_node;

	current_node = NULL;
	current_node = lst;
	counter = 0;
	while (current_node != NULL)
	{
		counter ++;
		current_node = current_node->next;
	}
	return (counter);
}

void	put_lvl(void)
{
	int		i;
	int		lvl;
	char	*last;
	char	**uns;

	uns = malloc(sizeof(char *) * 2);
	uns[1] = NULL;
	i = find_path_env(shell_h->envp, "SHLVL=");
	last = ft_strchr(shell_h->envp[i], '=') + 1;
	lvl = ft_atoi(last);
	uns[0] = ft_strdup("SHLVL");
	b_unset(uns);
	last = ft_strjoin("SHLVL=", ft_itoa(lvl + 1));
	set_new(last);
	free(uns[0]);
	free(uns);
}
