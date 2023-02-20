/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:20:30 by framos-p          #+#    #+#             */
/*   Updated: 2023/02/20 16:17:27 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

#include <limits.h>

static int ft_atoi(char *str, int *valor)
{
    int i;
    int	resultado;
	int	signo;

    i = 0;
	resultado = 0;
	signo = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
				str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
	    signo = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		resultado = resultado * 10 + (str[i] - 48);
		i++;
	}
    *valor = resultado * signo;
    if ((resultado * signo) > INT_MAX || (resultado * signo) < INT_MIN)
        return (1);
	return (0);
}

int check_args(int argc, char **argv, t_data *data)
{
    if (argc > 6 || argc < 5)
		return (ft_error(ERARGS));
    if ((ft_atoi(argv[1], &data->n_philos) != 0) || \
     (ft_atoi(argv[2], &data->time_to_die) != 0) || \
     (ft_atoi(argv[3], &data->time_to_eat) != 0) || \
     (ft_atoi(argv[4], &data->time_to_sleep) != 0))
        return (ft_error(EINVALARG));
    if (data->n_philos < 1)
		return (ft_error(EINVALARG));
	if (data->time_to_die < 0 || data->time_to_eat < 0 || \
		data->time_to_sleep < 0)
		return (ft_error(EINVALARG));
    data->n_times_ate = -1;
    if (argc == 6)
    {
        if (ft_atoi(argv[5], &data->n_times_ate) < 0)
            return (ft_error(EINVALARG));
    }
    data->dead = 0;
    return (0); 
}

