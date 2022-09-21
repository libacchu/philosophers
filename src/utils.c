/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:56:05 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/18 09:19:07 by libacchu         ###   ########.fr       */
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
long	ft_atoi(const char *str)
{
	int		sign;
	long	num;

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

int	ft_check_overflow(int ac, char **av)
{
	long long	num;
	int			i;

	i = 1;
	while (i < ac)
	{	
		if (ft_strlen(av[i]) > 11)
			return (EXIT_FAILURE);
		num = ft_atoi(av[i]);
		if (num < -2147483648 || num > 2147483647)
			return (EXIT_FAILURE);
		i++;
	}
	return (0);
}

/*
 The strlen() function computes the length of the string s.  The strnlen()
     function attempts to compute the length of s, but never scans beyond the
     first maxlen bytes of s.
The strlen() function returns the number of characters that precede the ter-
     minating NUL character.
*/
size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}