/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_pthread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:55:46 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/08 21:35:53 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_background(t_program *table)
{
	printf("--- init background ---\n");
	if (pthread_create(&table->thread_background, NULL, &bg_function, table))
		exit (EXIT_FAILURE);
	if (pthread_join(table->thread_background, NULL))
		exit (EXIT_FAILURE);
	printf("--- HERE background ---\n");
}

int	philo_died(t_philo *philo)
{
	time_t	current_time;

	current_time = get_time_in_ms() - philo->table->start_time;
	// printf("----HERE = %lu\n", current_time - philo->last_meal);
	if ((current_time - philo->last_meal) >= philo->table->time_to_die)
	{
		return (1);
	}
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
	// printf("----------------------------------------------\n");
	// printf("table->did_philo_die = %d\n", table->did_philo_die);
	while (table->did_philo_die == 0)
	{
		// usleep(555555);
		i = 0;
		while (i < table->nbr_of_philos)
		{
			if (philo_died(&table->philos[i]) == 1)
			{
				table->did_philo_die = 1;
				printf("%lu %d died\n", \
					(get_time_in_ms() - table->start_time) - \
					table->philos[i].last_meal, table->philos[i].index);
				break ;
			}
			i++;
		}
	}
	printf("--- background ended ---\n");
	//print massage that one died
	//exit clean
	return (NULL);
}

