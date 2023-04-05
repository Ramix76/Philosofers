/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:56:31 by framos-p          #+#    #+#             */
/*   Updated: 2023/04/05 17:08:14 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/errors.h"

int	print_action_taken(t_philo *philo, int action)
{
	long long int	st;

	st = time_stamp() - philo->data->time_start;
	if (philo->data->dead == 0)
	{
		if (pthread_mutex_lock(&philo->data->print) != 0)
			return (ft_error(EMUTLOCK));
		if (action == GRAB_LEFT)
			printf("%s[%lld ms]%s %sPhilo [%ld]%s %sleft fork taken%s\n",
				GRN, st, RESET, BLU, philo->num, RESET, YEL, RESET);
		if (action == GRAB_RIGHT)
			printf("%s[%lld ms]%s %sPhilo [%ld]%s %sright fork taken%s\n",
				GRN, st, RESET, BLU, philo->num, RESET, GRAY, RESET);
		if (action == EAT)
			printf("%s[%lld ms]%s %sPhilo [%ld]%s %sis eating%s\n",
				GRN, st, RESET, BLU, philo->num, RESET, UCYN, RESET);
		if (action == SLEEP)
			printf("%s[%lld ms]%s %sPhilo [%ld]%s %sis sleeping%s\n",
				GRN, st, RESET, BLU, philo->num, RESET, UMAG, RESET);
		if (action == THINK)
			printf("%s[%lld ms]%s %sPhilo [%ld]%s %sis thinking%s\n",
				GRN, st, RESET, BLU, philo->num, RESET, UWHT, RESET);
		pthread_mutex_unlock(&philo->data->print);
	}
	return (0);
}

int	diying(t_philo *philo, int action)
{
	long long int	st;

	st = time_stamp() - philo->data->time_start;
	if (pthread_mutex_lock(&philo->data->print) != 0)
		return (ft_error(EMUTLOCK));
	if (action == DIE)
		printf("%s[%lld ms]%s %sPhilo [%ld]%s %sjust died%s\n",
			GRN, st, RESET, BLU, philo->num, RESET, RED, RESET);
	if (pthread_mutex_unlock(&philo->data->print) != 0)
		return (ft_error(EMUTUNLOCK));
	return (0);
}
