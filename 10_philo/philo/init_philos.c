/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:34:10 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/08 14:32:37 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//initializes the struct philos with start values
static void	init_philos_aux(pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < get_data()->num_philos)
	{
		get_data()->philos[i].id = i + 1;
		get_data()->philos[i].meals_eaten = 0;
		get_data()->philos[i].num_meals = get_data()->num_meals;
		get_data()->philos[i].someone_died = &get_data()->someone_died;
		get_data()->philos[i].start_time = get_current_time();
		get_data()->philos[i].last_meal_time = get_current_time();
		get_data()->philos[i].time_to_die = get_data()->time_to_die;
		get_data()->philos[i].time_to_eat = get_data()->time_to_eat;
		get_data()->philos[i].time_to_sleep = get_data()->time_to_sleep;
		get_data()->philos[i].write_lock = &get_data()->write_lock;
		get_data()->philos[i].dead_lock = &get_data()->dead_lock;
		get_data()->philos[i].meal_lock = &get_data()->meal_lock;
		get_data()->philos[i].r_fork = &forks[i];
		if (i == 0)
			get_data()->philos[i].l_fork = &forks[get_data()->num_philos - 1];
		else
			get_data()->philos[i].l_fork = &forks[i - 1];
		i++;
	}
}

// initializes how many forks as there are philos
void	init_philos(pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	pthread_mutex_init(&get_data()->write_lock, NULL);
	pthread_mutex_init(&get_data()->dead_lock, NULL);
	pthread_mutex_init(&get_data()->meal_lock, NULL);
	while (i < get_data()->num_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	init_philos_aux(forks);
}
