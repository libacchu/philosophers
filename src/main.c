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
	// t_philo		*philos;

	if (input_handler(ac, av))
		return (EXIT_FAILURE);
	table = init_program(ac, av);
	(void)table;
	table->philos = init_philos(table);
	// init_background(table);
	init_threads(table, table->philos);
	// end_program(table, philos);

	// free(table);
	return (0);
}
