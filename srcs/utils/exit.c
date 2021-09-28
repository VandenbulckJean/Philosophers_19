/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:57:29 by jvanden-          #+#    #+#             */
/*   Updated: 2021/09/28 08:33:14 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	free_n_exit(char error, t_data *data, char lvl)
{
	(void)data;

	if (error)
		error_manager(error);
	if (lvl <= 0)
		return(0);
	else if (lvl <= 1)
	{
		free(data->assembly.philosophers);
		return(0);
	}
	else
	{
		free(data->assembly.philosophers);
		printf("Exited without error\n");
		return(1);
	}
}

void	error_manager(char error)
{
	if (error == 1)
		printf("Error: you must have at least 4 arguments and at most 5.\n");
	else if (error == 2)
		printf("Error: Number of phisolopher must be a number between 1 and 2147483647.\n");
	else if (error == 3)
		printf("Error: Time to die must be a number between 0 and 2147483647.\n");
	else if (error == 4)
		printf("Error: Time to eat must be a number between 0 and 2147483647.\n");
	else if (error == 5)
		printf("Error: Time to sleep must be a number between 0 and 2147483647.\n");
	else if (error == 6)
		printf("Error: Number of time each one must eat must be a number between 0 and 2147483647.\n");
	else if (error == 7)
		printf("Error: Couldn't allocate memory for assembly.\n");
	else if (error == 8)
		printf("Error: Philosopher thread creation failed.\n");
	else
		printf("Error: undefined.\n");
}