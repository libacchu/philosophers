/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:02:51 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/18 10:37:42 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
	// time_to_think = 10;
	
	// printf("\n----- time to think \t %ld\n", time_to_think);
	// printf("----- time to die \t %ld\n", table->time_to_die);
	// printf("----- lst meal \t\t %ld\n", philo->last_meal);
	// printf("----- time to eat \t %ld\n", table->time_to_eat);
	// printf("----- get time ms \t %ld\n\n", get_time_in_ms() - philo->table->start_time);

int	philo_think(t_program *table, t_philo *philo)
{
	time_t	time_to_think;
	time_t	time_to_stop;

	time_to_think = (((get_time_in_ms() - philo->table->start_time) \
		- philo->last_meal) / 2);
	if (time_to_think > 200)
		time_to_think = 200;
	if (time_to_think > table->time_to_die)
		time_to_think = 0;
	if (philo->table->did_philo_die != 0)
		return (1);
	print_msg(table->start_time, philo->index, THINKING, table);
	time_to_stop = get_time_in_ms() + time_to_think;
	while (get_time_in_ms() < time_to_stop)
	{
		if (table->did_philo_die)
			return (1);
		usleep(10);
	}
	return (0);
}

