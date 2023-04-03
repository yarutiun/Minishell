/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:56:07 by dsas              #+#    #+#             */
/*   Updated: 2023/04/03 10:45:52 by yarutiun         ###   ########.fr       */
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
	char	*num;

	i = find_path_env(g_shell_h->envp, "SHLVL=");
	last = ft_strchr(g_shell_h->envp[i], '=') + 1;
	lvl = ft_atoi(last);
	num = ft_itoa(lvl + 1);
	last = ft_strjoin("SHLVL=", num);
	set_new(last);
	free(num);
}

int	main_split(char **splited, char *readed)
{
	add_history(readed);
	if ((init_list(&(g_shell_h->head), readed, splited) == 1))
	{
		free_readed_and_splited(readed, splited);
		return (1);
	}
	ft_lexer();
	g_shell_h->pipes = redirection(&(g_shell_h->head));
	if (g_shell_h->pipes == NULL)
	{
		free_readed_and_splited(readed, splited);
		return (1);
	}
	return (0);
}
