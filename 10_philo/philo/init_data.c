/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:34:10 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/08 20:09:09 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// function to acess data struct
t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

// prints the data struct -> debug
void	print_data(void)
{
	printf("Num philos:\t%d\n", get_data()->num_philos);
	printf("Time die:\t%d\n", get_data()->time_to_die);
	printf("Time eat:\t%d\n", get_data()->time_to_eat);
	printf("Time sleep:\t%d\n", get_data()->time_to_sleep);
	printf("Num meals:\t%d\n", get_data()->num_meals);
	printf("Dead:\t\t%d\n", get_data()->someone_died);
}

// validates de data passed to struct data
static int	ft_validate_data(int argc, char **argv)
{
	if (get_data()->num_philos <= 0 || get_data()->num_philos > PHILO_MAX
		|| ft_isalldigit(argv[1]) == -1)
		return (printf("\033[1;31mError in number of philos.\033[0m\n"), -1);
	if (get_data()->time_to_die <= 0 || ft_isalldigit(argv[2]) == -1)
		return (printf("\033[1;31mError in time to die.\033[0m\n"), -1);
	if (get_data()->time_to_eat <= 0 || ft_isalldigit(argv[3]) == -1)
		return (printf("\033[1;31mError in time to eat.\033[0m\n"), -1);
	if (get_data()->time_to_sleep <= 0 || ft_isalldigit(argv[4]) == -1)
		return (printf("\033[1;31mError in time to sleep.\033[0m\n"), -1);
	if (argc == 6 && (get_data()->num_meals <= 0
			|| ft_isalldigit(argv[5]) == -1))
		return (printf("\033[1;31mError in number of meals.\033[0m\n"), -1);
	return (0);
}

// initializes the data struct with the args
int	ft_init_data(int argc, char **argv, t_philos *philos)
{
	if (argc == 5 || argc == 6)
	{
		get_data()->num_philos = ft_atoi(argv[1]);
		get_data()->time_to_die = ft_atoi(argv[2]);
		get_data()->time_to_eat = ft_atoi(argv[3]);
		get_data()->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			get_data()->num_meals = ft_atoi(argv[5]);
		else
			get_data()->num_meals = -1;
		get_data()->philos = philos;
		get_data()->someone_died = false;
		return (ft_validate_data(argc, argv));
	}
	else
		printf("\033[1;31mError in Arguments.\033[0m\n");
	return (-1);
}
