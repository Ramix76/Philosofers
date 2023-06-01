/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:20:30 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/31 16:08:39 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines_bonus.h"

static long int	ft_atoi(char *str)
{
	int			i;
	long int	result;
	int			sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

static int	check_args(int argc, char **argv, t_data *data)
{
	data->n_philos = ft_atoi(argv[1]);
	if (data->n_philos <= 0 || data->n_philos > INT_MAX)
		return (1);
	data->time_to_die = ft_atoi(argv[2]);
	if (data->time_to_die <= 0 || data->time_to_die > INT_MAX)
		return (1);
	data->time_to_eat = ft_atoi(argv[3]);
	if (data->time_to_eat <= 0 || data->time_to_eat > INT_MAX)
		return (1);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->time_to_sleep <= 0 || data->time_to_sleep > INT_MAX)
		return (1);
	if (argc == 6)
	{
		data->n_times_ate = ft_atoi(argv[5]);
		if (data->n_times_ate <= 0 || data->n_times_ate > INT_MAX)
			return (1);
	}
	else
		data->n_times_ate = -1;
	data->dead = 0;
	return (0);
}

int	parsing(int argc, char **argv, t_data *data)
{
	if (argc > 6 || argc < 5)
		return (ft_error(ERARGS));
	if (check_args(argc, argv, data) != 0)
		return (ft_error(EINVALARG));
	return (0);
}
