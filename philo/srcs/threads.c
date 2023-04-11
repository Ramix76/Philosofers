/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:28:18 by framos-p          #+#    #+#             */
/*   Updated: 2023/04/11 12:13:26 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

static int	philo_eating_solo(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (pthread_mutex_lock(&data->forks[philo->left_fork]) != 0)
		return (ft_error(EMUTLOCK));
	if (print_action_taken(philo, GRAB_LEFT) != 0)
		return (1);
	if (ft_usleep(data->time_to_die) != 0)
		return (1);
	if (print_action_taken(philo, DIE) != 0)
		return (1);
	if (pthread_mutex_unlock(&data->forks[philo->left_fork]) != 0)
		return (ft_error(EMUTUNLOCK));
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->num % 2 == 0)
	{
		if (ft_usleep(philo->data->time_to_eat) != 0)
			return (0);
	}
	philo->time_last_meal = time_stamp() - philo->data->time_start;
	if (philo->data->n_philos == 1)
	{
		if (philo_eating_solo(philo) != 0)
			return (0);
	}
	else
	{
		while (philo->data->dead == 0)
		{
			if ((do_think(philo) != 0 || (do_eat(philo) != 0)
					|| (do_sleep(philo) != 0)))
				break ;
		}
	}
	return (0);
}

int	create_threads(t_data *data)
{
	pthread_t	*network;
	int			i;

	network = malloc(sizeof(pthread_t) * data->n_philos);
	if (network == NULL)
		return (ft_error(EOUTMEM));
	i = -1;
	while (++i < data->n_philos)
	{
		if (pthread_create(&network[i], NULL, routine, &data->philo[i]) != 0)
		{
			free(network);
			return (ft_error(E_CREATE_TH));
		}
	}
	check_loop(data);
	if (join_and_unlock(data, network) != 0)
		return (1);
	return (0);
}
