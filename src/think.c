/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:02:51 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/20 15:53:31 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_think(t_program *table, t_philo *philo)
{
	// time_t	time_to_stop;

	// if (has_a_philo_died(philo))
	// 	return (1);
	// time_to_stop = 8;
	print_msg(table->start_time, philo->index, THINKING, table);
	// while ((get_time_in_ms() - philo->table->start_time) < time_to_stop)
	// {
	usleep(50);
	if (has_a_philo_died(philo))
		return (1);
	if (has_all_eaten(philo->table) == 1)
		return (1);
	// }
	return (0);
}
