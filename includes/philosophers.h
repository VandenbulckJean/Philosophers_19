/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:15:44 by jvanden-          #+#    #+#             */
/*   Updated: 2021/09/27 14:46:34 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# ifndef INT_MAX 
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef struct s_philosopher
{
	int								_id;
	pthread_t						philosopher_thread;
	pthread_t						death_angel_thread;
	pthread_mutex_t					left_fork;
	pthread_mutex_t					*right_fork;
	int								amount_meal_eaten;
	long long						time_last_meal;
	char							is_eating;
	int								done;
	struct s_data					*data;
}	t_philosopher;

typedef struct	s_philosopher_assembly
{
	t_philosopher					*philosophers;
	long long						starting_time;
	int								amount_philosopher_done;
	pthread_mutex_t					write;
	pthread_mutex_t					death;
	pthread_mutex_t					eat;
	pthread_mutex_t					end;
}	t_philosopher_assembly;

typedef struct s_data
{
	int								number_of_philosophers;
	int								time_to_die;
	int								time_to_eat;
	int								time_to_sleep;
	int								number_of_times_each_philosopher_must_eat;
	int								end_of_experiment;
	t_philosopher_assembly			assembly;
}	t_data;

//UTILS

int			ft_atoi(const char *str);
int			free_n_exit(char error, t_data *data, char lvl);
void		error_manager(char error);
int			check_int(char *str);
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
int			is_inside_limits(long int up, long int down, long int number);
int			ft_isdigit(int c);
long long	get_time(void);
void		ft_usleep(long long time);
void		log_writer(t_philosopher *philosopher, char *str);

//PARSING
int			parsing(int argc, char **argv, t_data *data);
int			get_number_of_philosophers(t_data *data, char *str);
int			get_time_to_die(t_data *data, char *str);
int			get_time_to_eat(t_data *data, char *str);
int			get_time_to_sleep(t_data *data, char *str);
int			get_number_of_times_each_philosophers_must_eat(t_data *data, char *str);

//INIT
int			initialise(t_data *data);

//PHILOSOPHER
int			death_checker(t_philosopher *philosopher, int end_of_experiment);
void		live(t_philosopher *philosopher);
#endif