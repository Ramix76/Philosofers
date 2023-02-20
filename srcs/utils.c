/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:15:45 by framos-p          #+#    #+#             */
/*   Updated: 2023/02/20 12:37:42 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/errors.h"

static void    write_errors(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(2, &str[i], 1);
        i++;
    }   
}

int ft_error(int error)
{
    if (error == EOUTMEM)
        write_errors("Error,out of memory\n");
    if (error == EINVAL)
        write_errors("Invalid mutex");
    if (error == ERARGS)
        write_errors("Invalid number of arguments");
    if (error == EINVALARG)
        write_errors("Invalid argument");
    if (error == EINVALTIME)
        write_errors("Invalid time passed");
    if (error == EINIT_MUTEX)
        write_errors("Failed init mutex");
    return (0);
}