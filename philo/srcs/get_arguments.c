/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:08:23 by jvanden-          #+#    #+#             */
/*   Updated: 2021/09/28 10:47:26 by jvanden-         ###   ########.fr       */
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
	if (!is_inside_limits(INT_MAX, 0,
			data->number_of_times_each_philosopher_must_eat))
		return (0);
	return (1);
}
