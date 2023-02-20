/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:17:42 by framos-p          #+#    #+#             */
/*   Updated: 2023/02/20 12:38:58 by framos-p         ###   ########.fr       */
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
/*
1	EOUTMEM			Out of memory
2	EINVAL			The value specified by mutex is invalid
3   ERARGS          Invalid number of arguments
4   EINVALARG       Invalid argument
5   EINVALTIME      Invalid time pass
6	ECANCELED       Operation canceled
7   EINIT_MUTEX     Fail on mutex initialitation
*/

#endif
