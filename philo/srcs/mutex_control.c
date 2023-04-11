/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:09:56 by framos-p          #+#    #+#             */
/*   Updated: 2023/04/05 16:33:04 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

int	join_and_unlock(t_data *data, pthread_t *pthread)
{
	int	i;

	if (pthread_mutex_unlock(&data->print) != 0)
	{
		free(pthread);
		return (ft_error(EMUTUNLOCK));
	}
	if (pthread_mutex_unlock(&data->death) != 0)
	{
		free(pthread);
		return (ft_error(EMUTUNLOCK));
	}
	i = -1;
	while (++i < data->n_philos)
	{
		if (pthread_join(pthread[i], NULL) != 0)
			return (ft_error(ERRJOIN));
		printf("thread closed\n");
	}
	free(pthread);
	return (0);
}
