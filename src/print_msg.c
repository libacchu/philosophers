/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:29:07 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/16 13:46:49 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_msg(time_t start_time, int philo_id, int state_change)
{
	time_t	current_time;

	current_time = get_time_in_ms() - start_time;
	if (state_change == FORK)
		printf("%lu %d has taken a fork\n", current_time, philo_id);
	if (state_change == EATING)
		printf("%lu %d is eating\n", current_time, philo_id);
	if (state_change == SLEEPING)
		printf("%lu %d is sleeping\n", current_time, philo_id);
	if (state_change == THINKING)
		printf("%lu %d is thinking\n", current_time, philo_id);
	if (state_change == DIED)
		printf("%lu %d died\n", time, philo_id);
}
