/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitris <dimitris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:10:26 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/17 20:02:31 by dimitris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts (int)argv in ascending order executing min moves
 */
int	main(int argc, char **argv)
{
	t_stack	*a;
	int		*int_array;
	int		*sorted_array;

	if (argc == 1)
		return (0);
	int_array = atoi_array(argv, argc - 1);
	sorted_array = buckets(int_array, argc - 1);
	a = stack_init(int_array, sorted_array);
	print_node(a);
	return (0);
}
