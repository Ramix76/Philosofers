/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:28:18 by framos-p          #+#    #+#             */
/*   Updated: 2023/02/23 18:25:37 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include <sys/errno.h>
#include <errno.h>
void    *routine(t_data *data)
{
   // lock(data);
    pthread_mutex_lock(&data->print);
      // printf("%d\n", pthread_mutex_lock(&data->print));
     // ft_error(EMUTLOCK);
       
    printf("Hello\n");
   // unlock(data);
    pthread_mutex_unlock(&data->print);
        //ft_error(EMUTUNLOCK);
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
        usleep(100);
        if (pthread_create(&network[i], NULL, (void *(*)(void *))routine, &data->philo[i]) != 0)
        {
            free(network);
            return (ft_error(E_CREATE_TH));
        }
        i++;
    }
    usleep(100);
    join(data, network);
    return (0);        
}
/*
int     lock(t_data *data)
{
    return (0);
}

int     unlock(t_data *data)
{
    
    return (0);
}
*/    
int     join(t_data *data, pthread_t *pthread)
{
    int i;
    
    i = 0;
    while (i < data->n_philos)
    {
        if (pthread_join(pthread[i], NULL) != 0)
        {
            return (ft_error(ERRJOIN));
        }
       // lock(data);
        printf("thread closed\n");
        //unlock(data);
        i++;
    }
    return (0);
}