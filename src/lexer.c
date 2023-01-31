#include "../inc/include.h"

void init_list(t_token **head, char *split, char **splited)
{
    int words;
    int in_splited;
    in_splited = count_words(split);
    int counter = 0;
    t_token *temp;
    words = count_words(split);
    words -= 1;
    in_splited -= 2;
    while(counter < words)
    {
        temp = malloc(sizeof(t_token));
        temp->info = splited[in_splited];
        temp->len = 0;
        temp->type = 0;
        temp->next = *head;
        *head = temp;
        words--;
        in_splited--;
    }
}

void put_type_tok(t_token **head)
{
    t_token *temp;
    temp = *head;
    while(temp != NULL)
    {
        if(temp->info[0] == '|')
            temp->type = PIPE;
        // if(temp->info[0] == 32)
        //     temp->type = SPACE;
        else if(temp->info[0] == '>')
            temp->type = LESS_THAN;
        else if(temp->info[0] == '<')
            temp->type = GREATER_THAN;
        else if(temp->info[0] == '>')
            temp->type = LESS_THAN;
        else if((temp->info[0] >= 33 && temp->info[0] <= 59) || temp->info[0] == 61 || (temp->info[0] >= 63 && temp->info[0] <= 126))
            temp->type = WORD;
        else
            temp->type = SPACE;
        temp = temp->next;
    }
}

//распознать типы токенов

