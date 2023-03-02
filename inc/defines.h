/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:14:04 by framos-p          #+#    #+#             */
/*   Updated: 2023/03/02 17:01:42 by framos-p         ###   ########.fr       */
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

/* MAIN.c */
int				main(int argc, char **argv);
/* ARGS.c */
int				check_args(int argc, char **argv, t_data *data);
/* UTILS.c */
long long int   time_stamp(void);
int				ft_error(int error);
/* CLEAN_AND_DESTROY.c */
int				cleanning(t_data *data, int detroy, int error);
/* MUTEX_CONTROL.c */
int     		lock(t_data *data);
int     		unlock(t_data *data);
int			    join(t_data *data, pthread_t *pthread);
/* INITS.c */
int				init_philos(t_data *data);
int 			init_mutexes(t_data *data);
/* THREADS.c */
int 			create_threads(t_data *data);
void   			*routine(t_data *data);

#endif
