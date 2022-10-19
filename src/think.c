/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:02:51 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/19 19:10:35 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_think(t_program *table, t_philo *philo)
{
	if (has_a_philo_died(philo))
		return (1);
	print_msg(table->start_time, philo->index, THINKING, table);
	if (has_a_philo_died(philo))
		return (1);
	if (has_all_eaten(philo->table) == 1)
		return (1);
	return (0);
}
