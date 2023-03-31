/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:28:18 by framos-p          #+#    #+#             */
/*   Updated: 2023/03/02 15:07:54 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

void    *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    eat(philo);
    return (NULL);
}

int create_threads(t_data *data)
{
    pthread_t   *network;
    int         i;

    network = malloc(sizeof(pthread_t) * data->n_philos);
    if (network == NULL)
        return (ft_error(EOUTMEM));
    i = -1;
    while (++i < data->n_philos)
    {
        ft_usleep(100);
        if (pthread_create(&network[i], NULL, (void *(*)(void *))routine, &data->philo[i]) != 0)
        {
            free(network);
            return (ft_error(E_CREATE_TH));
        }
    }
    // while (1) ;

    ft_usleep(1000);
    if (join_and_unlock(data, network) != 0)
        return (1);
    return (0);        
}

