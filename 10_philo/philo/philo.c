/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:35:32 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/21 19:26:49 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philos		philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (ft_init_data(argc, argv, philos) == -1)
		return (-1);
	ft_init_philos(forks);
	print_data();
	ft_init_threads(forks);
	return (0);
}
