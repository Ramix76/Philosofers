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

int print_action_taken(t_philo *philo, int action)
{
    if (pthread_mutex_lock(&philo->data->print) != 0)
        return (ft_error(EMUTLOCK));
    if (action == GRAB_LEFT)
        printf("[%lldms] Philo [%ld] has taken the left fork\n", time_stamp() - philo->data->time_start, philo->num);
    if (action == GRAB_RIGHT)
        printf("[%lldms] Philo [%ld] has taken the right fork\n", time_stamp() - philo->data->time_start, philo->num);
    if (action == EAT)
        printf("[%lldms] Philo [%ld] is eating\n", time_stamp() - philo->data->time_start, philo->num);
    if (action == SLEEP)
        printf("[%lldms] Philo [%ld] is sleeping\n", time_stamp() - philo->data->time_start, philo->num);
    if (action == THINK)
        printf("[%lldms] Philo [%ld] is thinking\n", time_stamp() - philo->data->time_start, philo->num);
    if (action == DIE)
        printf("[%lldms] Philo [%ld] just died\n", time_stamp() - philo->data->time_start, philo->num);
    if (pthread_mutex_unlock(&philo->data->print) != 0)
       return (ft_error(EMUTUNLOCK));
    return (0);        
}