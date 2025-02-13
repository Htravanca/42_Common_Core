/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:09:03 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/13 17:06:16 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//ft to init philo routine, safe in case of fail
int ft_initmonitorthread(pthread_mutex_t *forks, pthread_t *monitor)
{
	if (pthread_create(monitor, NULL, &monitor_routine, get_data()->philos) != 0)
	{
		ft_freebfexit(forks);
		printf("\033[1;31mError creating threads.\033[0m\n");
		return (-1);
	}	
	return (0);
}

//ft to init philo routine, safe in case of fail
int	ft_initphilothread(pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while (i < get_data()->num_philos)
	{
		if (pthread_create(&get_data()->philos[i].thread, NULL, &table_routine, &get_data()->philos[i]) != 0)
		{
			ft_freebfexit(forks);
			printf("\033[1;31mError creating threads.\033[0m\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

//ft to join monitor routine, safe in case of fail
int	ft_joinmonitorthread(pthread_mutex_t *forks, pthread_t monitor)
{
	if (pthread_join(monitor, NULL) != 0)
	{
		ft_freebfexit(forks);
		printf("\033[1;31mError join threads MONITOR.\033[0m\n");
		return (-1);
	}
	return (0);
}	


//ft to join philo routine, safe in case of fail
int	ft_joinphilothread(pthread_mutex_t *forks)
{
	int i;
	int join_failed;

	i = 0;
	join_failed = 0;
	while (i < get_data()->num_philos)
	{
		if (pthread_join(get_data()->philos[i].thread, NULL) != 0)
		{
			printf("\033[1;31mError join threads PHILO.\033[0m\n");
			join_failed = 1;
		}
		i++;
	}
	if (join_failed)
	{
		ft_freebfexit(forks);
		return (-1);
	}
	return (0);
}
