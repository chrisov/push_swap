/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/30 16:18:21 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_atoi(const char *str)
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
 * @brief Calculates the target position of each node.
 * 
 * @param value The value-number of the node.
 * @param sorted_array Array to be searched for each value that corresponds to
 * a specific node.
 * 
 * @returns The index of the value-number in the sorted array.
 */
int	target_position(int value, int *sorted_array)
{
	int	i;
	int	target_index;

	i = 0;
	target_index = 1;
	while (sorted_array[i++] != value)
		target_index++;
	return (target_index);
}
