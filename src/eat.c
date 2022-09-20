/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:50:01 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/13 20:43:41 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eat(t_program *table, time_t amt_time_to_eat)
{
	time_t	time_to_stop;

	(void)table;
	time_to_stop = get_time_in_ms() + amt_time_to_eat;
	while (get_time_in_ms() < time_to_stop)
	{
		if (table->did_philo_die)
			break ;
		usleep(50);
	}
}
