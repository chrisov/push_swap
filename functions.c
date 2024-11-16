/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitris <dimitris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/16 01:15:15 by dimitris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*nbr_sign(int number)
{
	if (number >= 0)
		return ("positive");
	else
		return ("negative");
}

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

int	array_max_digits(char **array)
{
	int	max;
	int	result;

	result = 0;
	max = abs(ft_atoi(*array));
	while (*array)
	{
		if (abs(ft_atoi(*array)) > max)
			max = abs(ft_atoi(*array));
		array++;
	}
	while (max > 0)
	{
		result++;
		max /= 10;
	}
	return (result);

}

int	**buckets_alloc(t_stack *s, int maxlen)
{
	int		**array;
	int		size;
	int		columns;
	t_stack	*ptr;

	array = malloc(maxlen * sizeof(int *));
	if (!array)
		return (0);
	size = maxlen;
	while (size >= 1)
	{
		columns = 0;
		ptr = s;
		while (ptr)
		{
			if (ptr->length == size)
				columns++;
			ptr = ptr->next_nbr;
		}
		array[size - 1] = malloc (columns * sizeof(int));
		if (!array[size - 1])
			return (0);
		size--;
	}
	return (array);
}

int	**buckets_init(t_stack *ptr, int digits)
{
	int	columns;
	int	**array;

	while (digits >= 1)
	{
		while (ptr)
		{
			columns = 0;
			if (ptr->length == digits)
			{
				array[digits - 1][columns] = ptr->nbr;
				columns++;
			}
			ptr = ptr->next_nbr;
		}
		digits--;
	}
}

void	bucket_sort(int **array)
{
	while (*array)
	{

	}
}