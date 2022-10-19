/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:20:09 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/19 19:05:40 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO STRUCT_H

# include "philo.h"

typedef struct s_philo	t_philo;

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
	int				did_all_eat;
	time_t			start_time;
	pthread_t		thread_background;
	pthread_t		*thread;
	t_philo			*philos;
	t_fork			*forks;
	pthread_mutex_t	m_print_msg;
	pthread_mutex_t	m_death;
	pthread_mutex_t	m_meal;
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

#endif
