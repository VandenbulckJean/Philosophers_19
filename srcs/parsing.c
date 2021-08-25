/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:01:16 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/25 16:13:47 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	get_number_of_philosophers(t_data *data, char *str)
{
	if (!check_int(str))
		return (0);
	data->number_of_philosophers = ft_atoi(str);
	if (!is_inside_limits(INT_MAX, 1, data->number_of_philosophers))
		return (0);
	return (1);
}

int	get_time_to_die(t_data *data, char *str)
{
	if (!check_int(str))
		return (0);
	data->time_to_die = ft_atoi(str);
	if (!is_inside_limits(INT_MAX, 0, data->time_to_die))
		return (0);
	return (1);
}

int	get_time_to_eat(t_data *data, char *str)
{
	if (!check_int(str))
		return (0);
	data->time_to_eat = ft_atoi(str);
	if (!is_inside_limits(INT_MAX, 0, data->time_to_eat))
		return (0);
	return (1);
}

int	get_time_to_sleep(t_data *data, char *str)
{
	if (!check_int(str))
		return (0);
	data->time_to_sleep = ft_atoi(str);
	if (!is_inside_limits(INT_MAX, 0, data->time_to_sleep))
		return (0);
	return (1);
}

int	get_number_of_times_each_philosophers_must_eat(t_data *data, char *str)
{
	if (!check_int(str))
		return (0);
	data->number_of_times_each_philosopher_must_eat = ft_atoi(str);
	if (!is_inside_limits(INT_MAX, 0, data->number_of_times_each_philosopher_must_eat))
		return (0);
	return (1);
}

int	parsing(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
		free_n_exit(1, NULL, 0);
	if (!get_number_of_philosophers(data, argv[1]))
		free_n_exit(2, NULL, 0);
	if (!get_time_to_die(data, argv[2]))
		free_n_exit(3, NULL, 0);
	if (!get_time_to_eat(data, argv[3]))
		free_n_exit(4, NULL, 0);
	if (!get_time_to_die(data, argv[4]))
		free_n_exit(5, NULL, 0);
	if (argc == 6)
		if (!get_time_to_die(data, argv[5]))
			free_n_exit(6, NULL, 0);
	return(1);
}