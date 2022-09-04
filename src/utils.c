/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:56:05 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/02 16:17:28 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


/*
**	The isdigit() function tests for a decimal digit character.
**	The isdigit() functions return zero if the character tests
     false and return non-zero if the character tests true.
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
**	The atoi() function converts the initial portion of
		the string pointed to by str to int representation.
*/
int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	while (*str <= 32)
		str++;
	sign = 1;
	if (*str == '-')
	{
		sign = sign * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}
