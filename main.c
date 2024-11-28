/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:10:26 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/22 20:23:56 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts (int)argv in ascending order executing min moves
 */
int	main(int argc, char **argv)
{
	// t_stack	*a;
	int		*int_array;
	int		*sorted_array;

	if (argc == 1)
		return (0);
	argv++;
	int_array = atoi_array(argv, argc - 1);
	sorted_array = buckets(int_array, argc - 1);
	while(*sorted_array)
		printf("%d\n", *sorted_array++);
	// a = stack_init(int_array, argc - 1, sorted_array);
	// print_node(a);
	return (0);
}
