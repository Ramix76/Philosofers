/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:28:18 by framos-p          #+#    #+#             */
/*   Updated: 2023/02/23 15:53:13 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

void    *routine(t_data *data)
{
    pthread_mutex_lock(&data->print);
    printf("Hello\n");
    pthread_mutex_unlock(&data->print);
    return (NULL);
}

int create_threads(t_data *data)
{
    pthread_t   *network;
    int         i;

    network = malloc(sizeof(pthread_t) * data->n_philos);
    if (network == NULL)
        return (ft_error(EOUTMEM));
    i = 0;
    while (i < data->n_philos)
    {
        if (pthread_create(&network[i], NULL, (void *(*)(void *))routine, &data->philo[i]) != 0)
        {
            free(network);
            return (ft_error(E_CREATE_TH));
        }
        i++;
    }
    return (0);        
}