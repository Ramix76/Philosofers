/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:51:47 by framos-p          #+#    #+#             */
/*   Updated: 2023/02/23 17:20:57 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	//int		i;
	
	data = malloc(sizeof(data));
	if (data == NULL)
		return (EOUTMEM);
	check_args(argc, argv, data);
	init_philos(data);
	init_mutexes(data);
	create_threads(data);
	return (0);
}