/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:08:12 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/07 13:51:02 by nrenz            ###   ########.fr       */
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

typedef struct	s_token
{
	int				type;
	char			*info;
	int				len;
	struct s_token	*next;
}	t_token;

typedef struct	s_minishell
{
	int					argc;
	char				**argv;
	char				**envp;
	int					error;
	char				**builtin_cmd;
	char				*cmd_path;
	char				*key;
	char				*value;
	struct s_minishell	*next;
}	t_minishell;

/* LEXER */
void	init_list(t_token **head, char *split, char **splited);
void	put_type_tok(t_token **head);

/* BUILTINS */
// int	check_builtins(t_minishell *cmd_group);
// int	builtin_handler(t_minishell cmd_group, );

/* ENVIROMENT */
t_minishell	*new_envp(t_minishell *ms_data);
// t_minishell	*add_back_envp(t_minishell *ms_data);
void	init_envp_new_list(t_minishell *ms_data);
void	print_envp_new_list(t_minishell *ms_data);

/* PARSER */

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
