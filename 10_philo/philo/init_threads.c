/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:35:32 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/23 18:42:25 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ft to stop philo threads when one die
int	ft_dead_loop(t_philos *philos)
{
	pthread_mutex_lock(philos->dead_lock);
	if (*philos->someone_died == true)
		return (pthread_mutex_unlock(philos->dead_lock), -1);
	pthread_mutex_unlock(philos->dead_lock);
	return (0);
}

//ft to handle 1 philo case
void	ft_one_philo(t_philos *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_print_msg("has taken a fork", philo);
	ft_precise_sleep(get_data()->time_to_die, philo);
	pthread_mutex_unlock(philo->r_fork);
}

// routine of each thread philo
void	*ft_table(void *data)
{
	t_philos	*philo;

	philo = (t_philos *)data;
	if (get_data()->num_philos == 1)
		return (ft_one_philo(philo), data);
	if (philo->id % 2 == 0)
		ft_precise_sleep(1, philo);
	while (ft_dead_loop(philo) == 0)
	{
		eat(philo);
		snooze(philo);
		think(philo);
	}
	return (data);
}

//update last_meal_time
static void ft_update_lmt(void)
{
	int i;

	i = 0;
	while (i < get_data()->num_philos)
	{
		get_data()->philos[i].last_meal_time = get_data()->start_time;
		i++;
	}
	return ;
}

// ft to manage the init of all threads
void	ft_init_threads(pthread_mutex_t *forks)
{
	pthread_t	monitor;

	monitor = 0;
	get_data()->start_time = ft_current_timems();
	ft_update_lmt();
	if (ft_initmonitorthread(forks, &monitor) == -1)
		return ;
	if (ft_initphilothread(forks) == -1)
		return ;
	if (ft_joinmonitorthread(forks, monitor) == -1)
		return ;
	if (ft_joinphilothread(forks) == -1)
		return ;
}
