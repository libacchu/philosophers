/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:06:03 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/04 20:59:17 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_sleep(t_program *table, time_t amt_time_to_sleep)
{
	time_t	time_to_wake;

	(void)table;
	time_to_wake = get_time_in_ms() + amt_time_to_sleep;
	while (get_time_in_ms() < time_to_wake)
	{
		if (table->did_philo_die)
			break ;
		usleep(50);
	}
}
