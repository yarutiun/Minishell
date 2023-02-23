/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:16:54 by yarutiun          #+#    #+#             */
/*   Updated: 2023/02/23 12:26:29 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

// void set_pipe_group(t_pipe_group **head_pipe, t_token **head_tok)
// {
//     t_pipe_group *temp_pipe;
//     t_token *temp_tok;
//     // (void) head_pipe;
//     // int i = 0;
//     int counter = 0;
//     int pipes;
//     pipes = count_pipes(head_tok);
//     // temp_pipe = *head_pipe;
//     malloc_pipe_list(head_pipe, head_tok);
//     while(counter < pipes)
//     {
//     printf("frgrhtjykuli");
//     temp_tok = *head_tok;
//         while(temp_tok != NULL)
//         {
//             // ft_strcpy(temp_pipe->builtin_cmd[i], temp_tok->info);
//             // printf("%s\n", temp_pipe->builtin_cmd[i]); // not working for some reason, hmm...
//             temp_tok = temp_tok->next;
//         printf("A\n");
//             // i++;
//         }
//         temp_pipe = temp_pipe->next;
//         printf("b\n");
//         counter++;
//     }
// }

// //returns 0 if malloc failed, 1 if alles gut
// int malloc_pipe_list(t_pipe_group **head_pipe, t_token **head)
// {
//     t_pipe_group *temp_pipe;
//     int pipes;
//     int counter;
    
//     counter = 0;
//     pipes = count_pipes(head);
//     while(counter < pipes)
//     {
//         temp_pipe = malloc(sizeof(t_pipe_group));
//         temp_pipe->next = *head_pipe;
//         *head_pipe = temp_pipe;
//         counter++;
//     }
//     return(1);
// }

//counts pipes for knowledge of how many pipe groups we have
int count_pipes(t_token **head)
{
    t_token *temp;
    int counter_pipes;

    counter_pipes = 1; //because if we don't have a pipe, we still have one group of commands
    temp = *head;
    while(temp != NULL)
    {
        if(temp->type == PIPE)
        {
            counter_pipes++;
        }
        temp = temp->next;
    }
    return(counter_pipes);
}