/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/10 15:16:13 by dchrysov         ###   ########.fr       */
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
		// printf_node(a);
		b = NULL;
		rotate(&a);
		rotate(&a);
		push_ab(&a, &b);
		push_ab(&a, &b);
		push_ab(&a, &b);
		swap(&a);
		// rev_rotate(&a);
		target_node(a, b);
		calculate_cost(a, b);
		is_cheapest(a);
		print_nodes(a, b);
		// print_nodes(a, b);

		// // while (num_of_nodes(a) >= 3)
		// // {
		// // 	push_ab(&a, &b);
		// // 	target_position(&a);
			
		// // 	num_of_nodes(a);
		// // }
	}
}