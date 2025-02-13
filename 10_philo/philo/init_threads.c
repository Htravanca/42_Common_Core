/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:35:32 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/13 17:16:58 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//ft  to stop philo threads when one die
int	dead_loop(t_philos *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->someone_died == true)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

//routine of each thread philo
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

//ft to manage the init of all threads
void	init_threads(pthread_mutex_t *forks)
{
	pthread_t	monitor;

	monitor = 0;
	get_data()->start_time = ft_current_timems();
	if (ft_initmonitorthread(forks, &monitor) == -1)
		return ;
	if (ft_initphilothread(forks) == -1)
		return ;
	if (ft_joinmonitorthread(forks, monitor) == -1)
		return ;
	if (ft_joinphilothread(forks) == -1)
		return ;
}
