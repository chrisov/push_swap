/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/12 16:46:19 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	one_num_check(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (false);
	}
	return (true);
}

static bool	non_numeric(char *str)
{
	while (*str)
	{
		if (!(ft_isdigit(*str) || *str == '-' || *str == ' '))
			return (true);
		str++;
	}
	return (false);
}

/**
 * @brief First checks for descending order, second one for ascending.
 */
bool	already_sorted(t_stack *head)
{
    bool	ascending;
	bool	descending;

	ascending = true;
	descending = true;
    while (head->next_node)
	{
        if (head->nbr > head->next_node->nbr)
            ascending = false;
        if (head->nbr < head->next_node->nbr)
            descending = false;
		head = head->next_node;
	}
    return (ascending || descending);
}

char	**num_args(char **arr, int len)
{
	if (len == 1 || one_num_check(arr[1]))
		exit(1);
	if (non_numeric(arr[1]))
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(1);
	}
	return (ft_split(arr[1], ' '));
}
