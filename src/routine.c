/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:12:10 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/19 19:37:48 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	one_philo(t_program *table)
{
	int	flag;

	flag = 0;
	if (table->nbr_of_philos == 1)
	{
		flag = 1;
		printf("0 1 has taken a fork\n");
	}
	return (flag);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (get_time_in_ms() < philo->table->start_time)
		continue ;
	pthread_mutex_lock(&philo->table->m_meal);
	philo->last_meal = get_time_in_ms() - philo->table->start_time;
	pthread_mutex_unlock(&philo->table->m_meal);
	if (one_philo(philo->table))
		return (NULL);
	if (philo->index % 2 == 1)
		philo_think(philo->table, philo);
	while (has_a_philo_died(philo) == 0)
	{
		if (philo_eat(philo, philo->table->time_to_eat))
			break ;
		if (philo_sleep(philo, philo->table))
			break ;
		if (philo_think(philo->table, philo))
			break ;
	}
	return (NULL);
}
