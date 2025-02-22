/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:06:03 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/22 18:22:32 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Checks if the philosopher is dead
static int	ft_philo_dead(t_philos *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (ft_current_timems() - philo->last_meal_time >= get_data()->time_to_die
		&& philo->eating == 0)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (-1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

// Check if any philo died
static int	ft_check_dead(t_philos *philo)
{
	int	i;

	i = 0;
	while (i < get_data()->num_philos)
	{
		if (ft_philo_dead(&philo[i]) == -1)
		{
			ft_print_msg("died", &philo[i]);
			pthread_mutex_lock(philo->dead_lock);
			*philo->someone_died = true;
			pthread_mutex_unlock(philo->dead_lock);
			return (-1);
		}
		i++;
	}
	return (0);
}

// Checks if all the philos eat the meals
static int	ft_check_meals(t_philos *philo)
{
	int	i;
	int	philos_full;

	philos_full = 0;
	i = 0;
	if (get_data()->num_meals == -1)
		return (0);
	while (i < get_data()->num_philos)
	{
		pthread_mutex_lock(philo->meal_lock);
		if (philo[i].meals_eaten > philo[i].num_meals)
			philos_full++;
		pthread_mutex_unlock(philo->meal_lock);
		i++;
	}
	if (philos_full == get_data()->num_philos)
	{
		pthread_mutex_lock(philo->dead_lock);
		*philo->someone_died = true;
		pthread_mutex_unlock(philo->dead_lock);
		return (-1);
	}
	return (0);
}

//routine of monitor thread always checking if someone died 
//or all the meals have been eaten
void	*ft_monitor_routine(void *pointer)
{
	t_philos	*philos;

	philos = (t_philos *)pointer;
	while (1)
		if (ft_check_dead(philos) == -1 || ft_check_meals(philos) == -1)
			break ;
	return (pointer);
}
