/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:35:32 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/23 13:21:28 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Gets the current time in milliseconds
// sec * 1000 = ms
// usec / 1000 = ms
size_t	ft_current_timems(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday() error\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

// precise usleep, each cycle sleep 0.5ms
void	ft_precise_sleep(size_t milliseconds, t_philos *philo)
{
	size_t	start;
	size_t	end;

	start = ft_current_timems();
	end = start + milliseconds;
	while (ft_current_timems() < end)
	{
		if (ft_dead_loop(philo) == -1)
			break ;
		usleep(500);
	}
	return ;
}

// print a message in console
void	ft_print_msg(const char *msg, t_philos *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = ft_current_timems() - get_data()->start_time;
	if (!ft_dead_loop(philo))
		printf("%zu %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->write_lock);
}

// free all stuff before exiting
void	ft_freebfexit(pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&get_data()->write_lock);
	pthread_mutex_destroy(&get_data()->meal_lock);
	pthread_mutex_destroy(&get_data()->dead_lock);
	while (i < get_data()->num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
