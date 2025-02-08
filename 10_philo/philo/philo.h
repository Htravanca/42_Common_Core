/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:43:52 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/08 22:23:49 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX 200

typedef struct s_philos
{
	int				id;				// init
	pthread_t		thread;
	int				meals_eaten;	// init
	int				num_meals;		// init
	bool			*someone_died;	// init
	size_t			start_time;		// init
	size_t			last_meal_time;	// init
	int				time_to_die;	// init
	int				time_to_eat;	// init
	int				time_to_sleep;	// init
	pthread_mutex_t	*write_lock;	// init
	pthread_mutex_t	*dead_lock;		// init
	pthread_mutex_t	*meal_lock;		// init
	pthread_mutex_t	*r_fork;		// init
	pthread_mutex_t	*l_fork;		// init
}					t_philos;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	bool			someone_died;
	pthread_mutex_t	dead_lock;	//used to write in someone_died
	pthread_mutex_t	meal_lock;	//check if a philo is dead
	pthread_mutex_t	write_lock;	//used to write to console
	t_philos		*philos;
}					t_data;

// DEBUG
void				print_data(void);

// INIT DATA
t_data				*get_data(void);
int					ft_init_data(int argc, char **argv, t_philos *philos);

// INIT PHILOS
void				init_philos(pthread_mutex_t *forks);

// INIT THREADS
void				init_threads(pthread_mutex_t *forks);

// UTILS
size_t				get_current_time(void);
void				precise_usleep(size_t milliseconds);
void				print_msg(char *msg, t_philos *philo);

#endif