/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitris <dimitris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/22 23:21:26 by dimitris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	count;
	int	sign;

	res = 0;
	count = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		if (count > 0)
			return (0);
		str++;
		count++;
	}
	while (*str && ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}

/**
 * @brief Converts an array of str, of size "size" into an array of int.
 * 
 * @note Array is incrememnted before getting converted to get past argv[0].
 */
int	*atoi_array(char **array, int size)
{
	int	*array_int;
	int	i;

	array_int = malloc(size * sizeof(int));
	if (!array_int)
		return (0);
	i = 0;
	while (i < size)
	{
		array_int[i] = ft_atoi(array[i]);
		i++;
	}
	return (array_int);
}

/**
 * @brief Calculates the order of magnitude of a specific number
 * 
 * @param value The number of which the magnitude is to be calculated.
 * 
 * @returns result
 */
int	nbr_length(int value)
{
	int	result;

	result = 0;
	if (value == 0)
		return (1);
	if (value < 0)
		value *= -1;
	while (value > 0)
	{
		result++;
		value /= 10;
	}
	return (result);
}

/**
 * @brief Calculates the order of magnitude of the biggest number
 * given an array of ints.
 */
int	max_order_of_magnitude(int *array, int array_size)
{
	int	max;
	int	result;
	int	i;

	result = 0;
	i = 0;
	max = abs(array[i]);
	while (i < array_size)
	{
		if (abs(array[i]) > max)
			max = abs(array[i]);
		i++;
	}
	while (max > 0)
	{
		result++;
		max /= 10;
	}
	return (result);
}
