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

	(void)argc;
	stack_init(&a, argv);
	b = NULL;
	if (num_of_nodes(a) == 3)
		sort_stack_of_three(&a);
	else
	{
		push(&a, &b, false, "pab");
		push(&a, &b, false, "pab");
		while (num_of_nodes(a) > 3)
		{
			// print_nodes(a, b);
			push_cheapest(&a, &b, false);
		}
		// print_nodes(a, b);
		sort_stack_of_three(&a);
		target_cbn_node(b, a);
		while (b)
		{
			// print_rev_nodes(b, a);
			push_cheapest(&b, &a, true);
		}
		// print_node(a);
	}
}

// make run -- 16 -59 -66 44 78 -40 63 -88 80 81