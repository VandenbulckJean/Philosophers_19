/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:03:31 by jvanden-          #+#    #+#             */
/*   Updated: 2021/09/28 09:05:10 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	initialise_mutex(t_data *data)
{
	pthread_mutex_init(&data->assembly.write, NULL);
	pthread_mutex_init(&data->assembly.death, NULL);
	pthread_mutex_init(&data->assembly.eat, NULL);
	pthread_mutex_init(&data->assembly.end, NULL);
}

static int initialise_philosopher(int i, t_data *data)
{
	data->assembly.philosophers[i].data = data;
	data->assembly.philosophers[i]._id = i + 1;
	data->assembly.philosophers[i].amount_meal_eaten = 0;
	data->assembly.philosophers[i].is_eating = 0;
	data->assembly.philosophers[i].right_fork = NULL;
	data->assembly.philosophers[i].time_last_meal = data->assembly.starting_time;
	data->assembly.philosophers[i].done = 0;
	pthread_mutex_init(&data->assembly.philosophers[i].left_fork, NULL);
	if (data->number_of_philosophers == 1)
		return(0);
	if (i == data->number_of_philosophers - 1)
		data->assembly.philosophers[i].right_fork = &data->assembly.philosophers[0].left_fork;
	else
		data->assembly.philosophers[i].right_fork = &data->assembly.philosophers[i + 1].left_fork;
	return (1);	
}

int	initialise(t_data *data)
{
	int	i;

	i = 0;
	data->end_of_experiment = 0;
	data->assembly.philosophers = malloc(sizeof(t_philosopher) * data->number_of_philosophers);
	data->assembly.amount_philosopher_done = 0;
	if (!data->assembly.philosophers)
		return(7);
	data->assembly.starting_time = get_time();
	initialise_mutex(data);
	while (i < data->number_of_philosophers)
	{
		if (!initialise_philosopher(i, data))
			break;
		i++;
	}
	return (0);
}