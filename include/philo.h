/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:48:22 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/18 09:19:46 by libacchu         ###   ########.fr       */
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
# define FORK 11
# define EATING 12
# define SLEEPING 13
# define THINKING 14
# define DIED 15

typedef struct s_fork
{
	int				id;
	int				status;
	pthread_mutex_t	m_fork;
}	t_fork;

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
	t_fork			*fork;
}	t_program;

typedef struct s_philo
{
	int				index;
	int				last_meal;
	int				nbr_times_eaten;
	t_fork			*right_fork;
	t_fork			*left_fork;
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
long		ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_check_overflow(char *av);
size_t		ft_strlen(const char *str);

/*	print_msg.c	*/
void		print_msg(time_t start_time, int philo_id, int state_change);

/*	threads.c	*/
int			init_threads(t_program *table, t_philo *philos);
void		*routine(void *arg);

/*	background_threads.c	*/
void		init_background(t_program *table);
void		*bg_function(void *table);

#endif