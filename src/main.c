#include "../inc/include.h"

// void sig_handler(int signal)
// {
//     if(signal == SIGINT)
//     {
//         printf("\nexiting shell");

//         // rl_replace_line();
//         // readline("<qwert   ");
//     }
// }

// char	*ft_strcat(char *s1, const char *s2)
// {
// 	int		index;
// 	size_t	i;

// 	index = strlen(s1);
// 	i = 0;
// 	while (i < strlen((char *)s2))
// 	{
// 		s1[index] = s2[i];
// 		i++;
// 		index++;
// 	}
// 	s1[index] = '\0';
// 	return (s1);
// }

// void	prompt(void)
// {
// 	char	cwd[256];

// 	getcwd(cwd, sizeof(cwd));
// 	ft_strcat(cwd, " : ");
// 	ft_putstr_fd(cwd, 1);
// }

// void	sig_handle(int sig)
// {
// 	if (sig == SIGINT)
// 	{
// 		ft_putstr_fd("\n", 1);
// 		prompt();
// 	}
// }



int main(void)
{
    char *readed;
    t_token *head = NULL;

    char **splited;
    while(1)
    {
        readed = readline("<qwert   ");
        splited = ft_split_minishell(readed);
        init_list(&head, readed, splited);
        put_type_tok(&head);
        printf("%s    %i\n", head->next->next->info, head->next->next->type);

    }
    return(0);
}

