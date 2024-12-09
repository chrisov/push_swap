/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/09 13:57:41 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		min;
	int		max;

	if (argc > 1)
	{
		stack_init(&a, argv);
		b = NULL;
		printf("a[%d]: ", num_of_nodes(a)); print_node(a);
		printf("b[%d]: ", num_of_nodes(b)); print_node(b);
		printf("\n");

		push_ab(&a, &b);
		push_ab(&a, &b);
		min = stack_min(a);
		max = stack_max(a);
		// while (num_of_nodes(a) >= 3)
		// {
		// 	if (a->nbr == min || a->nbr == max)
		// 		push(&a, &b);
		// 	cheapest_node(a);
		// 	push_cheapest();
		// 	num_of_nodes(a);
		// }
		// sort_stack_of_three(&a);
		// push_back();
		printf("a[%d]: ", num_of_nodes(a)); print_node(a);
		printf("b[%d]: ", num_of_nodes(b)); print_node(b);

	}
}