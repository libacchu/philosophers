/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:29:07 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/04 22:29:32 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_msg(time_t time, int philo_id, char *msg)
{
	// if (time && philo_id && msg)
		printf("%lu %d %s", time, philo_id, msg);
}
