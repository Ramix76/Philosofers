/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:17:42 by framos-p          #+#    #+#             */
/*   Updated: 2023/03/02 15:44:54 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define    EOUTMEM     1
# define    EINVAL      2
# define    ERARGS      3
# define    EINVALARG   4
# define    EINVALTIME  5
# define    ECANCELED	6
# define    EINIT_MUTEX 7
# define    E_CREATE_TH 8
# define    EMUTLOCK    9
# define    EMUTUNLOCK  10
# define    ERRJOIN     11
# define    ERRTIME     12
# define    ERRDEST     13
/*
1	EOUTMEM			Out of memory
2	EINVAL			The value specified by mutex is invalid
3   ERARGS          Invalid number of arguments
4   EINVALARG       Invalid argument
5   EINVALTIME      Invalid time pass
6	ECANCELED       Operation canceled
7   EINIT_MUTEX     Error on mutex initialitation
8   E_CREATE_TH     Error on creating a thread
9   EMUTLOCK        Error locking the mutex
10  EMUTUNLOCK      Error unlocking the mutex
11  ERRJOIN         Error cloding the thread
12  ERRTIME         Error getting the time
13  ERRDEST         Error destrying mutex
*/

#endif
