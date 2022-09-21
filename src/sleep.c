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

int	philo_sleep(t_philo *philo, t_program *table)
{
	time_t	time_to_wake_up;

	time_to_wake_up = get_time_in_ms() + table->time_to_sleep;
	if (table->did_philo_die != 0)
		return (1);
	print_msg(table->start_time, philo->index, SLEEPING, table);
	while (get_time_in_ms() < time_to_wake_up)
	{
		if (table->did_philo_die)
			break ;
		usleep(50);
	}
	return (0);
}
