/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:48:47 by yarutiun          #+#    #+#             */
/*   Updated: 2023/02/20 16:50:14 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void free_token(t_token **token)
{
    t_token *temp;
    temp = *token;
    while(temp->next)
    {
        free(temp->info);
        temp = temp->next;
    }
}