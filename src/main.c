/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:40:21 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/19 19:07:03 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_program	table;

	if (input_handler(ac, av))
		return (EXIT_FAILURE);
	if (init_program(ac, av, &table))
		return (EXIT_FAILURE);
	if (init_philos(&table))
		return (EXIT_FAILURE);
	if (run_program(&table, (&table)->philos))
		return (EXIT_FAILURE);
	ft_free_table(&table);
	return (0);
}
