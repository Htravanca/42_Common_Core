/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:35:32 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/17 22:45:40 by hepereir         ###   ########.fr       */
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

// precise usleep
void	precise_usleep(size_t milliseconds)
{
	size_t	start;

	start = ft_current_timems();
	while (ft_current_timems() - start < milliseconds)
		usleep(500);
	return ;
}

// print a message in console
void	print_msg(char *msg, t_philos *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = ft_current_timems() - get_data()->start_time;
	if (!dead_loop(philo))
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
