/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:45:49 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/18 19:17:30 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	run_program(t_program *table, t_philo *philos)
{
	table->start_time = get_time_in_ms() + (table->nbr_of_philos * 20);
	table->thread = malloc(sizeof(pthread_t) * table->nbr_of_philos);
	if (!table->thread)
		return (EXIT_FAILURE);
	pthread_mutex_init(&table->m_print_msg, NULL);
	if (create_threads(table, philos))
		return (EXIT_FAILURE);
	if (init_background(table))
		return (EXIT_FAILURE);
	if (join_threads(table))
		return (EXIT_FAILURE);
	return (0);
}

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
