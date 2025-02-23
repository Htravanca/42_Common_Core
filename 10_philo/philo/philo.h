/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:43:52 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/23 14:45:59 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX 200

typedef struct s_philos
{
	int				id;
	pthread_t		thread;
	int				meals_eaten;
	int				num_meals;
	size_t			last_meal_time;
	int				eating;
	bool			*someone_died;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	int				r_fork_id;
	int				l_fork_id;
}					t_philos;

typedef struct s_data
{
	int				num_philos;
	size_t			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	size_t			start_time;
	bool			someone_died;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philos		*philos;
}					t_data;

// DEBUG
void				print_data(void);

// INIT DATA
t_data				*get_data(void);
int					ft_init_data(int argc, char **argv, t_philos *philos);

// INIT PHILOS
void				ft_init_philos(pthread_mutex_t *forks);

// INIT THREADS AUX
int					ft_initmonitorthread(pthread_mutex_t *forks,
						pthread_t *monitor);
int					ft_initphilothread(pthread_mutex_t *forks);
int					ft_joinmonitorthread(pthread_mutex_t *forks,
						pthread_t monitor);
int					ft_joinphilothread(pthread_mutex_t *forks);

// INIT THREADS
int					ft_dead_loop(t_philos *philo);
void				*ft_table(void *data);
void				ft_init_threads(pthread_mutex_t *forks);

// PHILO ROUTINE
void				think(t_philos *philo);
void				snooze(t_philos *philo);
void				eat(t_philos *philo);

// MONITOR ROUTINE
void				*ft_monitor_routine(void *pointer);

// UTILS
size_t				ft_current_timems(void);
void				ft_precise_sleep(size_t milliseconds, t_philos *philo);
void				ft_print_msg(const char *msg, t_philos *philo);
void				ft_freebfexit(pthread_mutex_t *forks);

// UTILS LIBFT
int					ft_isalldigit(char *s);
int					ft_atoi(const char *nptr);

#endif