/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/21 14:36:52 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
void	out_of_range_check(char **arr)
{
	while (*arr)
	{
		if (ft_atol(*arr) > INT_MAX || ft_atol(*arr) < INT_MIN)
		{
			write(STDERR_FILENO, "Error\n", 6);
			exit(0);
		}
		arr++;
	}
}

// void	sort_stack(t_stack **stack1, t_stack **stack2)
// {
// 	if (stck_len(*stack1) == 2)
// 		sort_stack_of_two(stack1);
// 	if (stck_len(*stack1) == 3)
// 		sort_stack_of_three(stack1);
// 	else
// 	{
// 		push(stack1, stack2, false, "pb\n");
// 		if (stck_len(*stack1) > 4)
// 			push(stack1, stack2, false, "pb\n");
// 		while (stck_len(*stack1) > 3)
// 		{
// 			print_nodes(*stack1, *stack2);
// 			push_cheapest(stack1, stack2, false);
// 		}
// 		print_nodes(*stack1, *stack2);
// 		sort_stack_of_three(stack1);
// 		target_cbn_node(*stack2, *stack1);
// 		while (*stack2)
// 		{
// 			print_rev_nodes(*stack2, *stack1);
// 			push_cheapest(stack2, stack1, true);
// 		}
// 	}
// 	print_node(*stack1);
// }