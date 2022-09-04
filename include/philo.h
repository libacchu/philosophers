/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:48:22 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/03 19:06:18 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

# define INVALID_INPUT 1
typedef struct s_program
{
	int				nbr_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_times_to_eat;
	int				did_philo_die;
	time_t			start_time;
	pthread_mutex_t	m_print_msg;
	pthread_mutex_t	m_supervisor;
	pthread_mutex_t	*m_fork;
	pthread_t	*thread;
}	t_program;

typedef struct s_philo
{
	int				index;
	int				last_meal;
	int				fork;
	t_program		*table;
}	t_philo;

int		input_handler(int ac, char **av);

/*	Utils.c	*/
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif