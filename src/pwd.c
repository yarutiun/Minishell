/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:58:05 by yarutiun          #+#    #+#             */
/*   Updated: 2023/02/08 17:04:49 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

char *get_pwd(void)
{
    char *buf;
    buf = malloc(sizeof(char) * 100);
    getcwd(buf, 100);
    printf("%s", buf);
    return(buf);
}