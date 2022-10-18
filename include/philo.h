/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:48:22 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/17 18:59:04 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include "philo_struct.h"

# define INVALID_INPUT 1
# define FORK 11
# define EATING 12
# define SLEEPING 13
# define THINKING 14
# define DIED 15

/*	init_struct.c	*/
int			init_program(int ac, char **av, t_program *table);
int			init_philos(t_program *table);
t_philo		populate_one_philo(int index, t_program *table);
t_fork		*init_forks(t_program *table);

/*	input_handler.c	*/
int			input_handler(int ac, char **av);
int			amt_of_args(int ac);
int			check_if_input_are_digits(int ac, char **av);
int			ft_check_overflow(int ac, char **av);
int			nbr_of_philos(char **av);

/*	get_time.c	*/
time_t		get_time_in_ms(void);

/*	sleep.c */
int			philo_sleep(t_philo *philo, t_program *table);

/*	think.c */
int			philo_think(t_program *table, t_philo *philo);

/*	eat.c */
int			philo_eat(t_philo *philo, time_t amt_time_to_eat);
void		philo_takes_forks(t_philo *philo);
void		philo_drops_forks(t_philo *philo);

/*	print_msg.c	*/
void		print_msg(time_t start_time, int philo_id, \
			int state_change, t_program *table);

/*	threads.c	*/
int			run_program(t_program *table, t_philo *philos);
void		*routine(void *arg);
int			create_threads(t_program *table, t_philo *philos);
int			join_threads(t_program *table);

/*	background_threads.c	*/
int			init_background(t_program *table);
void		*bg_function(void *table);

/*	Utils.c	*/
long		ft_atoi(const char *str);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *str);

/* free.c */
void		ft_free_table(t_program *table);

#endif
