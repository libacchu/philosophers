/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:50:01 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/19 19:40:55 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_eat(t_philo *philo, time_t amt_time_to_eat)
{
	if (has_a_philo_died(philo))
		return (1);
	philo_takes_forks(philo);
	if (has_a_philo_died(philo))
	{
		philo_drops_forks(philo);
		return (1);
	}
	if (philo_is_eating(philo, amt_time_to_eat))
		return (1);
	update_meal(philo);
	philo_drops_forks(philo);
	if (has_all_eaten(philo->table) == 1)
		return (1);
	return (0);
}

int	philo_is_eating(t_philo *philo, time_t amt_time_to_eat)
{
	time_t	time_to_stop;
	time_t	current_time;

	current_time = get_time_in_ms() - philo->table->start_time;
	time_to_stop = current_time + amt_time_to_eat;
	print_msg(philo->table->start_time, philo->index, EATING, philo->table);
	while ((get_time_in_ms() - philo->table->start_time) < time_to_stop)
	{
		if (has_a_philo_died(philo))
		{
			philo_drops_forks(philo);
			return (1);
		}
		usleep(100);
	}
	return (0);
}

void	update_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->m_meal);
	philo->last_meal = (get_time_in_ms() - philo->table->start_time);
	philo->nbr_times_eaten++;
	pthread_mutex_unlock(&philo->table->m_meal);
}

void	philo_takes_forks(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->right_fork->m_fork);
		print_msg(philo->table->start_time, philo->index, FORK, philo->table);
		pthread_mutex_lock(&philo->left_fork->m_fork);
		print_msg(philo->table->start_time, philo->index, FORK, philo->table);
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork->m_fork);
		print_msg(philo->table->start_time, philo->index, FORK, philo->table);
		pthread_mutex_lock(&philo->right_fork->m_fork);
		print_msg(philo->table->start_time, philo->index, FORK, philo->table);
	}
}

void	philo_drops_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->m_fork);
	pthread_mutex_unlock(&philo->right_fork->m_fork);
}
