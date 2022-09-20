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
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	philo->last_meal = philo->table->start_time;
	if (philo->index % 2)
		philo_think()
	while (i < 200)
	{
		pthread_mutex_lock(&philo->table->m_print_msg);
		print_msg((get_time_in_ms() - philo->table->start_time), \
					philo->index, "hello\n");
		pthread_mutex_unlock(&philo->table->m_print_msg);
		i++;
		usleep (99);
	}
	return ((void *)philo);
}
