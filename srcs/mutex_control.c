/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:09:56 by framos-p          #+#    #+#             */
/*   Updated: 2023/03/02 17:16:39 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

int     lock(t_data *data)
{
    if (pthread_mutex_lock(&data->death) < 0)
        return (ft_error(EMUTLOCK));
    if (pthread_mutex_lock(&data->print) < 0)
        return (ft_error(EMUTLOCK));
    return (0);
}

int     unlock(t_data *data)
{
    if (pthread_mutex_unlock(&data->death) < 0)
        return (ft_error(EMUTUNLOCK));
    if (pthread_mutex_unlock(&data->print) < 0)
        return (ft_error(EMUTUNLOCK));
    return (0);
}
    
int     join(t_data *data, pthread_t *pthread)
{
    int i;
    
    i = 0;
    while (i < data->n_philos)
    {
        if (pthread_join(pthread[i], NULL) != 0)
        {
            return (ft_error(ERRJOIN));
        }
        printf("thread closed\n");
        i++;
    }
    return (0);
}