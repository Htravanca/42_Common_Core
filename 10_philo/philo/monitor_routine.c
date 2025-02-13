/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:06:03 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/13 16:35:07 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// Checks if the philosopher is dead
int	philosopher_dead(t_philos *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (ft_current_timems() - philo->last_meal_time >= get_data()->time_to_die)//&& philo->eating == 0)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (-1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

// Check if any philo died
int	check_if_dead(t_philos *philo)
{
	int	i;

	i = 0;
	while (i < get_data()->num_philos)
	{
		if (philosopher_dead(&philo[i]) == -1)
		{
			print_msg("died", &philo[i]);
			pthread_mutex_lock(philo->dead_lock);
			get_data()->someone_died = 1;
			pthread_mutex_unlock(philo->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

// Checks if all the philos ate the num_of_meals
/* int	check_if_all_ate(t_philos *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos[0].num_times_to_eat == -1)
		return (0);
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].num_times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (finished_eating == philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
} */

void	*monitor_routine(void *pointer)
{
	t_philos	*philos;

	philos = (t_philos *)pointer;
	while (1)
		if (check_if_dead(philos) == 1)// || check_if_all_ate(philos) == 1)
			break ;
	return (pointer);
}
