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
		b = NULL;
		printf("a[%d]: ", num_of_nodes(a)); print_node(a);
		printf("b[%d]: ", num_of_nodes(b)); print_node(b); printf("\n");
		push_ab(&a, &b);
		push_ab(&a, &b);
		push_ab(&a, &b);
		push_ab(&a, &b);

		target_position(a, b);
		printf("%d\n", cost_calc(a, b));
		// while (num_of_nodes(a) >= 3)
		// {
		// 	push_ab(&a, &b);
		// 	target_position(&a);
			
		// 	num_of_nodes(a);
		// }
		printf("a[%d]: ", num_of_nodes(a)); print_node(a);
		printf("b[%d]: ", num_of_nodes(b)); print_node(b);

	}
}