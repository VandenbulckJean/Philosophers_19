/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:14:19 by jvanden-          #+#    #+#             */
/*   Updated: 2021/09/28 10:26:06 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	take_fork(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->left_fork);
	pthread_mutex_lock(&philosopher->data->assembly.write);
	log_writer(philosopher, "has taken a fork\n");
	pthread_mutex_unlock(&philosopher->data->assembly.write);
	if (!philosopher->right_fork)
	{
		ft_usleep(philosopher->data->time_to_die * 2);
		return (0);
	}
	pthread_mutex_lock(philosopher->right_fork);
	pthread_mutex_lock(&philosopher->data->assembly.write);
	log_writer(philosopher, "has taken a fork\n");
	pthread_mutex_unlock(&philosopher->data->assembly.write);
	return (1);
}

static void	eat(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->data->assembly.write);
	log_writer(philosopher, "is eating\n");
	pthread_mutex_lock(&philosopher->data->assembly.eat);
	philosopher->time_last_meal = get_time();
	pthread_mutex_unlock(&philosopher->data->assembly.eat);
	pthread_mutex_unlock(&philosopher->data->assembly.write);
	ft_usleep(philosopher->data->time_to_eat);
	pthread_mutex_unlock(&philosopher->left_fork);
	pthread_mutex_unlock(philosopher->right_fork);
}

static void	philosopher_sleep(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->data->assembly.write);
	log_writer(philosopher, "is sleeping\n");
	pthread_mutex_unlock(&philosopher->data->assembly.write);
	ft_usleep(philosopher->data->time_to_sleep);
}

static void	think(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->data->assembly.write);
	log_writer(philosopher, "is thinking\n");
	pthread_mutex_unlock(&philosopher->data->assembly.write);
}

void	live(t_philosopher *philosopher)
{
	if (!take_fork(philosopher))
		return ;
	eat(philosopher);
	philosopher_sleep(philosopher);
	think(philosopher);
}