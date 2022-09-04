/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:45:49 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/04 23:16:12 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->table->m_print_msg);
	print_msg((get_time_in_ms() - philo->table->start_time), \
				philo->index, "hello\n");
	pthread_mutex_unlock(&philo->table->m_print_msg);
	return ((void *)philo);
}

void	init_threads(t_program *table, t_philo *philos)
{
	int	i;

	i = 0;
	table->start_time = get_time_in_ms();
	table->thread = malloc(sizeof(pthread_t) * table->nbr_of_philos);
	pthread_mutex_init(&table->m_print_msg, NULL);
	while (i < table->nbr_of_philos)
	{
		if (pthread_create(&table->thread[i], NULL, &routine, &philos[i]))
			exit (EXIT_FAILURE);
		// usleep(1000);
		i++;
	}
	i = 0;
	while (i < table->nbr_of_philos)
	{
		if (pthread_join(table->thread[i], NULL))
			exit (EXIT_FAILURE);
		i++;
	}
	pthread_mutex_destroy(&table->m_print_msg);
}

void	*bg_function(void *table)
{
	while (1)
	{
		if (((t_program *)table)->did_philo_die == 0)
			break ;
	}
	//print massage that one died
	//exit clean
}

void	init_background(t_program *table)
{
	if (pthread_create(&table->thread_background, NULL, &bg_function, &table))
		exit (EXIT_FAILURE);
	if (pthread_detach(&table->thread_background))
		exit (EXIT_FAILURE);
	exit (0);
}
