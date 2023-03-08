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

int eat(t_philo *philo)
{
     t_data  *data;
 // printf("Hola\n");
    data = philo->data;
  //  if (pthread_mutex_lock(&data->forks[philo->left_fork]) < 0)
    //    return (ft_error(EMUTLOCK));
    if (print_action_taken(data) != 0)
        return (1);
    //if (pthread_mutex_lock(&data->forks[philo->right_fork]) < 0)
     //   return (ft_error(EMUTLOCK));
    //if (print_action_taken(data) != 0)
      //  return (1);
   // unlock_forks(philo);
    return (0);
}