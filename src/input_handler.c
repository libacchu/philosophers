/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:17:11 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/04 20:23:05 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	input_handler(int ac, char **av)
{
	if (amt_of_args(ac) != 0)
		return (INVALID_INPUT);
	if (check_if_input_are_digits(ac, av) != 0)
		return (INVALID_INPUT);
	return (0);
}

int	amt_of_args(int ac)
{
	if (ac < 5 || ac > 6)
		return (INVALID_INPUT);
	return (0);
}

int	check_if_input_are_digits(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				return (INVALID_INPUT);
			j++;
		}
		i++;
	}
	return (0);
}
