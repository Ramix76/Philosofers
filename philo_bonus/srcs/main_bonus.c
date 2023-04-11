/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:51:47 by framos-p          #+#    #+#             */
/*   Updated: 2023/04/11 11:17:46 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (ft_error(EOUTMEM));
	if (parsing(argc, argv, data) != 0)
	{
		free(data);
		return (1);
	}
	if (init_philos(data) != 0)
		return (cleanning(data));
	if (init_semaphores(data) != 0)
		return (cleanning(data));
	if (create_processes(data) != 0)
		return (cleanning(data));
	return (cleanning(data));
}
