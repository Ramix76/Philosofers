/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:48:32 by framos-p          #+#    #+#             */
/*   Updated: 2023/06/01 10:43:17 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines_bonus.h"
#include "../inc/errors_bonus.h"

void	do_eat(t_philo *philo)
{
	sem_wait(philo->data->forks);
	print_action_taken(philo, GRAB_LEFT);
	sem_wait(philo->data->forks);
	print_action_taken(philo, GRAB_RIGHT);
	sem_wait(philo->data->death);
	print_action_taken(philo, EAT);
	philo->eat_counter++;
	philo->time_last_meal = time_stamp();
	sem_post(philo->data->death);
	ft_usleep(philo->data->time_to_eat);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

int	do_sleep(t_philo *philo)
{
	if (philo->data->dead != 0)
		return (-1);
	if (print_action_taken(philo, SLEEP) != 0)
		return (1);
	if (ft_usleep(philo->data->time_to_sleep) != 0)
		return (1);
	return (0);
}

int	do_think(t_philo *philo)
{
	if (philo->data->dead != 0)
		return (-1);
	if (print_action_taken(philo, THINK) != 0)
		return (1);
	return (0);
}
