/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:01:16 by jvanden-          #+#    #+#             */
/*   Updated: 2021/09/27 12:08:12 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	parsing(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
		return(1);
	if (!get_number_of_philosophers(data, argv[1]))
		return(2);
	if (!get_time_to_die(data, argv[2]))
		return(3);
	if (!get_time_to_eat(data, argv[3]))
		return(4);
	if (!get_time_to_sleep(data, argv[4]))
		return(5);
	if (argc == 6)
	{
		if (!get_number_of_times_each_philosophers_must_eat(data, argv[5]))
			return(6);
	}
	else
		data->number_of_times_each_philosopher_must_eat = -1;
	return(0);
}