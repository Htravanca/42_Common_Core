/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:58:53 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/21 20:26:58 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//think routine, just a msg
void	think(t_philos *philo)
{
	ft_print_msg("is thinking", philo);
}

//sleping routine, message and then sleep time_to_sleep
void	snooze(t_philos *philo)
{
	ft_print_msg("is sleeping", philo);
	ft_precise_sleep(get_data()->time_to_sleep, philo);
}

// eat routine, mutex lock fork R and L, sleep time_to_eat
int	eat(t_philos *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_print_msg("has taken a fork", philo);
	if (get_data()->num_philos == 1)
	{
		ft_precise_sleep(get_data()->time_to_die, philo);
		pthread_mutex_unlock(philo->l_fork);
		return (-1);
	}
	pthread_mutex_lock(philo->l_fork);
	ft_print_msg("has taken a fork", philo);
	pthread_mutex_lock(philo->meal_lock);
	ft_print_msg("is eating", philo);
	philo->eating = 1;
	philo->last_meal_time = ft_current_timems();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_precise_sleep(get_data()->time_to_eat, philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->eating = 0;
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (0);
}
