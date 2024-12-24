/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/17 19:15:59 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Looks for invalid parameters
 */
static void	is_valid_integer(char **arr, int len)
{
	char	**current;
	char	*str;

	current = arr;
	while (*current)
	{
		str = *current;
		if (*str == '+' || *str == '-')
			str++;
		if (*str == '\0')
			exit(0);
		while (*str)
		{
			if (!ft_isdigit((unsigned char)*str))
			{
				write(STDERR_FILENO, "Error\n", 6);
				if (len == 2)
					free_array(arr);
				exit(0);
			}
			str++;
		}
		current++;
	}
}

static void	has_duplicates(char **arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
			{
				write(STDERR_FILENO, "Error\n", 6);
				if (len == 2)
					free_array(arr);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief Converts a str representation of a number to long format.
 */
static long	ft_atol(const char *str)
{
	long	res;
	int		count;
	int		sign;

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
 * @brief Checks the input args if they are getting out of INT range.
 */
static void	out_of_range_check(char **arr, int len)
{
	char	**current;

	current = arr;
	while (*current)
	{
		if (ft_atol(*current) > INT_MAX || ft_atol(*current) < INT_MIN)
		{
			write(STDERR_FILENO, "Error\n", 6);
			if (len == 2)
				free_array(arr);
			exit(0);
		}
		current++;
	}
}

char	**menu(int len, char **arg)
{
	char	**arr;

	if (len == 1)
		exit(0);
	if (len == 2)
		arr = ft_split(arg[0], ' ');
	else
		arr = arg;
	has_duplicates(arr, len);
	is_valid_integer(arr, len);
	out_of_range_check(arr, len);
	return (arr);
}
