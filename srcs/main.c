/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:51:47 by framos-p          #+#    #+#             */
/*   Updated: 2023/03/02 16:58:15 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	//int		i;
	
	data = malloc(sizeof(data));
	if (data == NULL)
		return (ft_error(EOUTMEM));
	if (check_args(argc, argv, data) != 0)
	{
		free(data);
		return (1);	
	}
	if (init_philos(data) != 0)
		return (cleanning(data, 1 , 1));
	if (init_mutexes(data) != 0)
		return (cleanning(data, 0, 1));
	data->time_start = time_stamp();
	if (data->time_start == -1)
		return (cleanning(data, 1 , 1));
	if (create_threads(data) != 0)
		return (cleanning(data, 1, 1));
	return (cleanning(data, 1, 0));
}