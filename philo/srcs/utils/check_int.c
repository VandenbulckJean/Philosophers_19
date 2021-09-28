/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:01:18 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/25 15:14:08 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static int	is_number_char(char *string)
{
	int	i;

	i = -1;
	if (!ft_strcmp(string, "-") || !ft_strcmp(string, "+"))
		return (0);
	if (string[0] == '-' || string[0] == '+')
		i++;
	while (string[++i])
		if (!ft_isdigit(string[i]))
			return (0);
	return (1);
}

static int	check_limits(char *string, char sign)
{
	if (sign == 'p' && ft_strcmp(string, "2147483647") > 0)
		return (0);
	else if (sign == '+' && ft_strcmp(string + 1, "2147483647") > 0)
		return (0);
	else if (sign == '-' && ft_strcmp(string + 1, "2147483648") > 0)
		return (0);
	else
		return (1);
}

static int	is_integer(char *string)
{
	int		len;
	char	sign;

	len = ft_strlen(string);
	sign = 'p';
	if (string[0] == '-')
	{
		sign = '-';
		len--;
	}
	if (string[0] == '+')
	{
		sign = '+';
		len--;
	}
	if (len > 10)
		return (0);
	else if (len < 10)
		return (1);
	else
		return (check_limits(string, sign));
}

int	is_inside_limits(long int up, long int down, long int number)
{
	if (number < down || number > up)
		return (0);
	return (1);
}

int	check_int(char *str)
{
	if (!is_number_char(str))
		return (0);
	if (!is_integer(str))
		return (0);
	return (1);
}