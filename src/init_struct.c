/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:18:26 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/12 12:47:55 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_program	*init_program(int ac, char **av)
{
	t_program	*table;

	table = malloc(sizeof(t_program));
	if (!table)
		return (NULL);
	table->nbr_of_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->nbr_of_times_to_eat = ft_atoi(av[5]);
	else
		table->nbr_of_times_to_eat = -1;
	table->did_philo_die = 0;
	table->forks = init_forks(table);
	return (table);
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

t_philo	*init_philos(t_program *table)
{
	t_philo		*philos;
	int			i;

	philos = malloc(sizeof(t_philo) * table->nbr_of_philos);
	if (!philos)
		return (0);
	i = 0;
	while (i < table->nbr_of_philos)
	{
		philos[i] = populate_one_philo(i + 1, table);
		i++;
	}
	return (philos);
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
