/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:49:52 by nrenz             #+#    #+#             */
/*   Updated: 2023/03/24 19:07:24 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

//basically strlen but whitespaces also counts as a breakpoint
int	ft_wordlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\"' && str[i] != '\'')
		++i;
	return (i);
}

//duplicates words
char	*word_dupe(char *str)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = ft_wordlen(str);
	word = malloc(sizeof(char) * (len + 1));
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

char	*quotes_dupe(char *str)
{
	char *word;

	word = malloc(2);
	if (*str == '\"')
		word[0] = '\"';
	else
		word[0] = '\'';
	word[1] = '\0';
	return (word);
}

void	fill_words(char **array, char *str)
{
	int	word_index;

	word_index = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		if (*str == '\'' || *str == '\"')
		{
			array[word_index] = quotes_dupe(str);
			str++;
			word_index++;
			continue;
		}
		if (*str == ' ')
		{
			array[word_index] = malloc(2);
			array[word_index][0] = ' ';
			array[word_index][1] = '\0';
			str++;
			word_index++;
			continue;
		}
		array[word_index] = word_dupe(str);
		++word_index;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n' && *str != '\'' && *str != '\"')
			++str;
	}
}

//counts amount of words
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
			continue;
		}
		while (*str != '\0' && *str != ' ' && *str != '\"' && *str != '\t' && *str != '\n' && *str != '\'')
			++str;
	}
	return (num_words);
}

//split BUT it splits for lexer including the whitespaces and quotes info as tokens
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

//shows the list size
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
	int	i;
	int lvl;
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
