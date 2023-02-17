/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:14:04 by framos-p          #+#    #+#             */
/*   Updated: 2023/02/17 18:15:15 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include "errors.h"

typedef struct s_data
{
	int					time_start;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					n_times_ate;
	pthread_mutex_t		start;
	char				dead;
}	t_data;

typedef struct s_philo
{
	int				num;
	int				eat_counter;
	int				last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}	t_philo;

typedef struct s_table
{
	int					n_philos;
	t_data			*data;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_table;

int		main(int argc, char **argv);
int		check_args(int argc, char **argv, t_table *table);
int		ft_error(int error);
int		init_philos(t_table *table);
int init_mutexes(t_table *table);

#endif
