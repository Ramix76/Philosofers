/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:56:31 by framos-p          #+#    #+#             */
/*   Updated: 2023/04/11 12:05:15 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines_bonus.h"
#include "../inc/errors_bonus.h"

int	print_action_taken(t_philo *philo, int action)
{
	long long int	st;

	st = time_stamp() - philo->data->time_start;
	sem_wait(philo->data->print);
	if (action == GRAB_LEFT && !philo->data->dead)
		printf("%s[%lld ms]%s %sPhilo [%ld]%s %sleft fork taken%s\n",
			GRN, st, RESET, BLU, philo->num, RESET, YEL, RESET);
	if (action == GRAB_RIGHT && !philo->data->dead)
		printf("%s[%lld ms]%s %sPhilo [%ld]%s %sright fork taken%s\n",
			GRN, st, RESET, BLU, philo->num, RESET, GRAY, RESET);
	if (action == EAT && !philo->data->dead)
		printf("%s[%lld ms]%s %sPhilo [%ld]%s %sis eating%s\n",
			GRN, st, RESET, BLU, philo->num, RESET, UCYN, RESET);
	if (action == SLEEP && !philo->data->dead)
		printf("%s[%lld ms]%s %sPhilo [%ld]%s %sis sleeping%s\n",
			GRN, st, RESET, BLU, philo->num, RESET, UMAG, RESET);
	if (action == THINK && !philo->data->dead)
		printf("%s[%lld ms]%s %sPhilo [%ld]%s %sis thinking%s\n",
			GRN, st, RESET, BLU, philo->num, RESET, UWHT, RESET);
	sem_post(philo->data->print);
	return (0);
}

int	diying(t_philo *philo, int action)
{
	long long int	st;

	st = time_stamp() - philo->data->time_start;
	sem_wait(philo->data->print);
	if (action == DIE)
		printf("%s[%lld ms]%s %sPhilo [%ld]%s %sjust died%s\n",
			GRN, st, RESET, BLU, philo->num, RESET, RED, RESET);
	sem_post(philo->data->print);
	return (0);
}
