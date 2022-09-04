/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:06:03 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/03 18:37:50 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_sleep(t_program *table, time_t amt_time_to_sleep)
{
	time_t	time_to_wake;

	time_to_wake = get_time_in_ms() + amt_time_to_sleep;
	while (get_time_in_ms() < time_to_wake)
	{
		usleep(50);
	}
}