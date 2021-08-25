/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:15:44 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/25 16:50:30 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

# ifndef INT_MAX 
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef struct s_data
{
	int								number_of_philosophers;
	int								time_to_die;
	int								time_to_eat;
	int								time_to_sleep;
	int								number_of_times_each_philosopher_must_eat;
	struct s_philosopher_assembly	assembly;
}	t_data;

typedef struct s_philosopher
{
	int								_id;
	pthread_t						thread;
	int								amount_meal_eaten;
	long long						time_since_last_meal;
	char							is_eating;
	char							possess_left_fork;
	char							possess_right_fork;
}	t_philosopher;

typedef struct	s_philosopher_assembly
{
	t_philosopher	**philosophers;
	long long		starting_time;
	char			death;
}	t_philosopher_assembly;

//UTILS

int		ft_atoi(const char *str);
void	free_n_exit(char error, t_data *data, char lvl);
void	error_manager(char error);
int		check_int(char *str);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		is_inside_limits(long int up, long int down, long int number);
int		ft_isdigit(int c);
int		parsing(int argc, char **argv, t_data *data);

#endif