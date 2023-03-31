/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:48:32 by framos-p          #+#    #+#             */
/*   Updated: 2023/03/08 11:11:34 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/errors.h"

static int  unlock_forks(t_philo *philo)
{
  if (pthread_mutex_unlock(&philo->data->forks[philo->left_fork]) != 0)
    return (ft_error(EMUTUNLOCK));
  if (pthread_mutex_unlock(&philo->data->forks[philo->right_fork]) != 0)
    return (ft_error(EMUTUNLOCK));
  return (0);
}

int eat(t_philo *philo)
{
  t_data  *data;
 
  data = philo->data;
  if (data->dead != 0)
    return (-1);
  if (pthread_mutex_lock(&data->forks[philo->left_fork]) != 0)
    return (ft_error(EMUTLOCK));
  if (print_action_taken(data, GRAB_LEFT) != 0)
    return (1);
  if (pthread_mutex_lock(&data->forks[philo->right_fork]) != 0)
    return (ft_error(EMUTLOCK));
  if (data->dead == 0)
  {
    if (print_action_taken(data, GRAB_RIGHT) != 0)
      return (1);
    philo->time_last_meal = time_stamp() - data->time_start;
    if (print_action_taken(data, EAT) != 0)
      return (1);
    if (ft_usleep(data->time_to_eat) != 0)
      return (1);
      philo->eat_counter++;
  }
  unlock_forks(philo);
  return (0);
}