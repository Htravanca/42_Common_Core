/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:34:10 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/23 19:40:46 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ft_orderforks(&get_data()->philos[i].l_fork, &get_data()->philos[i].r_fork);
static void	ft_orderforks(pthread_mutex_t **first, pthread_mutex_t **second,
		int first_id, int second_id)
{
	pthread_mutex_t	*temp;
	int				temp_id;

	if (first_id < second_id)
		return ;
	temp = *first;
	*first = *second;
	*second = temp;
	temp_id = first_id;
	first_id = second_id;
	second_id = temp_id;
}

// initializes the struct philos with start values
static void	ft_initphilos_aux(pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < get_data()->num_philos)
	{
		get_data()->philos[i].id = i + 1;
		get_data()->philos[i].meals_eaten = 0;
		get_data()->philos[i].num_meals = get_data()->num_meals;
		get_data()->philos[i].someone_died = &get_data()->someone_died;
		get_data()->philos[i].eating = 0;
		get_data()->philos[i].last_meal_time = 0;
		get_data()->philos[i].write_lock = &get_data()->write_lock;
		get_data()->philos[i].dead_lock = &get_data()->dead_lock;
		get_data()->philos[i].meal_lock = &get_data()->meal_lock;
		get_data()->philos[i].l_fork = &forks[i];
		get_data()->philos[i].l_fork_id = i;
		if (i == 0)
		{
			get_data()->philos[i].r_fork = &forks[get_data()->num_philos - 1];
			get_data()->philos[i].r_fork_id = get_data()->num_philos - 1;
		}
		else
		{
			get_data()->philos[i].r_fork = &forks[i - 1];
			get_data()->philos[i].r_fork_id = i - 1;
		}
		ft_orderforks(&get_data()->philos[i].l_fork,
			&get_data()->philos[i].r_fork, get_data()->philos[i].l_fork_id,
			get_data()->philos[i].r_fork_id);
		i++;
	}
}

// initializes how many forks as there are philos
void	ft_init_philos(pthread_mutex_t *forks)
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
	ft_initphilos_aux(forks);
}
