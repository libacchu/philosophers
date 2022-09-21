/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:45:49 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/16 12:12:51 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	create_threads(t_program *table, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philos)
	{
		if (pthread_create(&table->thread[i], NULL, &routine, &philos[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (0);
}

int	join_threads(t_program *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philos)
	{
		if (pthread_join(table->thread[i], NULL))
			return (EXIT_FAILURE);
		i++;
	}
	return (0);
}

int	run_program(t_program *table, t_philo *philos)
{
	table->start_time = get_time_in_ms() + (table->nbr_of_philos * 20);
	table->thread = malloc(sizeof(pthread_t) * table->nbr_of_philos);
	pthread_mutex_init(&table->m_print_msg, NULL);
	if (create_threads(table, philos))
		return (EXIT_FAILURE);
	init_background(table);
	if (join_threads(table))
		return (EXIT_FAILURE);
	return (0);
}

// int	end_program(t_program *table, t_philo *philos)
// {
// 	if (join_threads(table))
// 		return (EXIT_FAILURE);
// 	pthread_mutex_destroy(&table->m_print_msg);
// }
