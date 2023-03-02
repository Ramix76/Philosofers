/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:32:13 by framos-p          #+#    #+#             */
/*   Updated: 2023/03/02 17:07:16 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

int cleanning(t_data *data, int destroy, int error)
{
    int i;

    i = 0;
    if (destroy == 1)
    {
        if (pthread_mutex_destroy(&data->print) != 0)
            ft_error(ERRDEST);
        if (pthread_mutex_destroy(&data->death) != 0)
            ft_error(ERRDEST);
        while (i < data->n_philos)
        {
            if (pthread_mutex_destroy(&data->forks[i]) != 0)
                ft_error(ERRDEST);
            i++;
        }
    }
    //free(data->print);
    //free(data->forks);
    //free(data);
    return (error);
}