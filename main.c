/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:10:26 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/30 16:36:40 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts (int)argv in ascending order executing min moves
 */
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*int_array;
	int		*sorted_array;
	int		result;

	if (argc == 1)
		return (0);
	argv++;
	argc--;
	int_array = atoi_array(argv, argc);
	sorted_array = atoi_array(argv, argc);
	quick_sort(sorted_array, 0, argc - 1);
	a = stack_init(int_array, argc, sorted_array);
	b = NULL;
	print_nodes(a, b);
	result = sort_stack(&a, &b, argc);
	while (b)
	{
		printf("%d\n", b->nbr);
		b = b->next_nbr;
	}
	printf("\nNumber of moves: %d\n", result);
	return (0);
}
