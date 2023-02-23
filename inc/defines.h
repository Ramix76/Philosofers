/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:14:04 by framos-p          #+#    #+#             */
/*   Updated: 2023/02/23 18:16:39 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>
#include "errors.h"

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				num;
	int				eat_counter;
	int				time_last_meal;
	int				right_fork;
	int				left_fork;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int					n_philos;
	int					time_start;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					dead;
	int					n_times_ate;
	pthread_mutex_t		death;
	pthread_mutex_t		print;
	pthread_mutex_t		*forks;
	t_philo				*philo;
}	t_data;


int				main(int argc, char **argv);
int				check_args(int argc, char **argv, t_data *data);
int				ft_error(int error);
int				init_philos(t_data *data);
int 			init_mutexes(t_data *data);
long long int   time_stamp(void);
int 			create_threads(t_data *data);
void   			*routine(t_data *data);
int     		lock(t_data *data);
int     		unlock(t_data *data);
int			    join(t_data *data, pthread_t *pthread);

#endif
