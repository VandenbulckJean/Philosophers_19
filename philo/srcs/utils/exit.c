/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:57:29 by jvanden-          #+#    #+#             */
/*   Updated: 2021/09/28 11:12:52 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	free_n_exit(char error, t_data *data, char lvl)
{
	if (error)
		error_manager(error);
	if (lvl <= 0)
		return (0);
	else if (lvl <= 1)
	{
		free(data->assembly.philosophers);
		return (0);
	}
	else
	{
		free(data->assembly.philosophers);
		return (1);
	}
}

static void	p_e(char *str)
{
	printf("Error: %s.\n", str);
}

void	error_manager(char error)
{
	if (error == 1)
		p_e("you must have at least 4 arguments and at most 5");
	else if (error == 2)
		p_e("Number of phisolopher must be a number between 1 and 2147483647");
	else if (error == 3)
		p_e("Time to die must be a number between 0 and 2147483647");
	else if (error == 4)
		p_e("Time to eat must be a number between 0 and 2147483647");
	else if (error == 5)
		p_e("Time to sleep must be a number between 0 and 2147483647");
	else if (error == 6)
		p_e("Fifth argument must be a number between 0 and 2147483647");
	else if (error == 7)
		p_e("Couldn't allocate memory for assembly");
	else if (error == 8)
		p_e("Philosopher thread creation failed");
	else
		p_e("Undefined");
}
