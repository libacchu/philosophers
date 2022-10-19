/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_pthread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:55:46 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/19 19:04:41 by libacchu         ###   ########.fr       */
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

void	*bg_function(void *arg)
{
	int			i;
	t_program	*table;

	table = (t_program *)arg;
	while (get_time_in_ms() < table->start_time)
		continue ;
	i = 0;
	while (has_a_philo_died(table->philos) == 0)
	{
		i = 0;
		while (i < table->nbr_of_philos)
		{
			if (philo_died(&table->philos[i]) == 1)
			{
				pthread_mutex_lock(&table->m_death);
				table->did_philo_die = 1;
				pthread_mutex_unlock(&table->m_death);
				print_msg(table->start_time, i + 1, DIED, table);
				break ;
			}
			i++;
		}
		if (all_eaten(table) == 1)
			break ;
	}
	return (NULL);
}
