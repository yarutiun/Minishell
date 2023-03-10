/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:11:59 by hboichuk          #+#    #+#             */
/*   Updated: 2023/02/27 21:32:23 by hboichuk         ###   ########.fr       */
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
# include <stdint.h>

//other heders
// # include "parser.h"

//tokens types
# define WORD 1		   // "Hello World"
# define PIPE 2		   // "|"
# define SPACE 3		   // ' '
# define GREATER_THAN 4 // <
# define LESS_THAN 5	   // >
# define QUOTES 6	   // " "
# define HEREDOC 7	   // <<
# define EXPANSION 8	   //$
# define MINI_FILE 9

/*		ERRORS CODES	*/
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

/*		GLOBAL VARIABLE		*/

/*		TOKEN STRUCT		*/
//tokens
typedef struct	s_token
{
	int				tok_type;
	char			*str;
	int				index;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

/*		GLOBAL STRUCT		*/

typedef struct s_global
{
	char					*args;
	char					**paths;
	char					**envp;
	char					*pwd;
	char					*old_pwd;
	int						pipes;
	int						*pid;
	t_token					*lexer_list;
	struct s_simple_cmds	*simple_cmds;
	// bool					heredoc;
	// bool					reset;
}	t_global;

/*		COMAND STRUCT		*/
typedef struct s_simple_cmds
{
	char						**str;
	int							redirect_count;
	char						*hd_file_name; //i have no idea, we need it or not
	int							(*builtin)(t_global *, struct s_simple_cmds *);
	struct s_simple_cmds		*next;
	struct s_simple_cmds		*prev;
}		t_simple_cmds;

/*		INIT FUNCTIONS		*/

void	init_global_struct(char **envp);
void	run_minishell_loop(t_global *minishell);
int		find_pwd(t_global *minishell);
char	**init_envp(char **envp);
/*		LEXER		*/
t_token	*lexer(t_global *global);
char	**split_arguments(char *string);
t_token	*fill_stack_tokens(char **argv, t_token *tokens_arr);
t_token	*create_new_list(char *data, int index);
void	get_type_tok(t_token *token_arr);
/*		PARSER		*/
int		parser(t_global *global_struct);
void	count_pipes(t_global *global_struct);
/*		EXPANDER		*/

/*		EXECUTOR		*/

/*		BILTINS		*/

/*		ADDITIONAL FUNCTIONS		*/
#endif
