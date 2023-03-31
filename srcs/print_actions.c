/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:56:31 by framos-p          #+#    #+#             */
/*   Updated: 2023/03/08 13:33:51 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/errors.h"

int print_action_taken(t_data *data, int action)
{
    if (pthread_mutex_lock(&data->print) != 0)
        return (ft_error(EMUTLOCK));
    if (action == GRAB_LEFT)
        printf("Philo has taken the left fork\n");
    if (action == GRAB_RIGHT)
        printf("Philo has taken the right fork\n");
    if (action == EAT)
        printf("Philo is eating\n");
    if (action == SLEEP)
        printf("Philo is sleeping\n");
    if (action == THINK)
        printf("Philo is thinking\n");
    if (action == DIE)
        printf("Philo just died\n");
    if (pthread_mutex_unlock(&data->print) != 0)
       return (ft_error(EMUTUNLOCK));
    return (0);        
}