/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:02:51 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/16 13:47:35 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_think(t_program *table, t_philo *philo)
{
	time_t	time_to_think;

	time_to_think = (table->time_to_die - (get_time_in_ms() - philo->last_meal) \
						- table->time_to_eat) / 2;
	if (time_to_think > 200)
		time_to_think = 200;
	if (philo->table->did_philo_die != 0)
		return (1);
	print_msg(table->start_time, philo->index, THINKING, table);
	while (get_time_in_ms() < time_to_think)
	{
		if (table->did_philo_die)
			break ;
		usleep(50);
	}
	return (0);
}
