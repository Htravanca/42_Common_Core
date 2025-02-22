/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:58:53 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/22 00:19:45 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// think routine, just a msg
void	think(t_philos *philo)
{
	ft_print_msg("is thinking", philo);
}

// sleping routine, message and then sleep time_to_sleep
void	snooze(t_philos *philo)
{
	ft_print_msg("is sleeping", philo);
	ft_precise_sleep(get_data()->time_to_sleep, philo);
}

//ft to order the forks, fixed: Lock order violation
void	ft_orderforks(pthread_mutex_t **first, pthread_mutex_t **second,
		t_philos *philo)
{
	if (philo->r_fork < philo->l_fork)
	{
		*first = philo->r_fork;
		*second = philo->l_fork;
	}
	else
	{
		*first = philo->l_fork;
		*second = philo->r_fork;
	}
}

// eat routine, mutex lock fork R and L, sleep time_to_eat
int	eat(t_philos *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	ft_orderforks(&first_fork, &second_fork, philo);
	pthread_mutex_lock(first_fork);
	ft_print_msg("has taken a fork", philo);
	pthread_mutex_lock(second_fork);
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
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
	return (0);
}
