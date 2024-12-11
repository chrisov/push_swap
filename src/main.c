/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/11 16:08:57 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		stack_init(&a, argv);
		b = NULL;
		push_ab(&a, &b, "pab");
		push_ab(&a, &b, "pab");
		while (num_of_nodes(a) > 3)
		{
			calculate_cost(a, b);
			is_cheapest(a);
			print_nodes(a, b);
			printf("             _____________________________________________________\n\n");
			push_cheapest(&a, &b);
		}
		print_nodes(a, b);
		printf("             _____________________________________________________\n\n");
		sort_stack_of_three(&a);
		print_nodes(a, b);
	}
}

// make run -- 16 -59 -66 44 78 -40 63 -88 80 81