/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:57:29 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/25 16:08:16 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	free_n_exit(char error, t_data *data, char lvl)
{
	(void)data;

	if (error)
		error_manager(error);
	if (lvl <= 0)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
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
	else
		printf("Error: undefined.\n");
}