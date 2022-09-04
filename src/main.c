/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:40:21 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/03 18:10:45 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
		while(av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				return (INVALID_INPUT);
			j++;
		}
		i++;
	}
	return (0);
}

int	input_handler(int ac, char **av)
{
	if (amt_of_args(ac) != 0)
		return (INVALID_INPUT);
	if (check_if_input_are_digits(ac, av) != 0)
		return (INVALID_INPUT);
	return (0);
}

t_program *init_program(int ac, char **av)
{
	t_program	*table;
	
	table = malloc(sizeof(t_program));
	table->nbr_of_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->nbr_of_times_to_eat = ft_atoi(av[5]);
	else
		table->nbr_of_times_to_eat = 0;
	return (table);
}

t_philo populate_one_philo(int index, t_program *table)
{
	t_philo	philo;

	philo.index = index;
	philo.table = table;
	return (philo);
}

t_philo	*init_philos(t_program *table)
{
	t_philo		*philos;
	int			i;

	philos = malloc(sizeof(t_philo) * table->nbr_of_philos);
	if (!philos)
		return (0);
	i = 0;
	while (i < table->nbr_of_philos)
	{
		philos[i] = populate_one_philo(i + 1, table);
		i++;
	}
	return (philos);
}

int	main(int ac, char **av)
{
	t_program 	*table;
	t_philo		*philos;
	time_t		start = 0;
	// time_t		end;
	
	if (input_handler(ac, av))
	{
		write(1, "Invalid argument.\n", 18);
		return (INVALID_INPUT);
	}
	// gettimeofday(start, NULL);
	// printf("strat = %ld\n", start);
	table = init_program(ac, av);
	philos = init_philos(table);
	printf("index = %d\n", philos[0].index);
	printf("table->nbr_of_philos = %d\n", table->nbr_of_philos);
	printf("table->time_to_die = %d\n", table->time_to_die);
	printf("table->time_to_eat = %d\n", table->time_to_eat);
	printf("table->time_to_sleep = %d\n", table->time_to_sleep);
	printf("table->nbr_of_times_to_eat = %d\n", table->nbr_of_times_to_eat);
	
	free(table);
	return (0);
}
