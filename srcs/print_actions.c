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
        printf("%s[%lld ms]%s %sPhilo [%ld]%s %shas taken the left fork%s\n", GRN, time_stamp() - philo->data->time_start, RESET, BLU, philo->num, RESET, YEL, RESET);
    if (action == GRAB_RIGHT)
        printf("%s[%lld ms]%s %sPhilo [%ld]%s %shas taken the right fork%s\n", GRN, time_stamp() - philo->data->time_start, RESET, BLU, philo->num, RESET, GRAY, RESET);
    if (action == EAT)
        printf("%s[%lld ms]%s %sPhilo [%ld]%s %sis eating%s\n", GRN, time_stamp() - philo->data->time_start, RESET, BLU, philo->num, RESET, UCYN, RESET);
    if (action == SLEEP)
        printf("%s[%lld ms]%s %sPhilo [%ld]%s %sis sleeping%s\n", GRN, time_stamp() - philo->data->time_start, RESET, BLU, philo->num, RESET, UMAG, RESET);
    if (action == THINK)
        printf("%s[%lld ms]%s %sPhilo [%ld]%s %sis thinking%s\n", GRN, time_stamp() - philo->data->time_start, RESET, BLU, philo->num, RESET, UWHT, RESET);
    if (action == DIE)
        printf("%s[%lld ms]%s %sPhilo [%ld]%s %sjust died%s\n", GRN, time_stamp() - philo->data->time_start, RESET, BLU, philo->num, RESET, RED, RESET);
    if (pthread_mutex_unlock(&philo->data->print) != 0)
       return (ft_error(EMUTUNLOCK));
    return (0);        
}