/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:11:22 by framos-p          #+#    #+#             */
/*   Updated: 2023/02/17 18:30:44 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/errors.h"

int init_philos(t_table *table)
{
    int i;

    table->philos = malloc(sizeof(t_philo) * table->n_philos);
    if (table->philos == NULL)
        return (ft_error(EOUTMEM));
    i = 0;
    while (i < table->n_philos)
    {
        table->philos[i].num = i;
        table->data->dead = 0;
		table->philos[i].eat_counter = 0;
        table->philos[i].last_meal = 0;
        i++;
    }
    return (0);
}

int init_mutexes(t_table *table)
{
    int i;
    
    table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philos);
    if (table->forks == NULL)
        return (ft_error(EOUTMEM));
    i = 0;
    while (i < table->n_philos)
    {
        if (pthread_mutex_init(&table->forks[i], NULL) != 0)
            return (ft_error(ECANCELED));
        i++;
    }
    return (0);
}