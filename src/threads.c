/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:45:49 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/08 21:45:15 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
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

int	init_threads(t_program *table, t_philo *philos)
{
	table->start_time = get_time_in_ms();
	table->thread = malloc(sizeof(pthread_t) * table->nbr_of_philos);
	pthread_mutex_init(&table->m_print_msg, NULL);
	if (create_threads(table, philos))
		return (EXIT_FAILURE);
	if (join_threads(table))
		return (EXIT_FAILURE);
	pthread_mutex_destroy(&table->m_print_msg);
	return (0);
}
