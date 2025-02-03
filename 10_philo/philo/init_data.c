/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:34:10 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/03 21:49:55 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

//prints the dat, debug
void print_data(void)
{
    printf("Num philos:\t%d\n",get_data()->num_philos);
    printf("Time die:\t%d\n",get_data()->time_to_die);
    printf("Time eat:\t%d\n",get_data()->time_to_eat);
    printf("Time sleep:\t%d\n",get_data()->time_to_sleep);
    printf("Num meals:\t%d\n",get_data()->num_meals);
    printf("Dead:\t\t%d\n",get_data()->someone_died);
    printf("Time start:\t%lld\n",get_data()->start_time);
}

// initializes the data struct with the args
int	ft_init_data(int argc, char **argv)
{
	if (argc == 5)
	{
		get_data()->num_philos = ft_atoi(argv[1]);
		get_data()->time_to_die = ft_atoi(argv[2]);
		get_data()->time_to_eat = ft_atoi(argv[3]);
		get_data()->time_to_sleep = ft_atoi(argv[4]);
		get_data()->num_meals = -1;
        return (0);
	}
	else if (argc == 6)
	{
		get_data()->num_philos = ft_atoi(argv[1]);
		get_data()->time_to_die = ft_atoi(argv[2]);
		get_data()->time_to_eat = ft_atoi(argv[3]);
		get_data()->time_to_sleep = ft_atoi(argv[4]);
		get_data()->num_meals = ft_atoi(argv[5]);
        return (0);
	}
    printf("\033[1;31mError in arguments.\033[0m\n");
	return (-1);
}
