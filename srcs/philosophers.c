/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:17:24 by jvanden-          #+#    #+#             */
/*   Updated: 2021/09/14 15:37:50 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	initialise_mutex(t_data *data)
{
	pthread_mutex_init(&data->assembly.write, NULL);
	pthread_mutex_init(&data->assembly.death, NULL);
}

int	initialise(t_data *data)
{
	int	i;

	i = 0;
	data->assembly.philosophers = malloc(sizeof(t_philosopher) * data->number_of_philosophers);
	if (!data->assembly.philosophers)
		return(7);
	initialise_mutex(data);
	while (i < data->number_of_philosophers)
	{
		data->assembly.philosophers[i]._id = i+1;
		data->assembly.philosophers[i].amount_meal_eaten = 0;
		data->assembly.philosophers[i].is_eating = 0;
		data->assembly.philosophers[i].right_fork = NULL;
		pthread_mutex_init(&data->assembly.philosophers[i].left_fork, NULL);
		if (data->number_of_philosophers == 1)
			break;
		if (i == data->number_of_philosophers - 1)
			data->assembly.philosophers[i].right_fork = &data->assembly.philosophers[0].left_fork;
		else
			data->assembly.philosophers[i].right_fork = &data->assembly.philosophers[i + 1].left_fork;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;
	int		parsing_error;
	int		initialise_error;

	parsing_error = parsing(argc, argv, &data);
	if (parsing_error)
		return(free_n_exit(parsing_error, NULL, 0));
	initialise_error = initialise(&data);
	if (initialise_error)
		return(free_n_exit(initialise_error, NULL, 0));
	free_n_exit(0, &data, 5);
}
