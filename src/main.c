/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:40:21 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/16 12:51:31 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_program	*table;
	t_philo		*philos;

	if (input_handler(ac, av))
	{
		write(1, "Invalid argument.\n", 18);
		return (INVALID_INPUT);
	}
	table = init_program(ac, av);
	philos = init_philos(table);
	init_background(table);
	init_threads(table, philos);

	free(table);
	return (0);
}
