/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:51:47 by framos-p          #+#    #+#             */
/*   Updated: 2023/02/17 18:12:12 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

int	main(int argc, char **argv)
{
	t_table	table;
	
	check_args(argc, argv, &table);
	init_philos(&table);
	init_mutexes(&table);
	return (0);
}