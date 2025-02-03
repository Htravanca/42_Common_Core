/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:43:52 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/03 21:44:08 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <pthread.h>
# include <stdio.h>

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	int				someone_died;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
}					t_data;

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	long long		last_meal_time;
	int				meals_eaten;
	struct s_data	*data;
}					t_philosopher;

// DEBUG
void				print_data(void);

// INIT DATA
t_data				*get_data(void);
int					ft_init_data(int argc, char **argv);

//UTILS
void	free_bf_exit(void);

#endif