/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:58:05 by yarutiun          #+#    #+#             */
/*   Updated: 2023/02/08 17:10:26 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

//I think generally we should chenge env when mooving 
//from one directory into another one so getcwd knows from env where to get pwd

//also we need to know the lenth of our path for allocating memory
//it's pretty hard to test it now.

char *get_pwd(void)
{
    char *buf;
    buf = malloc(sizeof(char) * 100);
    getcwd(buf, 100);
    printf("%s", buf);
    return(buf);
}
