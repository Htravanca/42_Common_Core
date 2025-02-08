/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:35:32 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/08 20:09:31 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_loop(t_philos *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->someone_died == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void *table_routine(void *data)
{
	t_philos *philo;

	philo = (t_philos *)data;
	while (!dead_loop(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (NULL);
}

void	init_threads(pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while (i < get_data()->num_philos)
	{
		if (pthread_create(&get_data()->philos[i].thread, NULL, &table_routine, &get_data()->philos[i]) != 0)
			printf("error criating threads\n");//destory_all("Thread creation error", program, forks);
		i++;
	}
	i = 0;
	while (i < get_data()->num_philos)
	{
		if (pthread_join(&get_data()->philos[i].thread, NULL) != 0)
			printf("error join threads\n");//destory_all("Thread creation error", program, forks);
		i++;
	}
}
