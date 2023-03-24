/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:08:12 by nrenz             #+#    #+#             */
/*   Updated: 2023/03/24 18:46:49 by yarutiun         ###   ########.fr       */
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
	char			**envp;
	int				error;
	int				current_env;
	int				last;
	t_pipe_group	*pipes;
	t_token			*head;
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
void	split_words(t_token	**head);
void 	find_tokens(t_token **temp);
char	**ft_split_minishell(char *str);
int	init_list(t_token **head, char *split, char **splited);
void	put_type_tok(t_token **head);
int		check_for_closed_brackets(char **splited);
void	cat_quote(char **splited, int *words, t_token **head);
void	expander(t_token **token);
t_pipe_group *redirection(t_token **token);
/* PARSER */

/* EXECUTOR*/

int	executor(t_pipe_group *data);


/* UTILS */
int check_for_closed_brackets(char **splited);
void	charjoin_free(char **str, char add);
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
void 	free_t_pipe(t_pipe_group **token);
void	free_t_token(t_token **token);
void	free_shell_h();
void	throw_error(char *error);
void	throw_error_exec(char *error);
void	free_argv(char **argv);
void	free_env(char **env);


//signals

void	signals(void);
void	child_sig(void);
void	heredoc_sig(void);
void	sig_handle(int sig);
void	sig_handle_child(int sig);
void	heredoc_sig_handle(int sig);


// static int	find_path_env(char **env, char *key);

/* BUILTINS */
int	b_cd(char *arg);
int	b_echo(char **args);
int	ft_env(void);
int	b_exit(char **av);
int	b_export(char **args);
int	b_unset(char **args);
int ft_pwd(void);
void	set_new(char *arg);
#endif
