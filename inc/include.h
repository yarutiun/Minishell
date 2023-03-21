/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:08:12 by nrenz             #+#    #+#             */
/*   Updated: 2023/03/21 19:06:49 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

# define MAX_PATH 2000


typedef enum e_token 
{
	WORD,
	PIPE,
	SPACE,
	GREATER_THAN,
	LESS_THAN,
	DOUBLE_QUOTES,
	SINGLE_QUOTES,
	HEREDOC,
	APPEND,
	EXPANSION,
	MINI_FILE
}	t_type;


typedef struct s_token
{
	int		type;
	char	*info;
	int		len;
	struct	s_token *next;
}	t_token;


typedef struct	s_pipe_group
{
	char				**argv;
	char				*cmd;
	int 				fd[2];
	int					input;
	int					output;
	int					pipe_index;
	char				*heredoc;
	struct s_pipe_group	*next;
}	t_pipe_group;


typedef struct s_minishell
{
	char	**envp;
	int		error;
	char	**builtin_cmd;
	char	*cmd_path;
}			t_minishell;

extern t_minishell *shell_h;

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
void	cat_quote(char **splited, int *words, t_token **head);
void	expander(t_token **token);
/* PARSER */

/* UTILS */
int		assign_env(char **envp, t_minishell **shell_h);
char	*get_working_path(char *cmd, char **env);
int		count_words(char *str);
void	fill_words(char **array, char *str);
char	*word_dupe(char *str);
int		ft_wordlen(char *str);
int     ft_lstsize_mod(t_token *lst);
int	find_path_env(char **env, char *key);
char *cut_key(char **env, int index, char *key);
void change_words(t_token *temp);
char *cut_key(char **env, int index, char *key);
// static int	find_path_env(char **env, char *key);

/* BUILTINS */
// int		ft_env(t_minishell *global);
// char	*ft_pwd(t_minishell *global);

#endif