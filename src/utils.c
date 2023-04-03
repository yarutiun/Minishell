/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:49:52 by nrenz             #+#    #+#             */
/*   Updated: 2023/04/03 10:27:10 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	ft_wordlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t'
		&& str[i] != '\n' && str[i] != '\"' && str[i] != '\'')
		++i;
	return (i);
}

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
	char	*word;

	word = malloc(2);
	if (*str == '\"')
		word[0] = '\"';
	else
		word[0] = '\'';
	word[1] = '\0';
	return (word);
}

void	fill_word_end(char **array, char **str, int *word_index)
{
	array[*word_index] = word_dupe(*str);
	(*word_index)++;
	while (**str != '\0' && **str != ' ' && **str != '\t'
		&& **str != '\n' && **str != '\'' && **str != '\"')
		++(*str);
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
			continue ;
		}
		if (*str == ' ')
		{
			array[word_index] = malloc(2);
			array[word_index][0] = ' ';
			array[word_index][1] = '\0';
			str++;
			word_index++;
			continue ;
		}
		fill_word_end(array, &str, &word_index);
	}
}
