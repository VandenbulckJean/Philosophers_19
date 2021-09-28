/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 08:35:18 by jvanden-          #+#    #+#             */
/*   Updated: 2021/09/28 08:56:31 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	end_of_experiment_checker(t_data *data)
{
	pthread_mutex_lock(&data->assembly.death);
	if (data->end_of_experiment)
	{
		pthread_mutex_unlock(&data->assembly.death);
		return(0);
	}
	pthread_mutex_unlock(&data->assembly.death);
	return(1);
}

void	terminate(t_data *data)
{
	int i;

	i = 0;
	while (end_of_experiment_checker(data))
	{
		ft_usleep(1);
	}
	while (i < data->number_of_philosophers)
		pthread_join(data->assembly.philosophers[i++].philosopher_thread, NULL);
	pthread_mutex_destroy(&data->assembly.write);
	pthread_mutex_destroy(&data->assembly.death);
	pthread_mutex_destroy(&data->assembly.end);
	pthread_mutex_destroy(&data->assembly.eat);
	i = 0;
	while (i < data->number_of_philosophers)
		pthread_mutex_destroy(&data->assembly.philosophers[i++].left_fork);
	if (data->end_of_experiment == 2)
		printf("Each philosopher ate %d time(s)\n", data->assembly.philosophers[0].amount_meal_eaten);
}