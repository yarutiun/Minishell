/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:08:12 by nrenz             #+#    #+#             */
/*   Updated: 2023/04/03 10:46:56 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

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
# define SYNTAX_ERROR "minishell: syntax error near unexpected token\n"
# define OPEN_ERROR "minishell: couldn't open such file or directory\n"

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
	int				type;
	char			*info;
	int				len;
	struct s_token	*next;
}	t_token;

typedef struct s_pipe_group
{
	char				**argv;
	char				*cmd;
	int					fd[2];
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

extern t_minishell	*g_shell_h;
/* FUNCTIONS */
int				check_builtins(t_minishell *cmd_group);
int				if_builtin(char *word);
void			fill_builtin_cmd(t_token **head, t_minishell *cmds);
void			sub_dollar(char **ret, char *info, int *i);
void			strjoin_free(char **str, char *add);
void			charjoin_free(char **str, char add);
int				check_keyword(char *args);
void			error_handler(char *error_msg);
void			expander(t_token **token);
void			init_vars_env(int *counter, char ***temp, int *i, char **envp);
void			split_words(t_token	**head);
void			find_tokens(t_token **temp);
char			**ft_split_minishell(char *str);
int				init_list(t_token **head, char *split, char **splited);
void			put_type_tok(t_token **head);
int				check_for_closed_brackets(char **splited);
void			cat_quote(char **splited, int *words, t_token **head);
void			expander(t_token **token);
t_pipe_group	*redirection(t_token **token);
void			change_quotes(t_token *temp);
int				fork_and_execute(t_pipe_group *data, int in_fd, int out_fd);
int				exec_builtin_parent(t_pipe_group *pipes);
int				executor(t_pipe_group *data);
void			skip_space(t_token **token);
int				here_doc(t_token **token_tmp, t_pipe_group **tmp);
void			print_export(void);
int				check_for_closed_brackets(char **splited);
void			charjoin_free(char **str, char add);
int				assign_env(char **envp);
char			*get_working_path(char *cmd, char **env);
int				count_words(char *str);
void			fill_words(char **array, char *str);
char			*word_dupe(char *str);
int				ft_wordlen(char *str);
int				ft_lstsize_mod(t_token *lst);
int				find_path_env(char **env, char *key);
char			*cut_key(char **env, int index, char *key);
void			change_words(t_token *temp);
char			*cut_key(char **env, int index, char *key);
void			free_t_pipe(t_pipe_group **token);
void			free_t_token(t_token **token);
void			free_shell_h(void);
int				throw_error(char *error);
void			throw_error_exec(char *error);
void			free_argv(char **argv);
void			free_env(char **env);
int				command_exec_prep(t_pipe_group *data, t_pipe_group *prev,
					int in_fd, int out_fd);
int				put_skip(t_token **temp);
int				quote_if(t_pipe_group **tmp, t_token **token_tmp,
					int *first, int *count_words);
int				pipe_if(t_pipe_group **tmp, t_token **token_tmp,
					int *first, int *count_words);
t_pipe_group	*init_pipe(int index);
int				create_red(t_token **token_tmp, t_pipe_group **tmp);
void			free_splited(char **splited);
void			free_readed_and_splited(char *readed, char **splited);
int				main_split(char **splited, char *readed);
void			ft_lexer(void);

//signals
void			signals(void);
void			child_sig(void);
void			heredoc_sig(void);
void			sig_handle(int sig);
void			sig_handle_child(int sig);
void			heredoc_sig_handle(int sig);
void			put_lvl(void);

/* BUILTINS */
int				b_cd(char *arg);
int				b_echo(char **args);
int				ft_env(void);
int				b_exit(char **av);
int				b_export(char **args);
int				b_unset(char **args);
int				ft_pwd(void);
void			set_new(char *arg);

#endif
