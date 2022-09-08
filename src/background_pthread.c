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
	if (pthread_create(&table->thread_background, NULL, &bg_function, &table))
		exit (EXIT_FAILURE);
	printf("--- HERE background ---\n");
	if (pthread_detach(table->thread_background))
		exit (EXIT_FAILURE);
}

void	*bg_function(void *table)
{
	int	i;

	i = 0;
	while (i < 200)
	{
		printf("--- background [%d] ---\n", i);
		if (((t_program *)table)->did_philo_die == 0)
			break ;
		usleep(100);
		i++;
		if (i == 5)
			((t_program *)table)->did_philo_die == 1;
	}
	printf("--- background ended ---\n");
	//print massage that one died
	//exit clean
	return (NULL);
}
