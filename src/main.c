/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/21 15:41:28 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Checks if there are invalid arguments.
//  */
static void	non_numeric_check(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (!(ft_isdigit(s[i][j]) || s[i][j] == '-' || s[i][j] == ' '))
			{
				write(STDOUT_FILENO, "Error\n", 6);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief Stack sorting algorithm, depending on its number of nodes.
 */
static void	sort_stack(t_stack **stack1, t_stack **stack2)
{
	if (stck_len(*stack1) == 2)
		sort_stack_of_two(stack1);
	else
	{
		if (stck_len(*stack1) == 3)
			sort_stack_of_three(stack1);
		else
		{
			push(stack1, stack2, false, "pb\n");
			if (stck_len(*stack1) > 4)
				push(stack1, stack2, false, "pb\n");
			while (stck_len(*stack1) > 3)
				push_cheapest(stack1, stack2, false);
			sort_stack_of_three(stack1);
			target_cbn_node(*stack2, *stack1);
			while (*stack2)
				push_cheapest(stack2, stack1, true);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	char			**arr;

	arr = NULL;
	if (argc == 1)
		exit(0);
	if (argc == 2)
		arr = ft_split(argv[1], ' ');
	else
		arr = ++argv;
	out_of_range_check(arr);
	non_numeric_check(arr);
	stack_init(&a, arr);
	b = NULL;
	sort_stack(&a, &b);
	bring_min_top(&a);
	free_list(&a, arr, argc);
}
