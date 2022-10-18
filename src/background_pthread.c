/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_pthread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:55:46 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/18 20:30:28 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_background(t_program *table)
{
	if (pthread_create(&table->thread_background, NULL, &bg_function, table))
		return (EXIT_FAILURE);
	if (pthread_join(table->thread_background, NULL))
		return (EXIT_FAILURE);
	return (0);
}

int	philo_died(t_philo *philo)
{
	time_t	current_time;

	// pthread_mutex_lock(&philo->table->m_death);
	current_time = get_time_in_ms() - philo->table->start_time;
	if ((current_time - philo->last_meal) >= philo->table->time_to_die)
	{
		pthread_mutex_unlock(&philo->table->m_death);
		return (1);
	}
	// pthread_mutex_unlock(&philo->table->m_death);
	return (0);
}

int	has_all_eaten(t_program	*table)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	// pthread_mutex_lock(&table->m_meal);
	while (i < table->nbr_of_philos)
	{
		if (table->philos[i].nbr_times_eaten == table->nbr_of_times_to_eat)
			count++;
		i++;
	}
	// pthread_mutex_unlock(&table->m_meal);
	if (count == table->nbr_of_philos)
		return (1);
	else
		return (0);
}

void	*bg_function(void *arg)
{
	int			i;
	t_program	*table;

	table = (t_program *)arg;
	while (get_time_in_ms() < table->start_time)
		continue ;
	i = 0;
	while (table->did_philo_die == 0)
	{
		i = 0;
		while (i < table->nbr_of_philos)
		{
			pthread_mutex_lock(&table->m_death);
			pthread_mutex_lock(&table->m_meal);
			if (philo_died(&table->philos[i]) == 1)
			{
				pthread_mutex_lock(&table->m_lock);
				table->did_philo_die = 1;
				printf("%lu %d died\n", \
					(get_time_in_ms() - table->start_time) - \
					table->philos[i].last_meal, table->philos[i].index);
				pthread_mutex_unlock(&table->m_lock);
				break ;
			}
			if (has_all_eaten(table) != 0)
				break ;
			pthread_mutex_unlock(&table->m_death);
			pthread_mutex_unlock(&table->m_meal);
			i++;
		}
	}
	return (NULL);
}
