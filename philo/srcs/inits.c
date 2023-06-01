/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:11:22 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/31 16:07:00 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/errors.h"

int	init_philos(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->n_philos);
	if (data->philo == NULL)
		return (ft_error(EOUTMEM));
	i = -1;
	while (++i < data->n_philos)
	{
		data->philo[i].num = i + 1;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = i + 1;
		data->philo[i].eat_counter = 0;
		data->philo[i].time_last_meal = data->time_start;
		data->philo[i].data = data;
	}
	data->philo[i - 1].right_fork = 0;
	return (0);
}

int	init_mutexes(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->death, NULL) != 0)
		return (ft_error(EINIT_MUTEX));
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (ft_error(EINIT_MUTEX));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (data->forks == NULL)
		return (ft_error(EOUTMEM));
	i = -1;
	while (++i < data->n_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (ft_error(ECANCELED));
	}
	return (0);
}
