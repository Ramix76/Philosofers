/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conditions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:24:48 by framos-p          #+#    #+#             */
/*   Updated: 2023/04/06 11:06:39 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/errors.h"

static int	check_routine_finish(t_data *data)
{
	int	i;
	int	full;

	i = -1;
	full = 0;
	if (data->n_times_ate == -1)
		return (0);
	while (++i < data->n_philos)
	{
		if (data->philo[i].eat_counter >= data->n_times_ate)
			full++;
		else
			break ;
	}
	if (full >= data->n_philos)
	{
		if (pthread_mutex_lock(&data->death) != 0)
			return (ft_error(EMUTLOCK));
		data->dead = 1;
		if (pthread_mutex_lock(&data->print) != 0)
			return (ft_error(EMUTUNLOCK));
		return (1);
	}
	return (0);
}

static int	check_are_alive(t_data *data)
{
	int				i;
	long long int	time_lapse;

	i = -1;
	while (++i < data->n_philos)
	{
		time_lapse = time_stamp() - data->time_start;
		if (data->time_to_die < time_lapse - data->philo[i].time_last_meal)
		{
			if (pthread_mutex_lock(&data->death) != 0)
				return (ft_error(EMUTLOCK));
			data->dead = 1;
			if (diying(&data->philo[i], DIE) != 0)
				return (1);
			return (1);
		}
	}
	return (0);
}

int	check_loop(t_data *data)
{
	while (data->dead == 0)
	{
		if (check_routine_finish(data) != 0)
			return (1);
		if (check_are_alive(data) != 0)
			return (1);
	}
	return (0);
}
