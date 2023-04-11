/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:28:18 by framos-p          #+#    #+#             */
/*   Updated: 2023/04/06 17:17:28 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines_bonus.h"

void	*check_loop(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	while (data->dead)
	{
		sem_wait(data->death);
		if ((time_stamp() - philo->time_last_meal) >= data->time_to_die)
		{
			print_action_taken(philo, DIE);
			data->dead = 0;
			sem_wait(data->print);
			exit(1);
		}
		sem_post(data->death);
		ft_usleep(1000);
		if (!(data->dead))
			break ;
		if (data->n_times_ate && philo->eat_counter == data->n_times_ate)
			break ;
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->time_last_meal = time_stamp();
	pthread_create(&(philo->th), NULL, (void *(*)(void *))check_loop, philo);
	while (philo->data->dead == 0)
	{
		do_eat(philo);
		if (philo->eat_counter && philo->data->n_times_ate == philo->eat_counter)
			break ;
		do_sleep(philo);
		do_think(philo);
	}
	pthread_join(philo->th, NULL);
	if (!philo->data->dead)
		exit(1);
	exit(0);
}

void	exit_action(t_data *data)
{
	int			i;
	int			stat;

	i = -1;
	while (++i < data->n_philos)
	{
		waitpid(-1, &stat, 0);
		if (stat)
		{
			i = -1;
			while (++i < data->n_philos)
				kill(data->philo[i].pid, SIGTERM);
			break ;
		}
		i++;
	}
	sem_close(data->forks);
	sem_close(data->print);
	sem_close(data->death);
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/death");
}

int	create_processes(t_data *data)
{
	int	i;

	i = -1;
	data->time_start = time_stamp();
	while (++i < data->n_philos)
	{
		data->philo[i].pid = fork();
		if (data->philo[i].pid < 0)
			return (1);
		if (data->philo[i].pid == 0)
			routine(&data->philo[i]);
		usleep(50);
	}
	exit_action(data);
	return (0);
}
