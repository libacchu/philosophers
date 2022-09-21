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

int	philo_eat(t_philo *philo, time_t amt_time_to_eat)
{
	time_t	time_to_stop;

	if (philo->table->did_philo_die != 0)
		return (1);
	philo_takes_forks(philo);
	if (philo->table->did_philo_die != 0)
		return (1);
	time_to_stop = get_time_in_ms() + amt_time_to_eat;
	print_msg(philo->table->start_time, philo->index, EATING, philo->table);
	while (get_time_in_ms() < time_to_stop)
	{
		if (philo->table->did_philo_die)
			break ;
		usleep(10);
	}
	philo_drops_forks(philo);
	philo->last_meal = get_time_in_ms() - philo->table->start_time;
	philo->nbr_times_eaten++;
	return (0);
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
	// printf("philo %d dropped forks\n", philo->index);
}


