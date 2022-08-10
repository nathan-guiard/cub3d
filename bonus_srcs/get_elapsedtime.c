/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elapsedtime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:33:41 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/10 22:07:00 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

unsigned long long	get_elapsedtime(unsigned long long base)
{
	struct timeval				time;

	gettimeofday(&time, NULL);
	return (time.tv_sec - base);
}
