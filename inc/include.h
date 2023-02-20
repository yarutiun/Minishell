/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:08:12 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/19 15:46:22 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//better enum?
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

//token
typedef struct	s_token
{
	int				type;
	char			*info;
	int				len;
	// int				index; maybe we need it?
	struct s_token	*next;
}	t_token;

//global init struct
typedef struct	s_minishell
{
	// int					argc;don't need it?
	char				*argv;//one pointer?
	char				**envp;
	// char				**paths;for inner cmd 
	int					error;//do we need it?
	char				**builtin_cmd;//struct?
	char				*cmd_path;// for pwd, do we need old pwd?
	// char				*key;//??
	// char				*value;//??
	bool				heredoc;//do it later
	int					*pid;//forks
	int					pipes;//count of pipes
	// struct s_minishell	*next;//do we need it?
	bool				reset;//flag for reset or maybe do it another way?
}	t_minishell;

/* LEXER */
void	init_list(t_token **head, char *split, char **splited);
void	put_type_tok(t_token **head);

/* BUILTINS */
// int	check_builtins(t_minishell *cmd_group);
// int	builtin_handler(t_minishell cmd_group, );

/* ENVIROMENT */
// t_minishell	*new_envp(t_minishell *ms_data);
// t_minishell	*add_back_envp(t_minishell *ms_data);
char	**init_envp(char **envp);//the same, but with 2d-arr
void	init_envp_new_list(t_minishell *ms_data);
void	print_envp_new_list(t_minishell *ms_data);
void	fill_builtin_cmd(t_token **head, t_minishell *cmds);
int		if_builtin(char *word);

/* INIT */
int	init_global_data(t_minishell *global_struct, char **envp);
int	run_minishell(t_minishell *global_data);
/* PARSER */
int	start_parser(t_minishell *global_data);

/* EXECUTION */

/* ERROR HANDLING */
void	error_args(void);

/* UTILS */
int		ft_wordlen(char *str);
char	*word_dupe(char *str);
void	fill_words(char **array, char *str);
int		count_words(char *str);
char	**ft_split_minishell(char *str);

#endif
