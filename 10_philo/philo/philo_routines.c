/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:58:53 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/17 22:43:45 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philos *philo)
{
	print_msg("is thinking", philo);
}

void	dream(t_philos *philo)
{
	print_msg("is sleeping", philo);
	precise_usleep(get_data()->time_to_sleep);
}

// eat routine, mutex lock fork R and L, sleep time_to_eat
int	eat(t_philos *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_msg("has taken a fork", philo);
	if (get_data()->num_philos == 1)
	{
		precise_usleep(get_data()->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return (-1);
	}
	print_msg("has taken a fork", philo);
	philo->eating = 1;
	print_msg("is eating", philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal_time = ft_current_timems();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	precise_usleep(get_data()->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}
