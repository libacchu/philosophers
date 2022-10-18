/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:12:10 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/18 20:19:45 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (get_time_in_ms() < philo->table->start_time)
		continue ;
	pthread_mutex_lock(&philo->table->m_death);
	philo->last_meal = get_time_in_ms() - philo->table->start_time;
	pthread_mutex_unlock(&philo->table->m_death);
	if (philo->index % 2 == 1)
		philo_think(philo->table, philo);
	while (1)
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
	return (NULL);
}
