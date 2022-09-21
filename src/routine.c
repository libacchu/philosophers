/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:12:10 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/16 12:57:19 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (get_time_in_ms() < philo->table->start_time)
		continue ;
	philo->last_meal = get_time_in_ms() - philo->table->start_time;
	if (philo->index % 2 == 1)
		philo_think(philo->table, philo);
	while (philo->table->did_philo_die == 0)
	{
		if (philo_eat(philo, philo->table->time_to_eat))
			break ;
		if (philo->nbr_times_eaten == philo->table->nbr_of_times_to_eat)
			break ;
		if (philo_sleep(philo, philo->table))
			break ;
		if (philo_think(philo->table, philo))
			break ;
	}
	return ((void *)philo);
}
