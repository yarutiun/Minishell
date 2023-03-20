/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:17:10 by yarutiun          #+#    #+#             */
/*   Updated: 2023/03/20 16:01:30 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

//this function assigns shell_h->envp 
//sets value of our envp to structure
// int assign_env(char **envp, t_minishell *shell_h)
// {
//     int counter;
//     int len;
//     char **temp;
    
//     counter = 0;
//     int i = 0;
//     shell_h = malloc(sizeof(t_minishell));
//     if(!shell_h)
//         return(0);
//     while(envp[counter])
//         counter++;
//     temp = malloc(sizeof(char *) * counter);
//     if(!temp)
//         return(0);
//     while(i != counter)
//     {
//         len = ft_strlen(envp[i]);
//         temp[i] = malloc(sizeof(char *) * len);
//         if(!temp[i])
//             return(0);
//         temp[i] = envp[i];
//         i++;
//         len = 0;
//     }
//     shell_h->envp = temp;
//     return(1);
// }

// int main(int argc, char **argv, char **envp)
// {
//     (void) argc;
//     (void) argv;
//     // t_minishell *shell_h = NULL;
//     // assign_env(envp, shell_h);
//     // expand_and_print();
//     return(0);
// }

//setenv returns -1 if variable does not exist

