/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:08:12 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/10 14:47:16 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define WORD 1		   // "Hello World"
# define PIPE 2		   // "|"
# define SPACE 3		   // ' '
# define GREATER_THAN 4 // <
# define LESS_THAN 5	   // >
# define QUOTES 6	   // " "
# define HEREDOC 7	   // <<
# define EXPANSION 8	   //$
# define MINI_FILE 9

// "" must be closed

# include "../libft/libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_token
{
	int		type;
	char	*info;
	int		len;
	struct	s_token *next;
}	t_token;

typedef struct s_minishell
{
	int		argc;
	char	**argv;
	char	**envp;
	int		error;
	char	**builtin_cmd;
	char	*cmd_path;
}			t_minishell;

/* FUNCTIONS */
int     check_builtins(t_minishell *cmd_group);
// int     builtin_handler(t_minishell cmd_group, );
int     if_builtin(char *word);
void    fill_builtin_cmd(t_token **head, t_minishell *cmds);

/* ERRORS */
void	error_handler(char *error_msg);

/* LEXER*/
char	**ft_split_minishell(char *str);
void	init_list(t_token **head, char *split, char **splited);
void	put_type_tok(t_token **head);
int		check_for_closed_brackets(char **splited);

/* UTILS */
int		count_words(char *str);
void	fill_words(char **array, char *str);
char	*word_dupe(char *str);
int		ft_wordlen(char *str);
int     ft_lstsize_mod(t_token *lst);

//pwd
char *get_pwd(void);

#endif