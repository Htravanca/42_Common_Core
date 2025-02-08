/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:58:53 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/08 22:25:04 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philos *philo)
{
	print_message("is thinking", philo);
}

void	dream(t_philos *philo)
{
	print_message("is sleeping", philo);
	ft_usleep(philo->time_to_sleep);
}