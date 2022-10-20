/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:17:11 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/19 21:02:19 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	input_handler(int ac, char **av)
{
	if (amt_of_args(ac) != 0)
	{
		printf("Invalid amount of arguments.\n");
		return (EXIT_FAILURE);
	}
	if (check_if_input_are_digits(ac, av))
	{
		printf("Invalid argument.\n");
		return (EXIT_FAILURE);
	}
	if (ft_check_overflow(ac, av))
	{
		printf("Invalid integer.\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	amt_of_args(int ac)
{
	if (ac < 5 || ac > 6)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_overflow(int ac, char **av)
{
	long long	num;
	int			i;

	i = 1;
	while (i < ac)
	{	
		if (ft_strlen(av[i]) > 11)
			return (EXIT_FAILURE);
		num = ft_atoi(av[i]);
		if (num < -2147483648 || num > 2147483647)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	nbr_of_times_to_eat(int ac, char **av, t_program *table)
{
	if (ac == 6)
		table->nbr_of_times_to_eat = ft_atoi(av[5]);
	else
		table->nbr_of_times_to_eat = -1;
	if (table->nbr_of_times_to_eat == 0)
	{
		printf("Invalid argument.\n");
		return (EXIT_FAILURE);
	}
	return (0);
}
