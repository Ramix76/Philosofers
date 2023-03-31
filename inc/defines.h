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
	long int		num;
	long int		eat_counter;
	long int		time_last_meal;
	long int		right_fork;
	long int		left_fork;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	long int			n_philos;
	long int			time_start;
	long int			time_to_die;
	long int			time_to_eat;
	long int			time_to_sleep;
	long int			dead;
	long int			n_times_ate;
	pthread_mutex_t		death;
	pthread_mutex_t		print;
	pthread_mutex_t		*forks;
	t_philo				*philo;
}	t_data;

# define GRAB_LEFT	0
# define GRAB_RIGHT	1
# define EAT		2
# define SLEEP		3
# define THINK		4
# define DIE		5

/* MAIN.c */
int				main(int argc, char **argv);
/* ARGS.c */
int				parsing(int argc, char **argv, t_data *data);
/* UTILS.c */
long long int   time_stamp(void);
int				ft_error(int error);
int				ft_usleep(int time);
/* CLEAN_AND_DESTROY.c */
int				cleanning(t_data *data, int detroy, int error);
/* MUTEX_CONTROL.c */
int     		lock(t_data *data);
int     		unlock(t_data *data);
int			    join_and_unlock(t_data *data, pthread_t *pthread);
/* INITS.c */
int				init_philos(t_data *data);
int 			init_mutexes(t_data *data);
/* THREADS.c */
int 			create_threads(t_data *data);
void   			*routine(void *arg);
/* ACTIONS.c */
int				eat(t_philo *philo);
int 			sleep(t_philo *philo);
int 			think(t_philo *philo);
/* PRINT_ACTIONS.c */
int print_action_taken(t_philo *philo, int action);

#endif
