/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:29:07 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/20 15:05:55 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_msg(time_t start_time, int philo_id, \
			int state_change, t_program *table)
{
	time_t	current_time;

	current_time = get_time_in_ms() - start_time;
	if (has_a_philo_died(table->philos) == 0)
	{
		pthread_mutex_lock(&table->m_print_msg);
		if (state_change == FORK)
			printf("%lu %d has taken a fork\n", current_time, philo_id);
		else if (state_change == EATING)
			printf("%lu %d is eating\n", current_time, philo_id);
		else if (state_change == SLEEPING)
			printf("%lu %d is sleeping\n", current_time, philo_id);
		else if (state_change == THINKING)
			printf("%lu %d is thinking\n", current_time, philo_id);
		pthread_mutex_unlock(&table->m_print_msg);
	}
	if (state_change == DIED)
	{
		pthread_mutex_lock(&table->m_print_msg);
		printf("%lu %d died\n", current_time, philo_id);
		pthread_mutex_unlock(&table->m_print_msg);
	}
}
