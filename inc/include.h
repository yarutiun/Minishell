/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:08:12 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/18 17:13:17 by yarutiun         ###   ########.fr       */
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

enum	e_mini_errors
{
	QUOTE = 10,
	NDIR = 11,
	NPERM = 12,
	NCMD = 13,
	DUPERR = 14,
	FORKERR = 15,
	PIPERR = 16,
	PIPENDERR = 17,
	MEM = 18,
	IS_DIR = 19,
	NOT_DIR = 20
};
/*
** 10 = Quote error, if cant match quotes
** 11 = File or Directory error
** 12 = No permission error
** 13 = Command error, wrong command
** 14 = Duplication error, dup2
** 15 = Fork error, cant create or else
** 16 = Pipe error, cant create or else
** 17 = Syntax error, wrong usage of "|"
** 18 = Memory error, no space of else
** 19 = If its directory (z.B when u try delete folder without flags)
** 20 = Not a directory
*/

extern int	g_status;

typedef struct	s_token
{
	int				type;
	char			*info;
	int				len;
	struct s_token	*next;
}	t_token;

typedef struct	s_minishell
{
	char 				**args;
	char				**envp;
	int					error;
	char				**builtin_cmd;
	char				*cmd_path;
	char 				*pwd;
	char 				*old_pwd;
	int					pid;
	struct s_minishell	*next;
}	t_minishell;

/* LEXER */
void	init_list(t_token **head, char *split, char **splited);
void	put_type_tok(t_token **head);
int		check_for_closed_brackets(char **splited);
int		init_all(t_token **token, t_minishell *globals, char *split, char **splited, char **envp);

/* BUILTINS */
int		builtin_cd(t_minishell *ms_data);
int		builtin_pwd(t_minishell *ms_data);
int		builtin_exit(t_minishell *ms_data);

/* ENVIROMENT */
int		assign_env(char **envp, t_minishell *shell_h);

/* PARSER */
void	fill_builtin_cmd(t_token **head, t_minishell *cmds);
int		if_builtin(char *word);

/* EXECUTION */

/* ERROR HANDLING */
void	error_args(void);
void	*das_error(int err_type, char *param, int fd);

/* UTILS */
int		ft_wordlen(char *str);
char	*word_dupe(char *str);
void	fill_words(char **array, char *str);
int		count_words(char *str);
char	**ft_split_minishell(char *str);
int		ft_lstsize_mod(t_token *lst);

#endif
