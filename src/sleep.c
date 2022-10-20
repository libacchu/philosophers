/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:06:03 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/20 15:31:46 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_sleep(t_philo *philo, t_program *table)
{
	time_t	time_to_wake_up;
	time_t	current_time;

	current_time = get_time_in_ms() - philo->table->start_time;
	time_to_wake_up = current_time + table->time_to_sleep;
	// if (has_a_philo_died(philo))
	// 	return (1);
	print_msg(table->start_time, philo->index, SLEEPING, table);
	if (table->time_to_sleep == 0)
		return (0);
	while ((get_time_in_ms() - philo->table->start_time) < time_to_wake_up)
	{
		if (has_a_philo_died(philo) == 1)
			return (1);
		if (has_all_eaten(philo->table) == 1)
			return (1);
		usleep(50);
	}
	return (0);
}
