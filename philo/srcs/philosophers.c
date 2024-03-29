/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:17:24 by jvanden-          #+#    #+#             */
/*   Updated: 2021/09/28 11:04:17 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	death_checker(t_philosopher *philosopher, int end_of_experiment)
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
	return (0);
}

void	*death_angel(void *data)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)data;
	ft_usleep(philosopher->data->time_to_die + 1);
	pthread_mutex_lock(&philosopher->data->assembly.eat);
	pthread_mutex_lock(&philosopher->data->assembly.end);
	if (!death_checker(philosopher, 0) && !philosopher->done && ((get_time()
				- philosopher->time_last_meal)
			>= (long long)philosopher->data->time_to_die))
	{
		pthread_mutex_unlock(&philosopher->data->assembly.eat);
		pthread_mutex_unlock(&philosopher->data->assembly.end);
		pthread_mutex_lock(&philosopher->data->assembly.write);
		log_writer(philosopher, "died\n");
		pthread_mutex_unlock(&philosopher->data->assembly.write);
		death_checker(philosopher, 1);
	}
	pthread_mutex_unlock(&philosopher->data->assembly.eat);
	pthread_mutex_unlock(&philosopher->data->assembly.end);
	return (NULL);
}

void	*philosopher(void *data)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)data;
	if (philosopher->_id % 2 == 0)
		ft_usleep(philosopher->data->time_to_eat / 10);
	while (!death_checker(philosopher, 0))
	{
		pthread_create(&philosopher->death_angel_thread,
			NULL, death_angel, data);
		pthread_detach(philosopher->death_angel_thread);
		live(philosopher);
		if (is_well_fed(philosopher))
			return (NULL);
	}
	return (NULL);
}

static int	start_experiment(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&data->assembly.philosophers[i].philosopher_thread,
				NULL, philosopher, &data->assembly.philosophers[i]) != 0)
			return (8);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		parsing_error;
	int		initialise_error;
	int		experiment_error;

	parsing_error = parsing(argc, argv, &data);
	if (parsing_error)
		return (free_n_exit(parsing_error, NULL, 0));
	initialise_error = initialise(&data);
	if (initialise_error)
		return (free_n_exit(initialise_error, NULL, 0));
	experiment_error = start_experiment(&data);
	if (experiment_error)
		return (free_n_exit(experiment_error, NULL, 1));
	terminate(&data);
	free_n_exit(0, &data, 2);
}
