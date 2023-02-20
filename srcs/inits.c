/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:11:22 by framos-p          #+#    #+#             */
/*   Updated: 2023/02/20 16:07:16 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/errors.h"

int init_philos(t_data *data)
{
    int i;
    t_philo *tmp;

    data->philo = malloc(sizeof(t_philo) * data->n_philos);
    if (data->philo == NULL)
        return (ft_error(EOUTMEM));
    i = -1;
    tmp = data->philo;
    while (++i < data->n_philos)
    {      
        tmp->num = i + 1;
        tmp->left_fork = i;
        tmp->eat_counter = 0;
        tmp->time_last_meal = 0;
        tmp->data = data;
        tmp->right_fork = i + 1;
        tmp++;
    }
    tmp[i - 1].right_fork = 0;
    return (0);
}

int init_mutexes(t_data *data)
{
    int i;
    
    if (pthread_mutex_init(&data->print, NULL) != 0)
        return (ft_error(EINIT_MUTEX));
    data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
    if (data->forks == NULL)
        return (ft_error(EOUTMEM));
    i = 0;
    while (i < data->n_philos)
    {
        if (pthread_mutex_init(&data->forks[i], NULL) != 0)
            return (ft_error(ECANCELED));
        i++;
    }
    return (0);
}