/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:18:26 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/18 15:46:52 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_program(int ac, char **av, t_program	*table)
{
	table->nbr_of_philos = ft_atoi(av[1]);
	if (table->nbr_of_philos < 1)
	{
		printf("Invalid argument.\n");
		return (EXIT_FAILURE);
	}
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->nbr_of_times_to_eat = ft_atoi(av[5]);
	else
		table->nbr_of_times_to_eat = -1;
	table->did_philo_die = 0;
	table->start_time = 0;
	table->forks = init_forks(table);
	if (!table->forks)
		return (EXIT_FAILURE);
	pthread_mutex_init(&table->m_death, NULL);
	pthread_mutex_init(&table->m_meal, NULL);
	pthread_mutex_init(&table->m_lock, NULL);
	return (0);
}

t_fork	*init_forks(t_program *table)
{
	t_fork	*forks;
	int		i;

	forks = malloc(sizeof(t_fork) * table->nbr_of_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < table->nbr_of_philos)
	{
		forks[i].id = i;
		forks[i].status = 0;
		pthread_mutex_init(&forks[i].m_fork, NULL);
		i++;
	}
	return (forks);
}

int	init_philos(t_program *table)
{
	int			i;

	table->philos = malloc(sizeof(t_philo) * table->nbr_of_philos);
	if (!table->philos)
		return (EXIT_FAILURE);
	i = 0;
	while (i < table->nbr_of_philos)
	{
		table->philos[i] = populate_one_philo(i + 1, table);
		i++;
	}
	return (0);
}

t_philo	populate_one_philo(int index, t_program *table)
{
	t_philo	philo;

	philo.index = index;
	philo.table = table;
	philo.last_meal = 0;
	philo.nbr_times_eaten = 0;
	philo.right_fork = &table->forks[index - 1];
	philo.left_fork = &table->forks[index % table->nbr_of_philos];
	return (philo);
}
