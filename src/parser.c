/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:16:54 by yarutiun          #+#    #+#             */
/*   Updated: 2023/02/21 15:03:16 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void set_pipe_group(t_pipe_group **head_pipe, t_token **head_tok)
{
    t_pipe_group *temp_pipe;
    t_token *temp_tok;
    
    int i = 0;
    temp_pipe = *head_pipe;
    temp_tok = *head_tok;
    malloc_pipe_list(head_pipe, head_tok);
    while(temp_pipe->next)
    {
        while(temp_tok->type != PIPE || temp_tok != NULL)
        {
            ft_strcpy(temp_pipe->builtin_cmd[i], temp_tok->info);
            printf("%s\n", temp_pipe->builtin_cmd[i]); // not working for some reason, hmm...
            temp_tok = temp_tok->next;
            i++;
        }
        temp_pipe = temp_pipe->next;
    }
}

//returns 0 if malloc failed, 1 if alles gut
int malloc_pipe_list(t_pipe_group **head_pipe, t_token **head)
{
    t_pipe_group *temp_pipe;
    int pipes;
    int counter;
    
    counter = 1;
    pipes = count_pipes(head);
    temp_pipe = *head_pipe;
    while(counter <= pipes)
    {
        temp_pipe = malloc(sizeof(t_pipe_group));
        if(!temp_pipe)
            return(0);
        temp_pipe = temp_pipe->next;
        counter++;
    }
    return(1);
}

//counts pipes for knowledge of how many pipe groups we have
int count_pipes(t_token **head)
{
    t_token *temp;
    int counter_pipes;

    counter_pipes = 1; //because if we don't have a pipe, we still have one group of commands
    temp = *head;
    while(temp->next != NULL)
    {
        if(temp->type == PIPE)
        {
            counter_pipes++;
        }
        temp = temp->next;
    }
    return(counter_pipes);
}