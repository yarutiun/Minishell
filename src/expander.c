/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:17:10 by yarutiun          #+#    #+#             */
/*   Updated: 2023/03/21 20:38:43 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

//this function assigns shell_h->envp 
//sets value of our envp to structure
int assign_env(char **envp, t_minishell **shell_h)
{
    int counter;
    int len;
    char **temp;
    
    counter = 0;
    int i = 0;
    *shell_h = malloc(sizeof(t_minishell));
    if(!(*shell_h))
        return(0);
    while(envp[counter])
        counter++;
    temp = malloc(sizeof(char *) * counter);
    if(!temp)
        return(0);
    while(i != counter)
    {
        len = ft_strlen(envp[i]);
        temp[i] = malloc(sizeof(char *) * len);
        if(!temp[i])
            return(0);
        temp[i] = envp[i];
        i++;
        len = 0;
    }
    (*shell_h)->envp = temp;
    // printf("%s", shell_h->envp[0]);
    // printf("%s", shell_h->envp[1]);
    return(1);
}

void strjoin_free(char **str, char *add)
{
    char *res;

    res = ft_strjoin(*str, add);
    free(*str);
    *str = res;
}

void charjoin_free(char **str, char add)
{
    char *res;
    char *adder;

    adder = malloc(2);
    adder[1] = 0;
    adder[0] = add;
    res = ft_strjoin(*str, adder);
    free(*str);
    free(adder);
    *str = res;
}

void change_words(t_token *temp)
{
    int index;
    char *key;
    char *ret;
    
    key = ft_substr(temp->info, 1, ft_strlen(temp->info) - 1);
    index = find_path_env(shell_h->envp, key);
    if(index == -1)
    {
        free(temp->info);
        free(key);
        temp->len = 0;
        temp->info = ft_strdup("");
        return ;
    }
    ret = cut_key(shell_h->envp, index, key);
    free(temp->info);
    free(key);
    temp->info = ret;
    temp->len = ft_strlen(ret);
}

void sub_dollar(char **ret, char *info, int *i)
{
    char *key;
    int index;
    char *ret1;

    key = NULL;
    (*i)++;
    while(info[*i] != ' ' && info[*i] != '\0')
    {
        charjoin_free(&key, info[*i]);
        (*i)++;
    }
    index = find_path_env(shell_h->envp, key);
    if(index == -1)
    {
        free(key);
        return ;
    }
    ret1 = cut_key(shell_h->envp, index, key);
    free(key);
    strjoin_free(ret, ret1);
    free(ret1);
}

void change_quotes(t_token *temp)
{
    char *ret;
    char *info;
    int i;

    ret = NULL;
    info = temp->info;
    i = 0;
    while (info[i])
    {
        if(info[i]== '$' && (info[i+1] != ' ' && info[i+1] != '\0'))
        {
            sub_dollar(&ret, info, &i);
        }
        else
        {
            charjoin_free(&ret, info[i]);
            i++;
        }
    }
    free(temp->info);
    temp->info = ret;
    temp->len = ft_strlen(ret);
}

void expander(t_token **token)
{
    t_token *temp;
    int index;
    char *key;
    char *ret;

    temp = *token;
    while(temp)
    {
        if(temp->type == WORD && temp->info[0] == '$' && temp->info[1])
            // if(temp->info[ft_strlen(temp->info) - 1] != '$')
                change_words(temp);
        if (temp->type == DOUBLE_QUOTES)
            change_quotes(temp);
        temp = temp->next;
    }
}




// int main(int argc, char **argv, char **envp)
// {
//     (void) argc;
//     (void) argv;
//     t_minishell *shell_h = NULL;
//     assign_env(envp, shell_h);
//     printf("%s", shell_h->envp[0]);
//     // expand_and_print();
//     return(0);
// }

// setenv returns -1 if variable does not exist

