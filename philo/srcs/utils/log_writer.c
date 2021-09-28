/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_writer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:15:42 by jvanden-          #+#    #+#             */
/*   Updated: 2021/09/28 11:14:12 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	log_writer(t_philosopher *philosopher, char *str)
{
	long long	log_time;

	log_time = get_time() - philosopher->data->assembly.starting_time;
	if (time >= 0 && !death_checker(philosopher, 0))
	{
		printf("%lld ", log_time);
		printf("%d %s", philosopher->_id, str);
	}
}
