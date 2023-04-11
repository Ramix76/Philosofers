/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:11:22 by framos-p          #+#    #+#             */
/*   Updated: 2023/04/11 11:17:54 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines_bonus.h"
#include "../inc/errors_bonus.h"

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
		data->philo[i].eat_counter = 0;
		data->philo[i].time_last_meal = data->time_start;
		data->philo[i].data = data;
		data->dead = 0;
	}
	return (0);
}

int	init_semaphores(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/death");
	data->forks = sem_open("/forks", O_CREAT, S_IRWXU, data->n_philos);
	data->print = sem_open("/print", O_CREAT, S_IRWXU, 1);
	data->death = sem_open("/death", O_CREAT, S_IRWXU, 1);
	if (data->forks <= 0 || data->print <= 0 || data->death <= 0)
		return (1);
	return (0);
}
