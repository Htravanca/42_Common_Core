/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:35:32 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/08 16:00:09 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *table_routine(void *data)
{
	t_philos *philo;

	philo = (t_philos *)data;
}


void	init_threads(pthread_mutex_t *forks)
{
	int i;

	i = 0;
	if (get_data()->num_meals == 0)
		return ;
	else if ((get_data()->num_philos == 1))
		;//to DO
	else
	{
		while (i < get_data()->num_philos)
		{
			if (pthread_create(&get_data()->philos[i].thread, NULL, &table_routine, &get_data()->philos[i]) != 0)
				destory_all("Thread creation error", program, forks);
			i++;
		}
		
	}
		
}
