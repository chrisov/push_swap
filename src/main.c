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
 * @brief Checks if the arg is only one number.
 */
static bool	one_num_check(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (false);
	}
	return (true);
}

/**
 * @brief Checks if there are invalid arguments.
 */
static bool	non_numeric(char *str)
{
	while (*str)
	{
		if (!(ft_isdigit(*str) || *str == '-' || *str == '+' || *str == ' '))
			return (true);
		str++;
	}
	return (false);
}

/**
 * @brief Creates the input arr, depending on the num of args.
 */
static char	**num_args(char **arr, int len)
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

/**
 * @brief Stack sorting algorithm, depending on its number of nodes.
 */
static void	sort_stack(t_stack **stack1, t_stack **stack2)
{
	if (num_of_nodes(*stack1) == 2)
		sort_stack_of_two(stack1);
	if (num_of_nodes(*stack1) == 3)
		sort_stack_of_three(stack1);
	else
	{
		push(stack1, stack2, false, "pb\n");
		if (num_of_nodes(*stack1) > 4)
			push(stack1, stack2, false, "pb\n");
		while (num_of_nodes(*stack1) > 3)	
			push_cheapest(stack1, stack2, false);
		sort_stack_of_three(stack1);
		target_cbn_node(*stack2, *stack1);
		while (*stack2)
			push_cheapest(stack2, stack1, true);
	}
}

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	char			**arr;

	arr = NULL;
	if (argc < 3)
		arr = num_args(argv, argc);
	else
		arr = ++argv;
	out_of_range_check(arr);
	stack_init(&a, arr);
	b = NULL;
	sort_stack(&a, &b);
	bring_min_top(&a);
	free_list(&a, arr, argc);
}

// make run -- 16 -59 -66 44 78 -40 63 -88 80 81