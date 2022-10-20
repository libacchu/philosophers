/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:02:51 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/20 16:06:15 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_think(t_program *table, t_philo *philo)
{
	print_msg(table->start_time, philo->index, THINKING, table);
	usleep(50);
	if (has_a_philo_died(philo))
		return (1);
	if (has_all_eaten(philo->table) == 1)
		return (1);
	return (0);
}
