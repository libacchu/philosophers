/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:12:10 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/20 16:23:45 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	one_philo(t_program *table)
{
	int	flag;

	flag = 0;
	if (table->nbr_of_philos == 1)
	{
		flag = 1;
		printf("0 1 has taken a fork\n");
	}
	return (flag);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (one_philo(philo->table))
		return (NULL);
	if (philo->index % 2 == 1)
		usleep(philo->table->time_to_sleep * 1000);
	while (1)
	{
		if (philo_eat(philo, philo->table->time_to_eat))
			break ;
		if (philo_sleep(philo, philo->table))
			break ;
		if (philo_think(philo->table, philo))
			break ;
	}
	return (NULL);
}
