/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:17:24 by jvanden-          #+#    #+#             */
/*   Updated: 2021/09/27 14:50:49 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int		death_checker(t_philosopher *philosopher, int end_of_experiment)
{
	pthread_mutex_lock(&philosopher->data->assembly.death);
	if (end_of_experiment)
		philosopher->data->end_of_experiment = end_of_experiment;
	if (philosopher->data->end_of_experiment)
	{
		pthread_mutex_unlock(&philosopher->data->assembly.death);
		return (1);
	}
	pthread_mutex_unlock(&philosopher->data->assembly.death);
	return(0);
}

void death_angel(void *data)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)data;
	ft_usleep(philosopher->data->time_to_die + 1);
	pthread_mutex_lock(&philosopher->data->assembly.eat);
	pthread_mutex_lock(&philosopher->data->assembly.end);
	if (!death_checker(philosopher, 0) && !philosopher->done &&((get_time() -
	philosopher->time_last_meal) >= (long long)philosopher->data->time_to_die))
	{
		pthread_mutex_unlock(&philosopher->data->assembly.eat);
		pthread_mutex_unlock(&philosopher->data->assembly.end);
		pthread_mutex_lock(&philosopher->data->assembly.write);
		log_writer(philosopher, "died\n");
		pthread_mutex_lock(&philosopher->data->assembly.eat);
		death_checker(philosopher, 1);
	}
	pthread_mutex_unlock(&philosopher->data->assembly.eat);
	pthread_mutex_unlock(&philosopher->data->assembly.end);
}

void	philosopher(void *data)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)data;
	if (philosopher->_id % 2 == 0)
		ft_usleep(philosopher->data->time_to_eat / 10);
	while(death_checker(philosopher, 0))
	{
		pthread_create(&philosopher->death_angel_thread, NULL, death_angel, data);
		live(philosopher);
		pthread_detach(&philosopher->death_angel_thread);
		if (++philosopher->amount_meal_eaten == philosopher->data->number_of_times_each_philosopher_must_eat)
		{
			pthread_mutex_lock(&philosopher->data->assembly.end);
			philosopher->done = 1;
			philosopher->data->assembly.amount_philosopher_done++;
			if (philosopher->data->assembly.amount_philosopher_done == philosopher->data->number_of_philosophers)
			{
				pthread_mutex_unlock(&philosopher->data->assembly.end);
				death_checker(philosopher, 2);
			}
			pthread_mutex_unlock(&philosopher->data->assembly.end);
			return(NULL);
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		parsing_error;
	int		initialise_error;

	parsing_error = parsing(argc, argv, &data);
	if (parsing_error)
		return(free_n_exit(parsing_error, NULL, 0));
	initialise_error = initialise(&data);
	if (initialise_error)
		return(free_n_exit(initialise_error, NULL, 0));
	
	free_n_exit(0, &data, 2);
}
