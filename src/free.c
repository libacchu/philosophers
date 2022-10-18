/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:36:29 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/17 19:02:51 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_and_destroy_forks(t_program *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philos)
	{
		pthread_mutex_destroy(&table->forks[i].m_fork);
		i++;
	}
	free(table->forks);
}

void	ft_free_table(t_program *table)
{
	if (table->forks)
		free_and_destroy_forks(table);
	if (table->philos)
		free(table->philos);
	if (table->thread)
		free(table->thread);
	pthread_mutex_destroy(&table->m_print_msg);
}
