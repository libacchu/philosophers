/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:29:50 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/20 14:28:36 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_died(t_philo *philo)
{
	time_t	current_time;
	int		status;

	status = 0;
	current_time = get_time_in_ms() - philo->table->start_time;
	pthread_mutex_lock(&philo->table->m_meal);
	// pthread_mutex_lock(&philo->table->m_death);
	// pthread_mutex_lock(&philo->table->m_lock);
	
	if ((current_time - philo->last_meal) >= philo->table->time_to_die)
	{
		// philo->table->did_philo_die = 1;
		status = 1;
	}
	// pthread_mutex_unlock(&philo->table->m_lock);
	// pthread_mutex_unlock(&philo->table->m_death);
	pthread_mutex_unlock(&philo->table->m_meal);
	return (status);
}

int	has_a_philo_died(t_philo *philos)
{
	int	status;

	status = 0;
	pthread_mutex_lock(&philos->table->m_death);
	if (philos->table->did_philo_die == 1)
		status = 1;
	pthread_mutex_unlock(&philos->table->m_death);
	return (status);
}

int	all_eaten(t_program	*table)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (table->nbr_of_times_to_eat == -1)
		return (0);
	while (i < table->nbr_of_philos)
	{
		pthread_mutex_lock(&table->m_meal);
		if (table->philos[i].nbr_times_eaten >= table->nbr_of_times_to_eat)
			count++;
		pthread_mutex_unlock(&table->m_meal);
		i++;
	}
	if (count == table->nbr_of_philos)
	{	
		pthread_mutex_lock(&table->m_meal);
		table->did_all_eat = 1;
		pthread_mutex_unlock(&table->m_meal);
		return (1);
	}
	return (0);
}

int	has_all_eaten(t_program	*table)
{
	int	status;

	status = 0;
	pthread_mutex_lock(&table->m_meal);
	if (table->did_all_eat == 1)
		status = 1;
	pthread_mutex_unlock(&table->m_meal);
	return (status);
}
