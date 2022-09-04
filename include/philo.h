/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:48:22 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/04 22:58:31 by libacchu         ###   ########.fr       */
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
	pthread_t		*thread;
	pthread_t		thread_background;
}	t_program;

typedef struct s_philo
{
	int				index;
	int				last_meal;
	int				fork;
	pthread_mutex_t	m_fork;
	t_program		*table;
}	t_philo;

/*	init_struct.c	*/
t_program	*init_program(int ac, char **av);
t_philo		*init_philos(t_program *table);
t_philo		populate_one_philo(int index, t_program *table);

/*	input_handler.c	*/
int			input_handler(int ac, char **av);
int			amt_of_args(int ac);
int			check_if_input_are_digits(int ac, char **av);

/*	get_time.c	*/
time_t		get_time_in_ms(void);

/*	sleep.c */
void		philo_sleep(t_program *table, time_t amt_time_to_sleep);

/*	Utils.c	*/
int			ft_atoi(const char *str);
int			ft_isdigit(int c);

/*	print_msg.c	*/
void		print_msg(time_t time, int philo_id, char *msg);

/*	threads.c	*/
void		init_threads(t_program *table, t_philo *philos);
void		*routine(void *arg);

#endif