/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_destroy_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:32:13 by framos-p          #+#    #+#             */
/*   Updated: 2023/04/06 17:22:17 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines_bonus.h"

int	cleanning(t_data *data)
{
	if (data->philo)
		free(data->philo);
	free(data);
	return (0);
}
