/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/10 16:03:12 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	calculate_cost(t_stack *src, t_stack *dest)
{
	t_stack	*current;
	int	cost;

	current = src;
	while (current)
	{
		cost = 0;
		if (current->above_median)
		{
			if (current->target_node->above_median)
				cost = max(current->index, current->target_node->index);
			else
				cost = current->index + num_of_nodes(dest) - current->target_node->index;
		}
		else
		{
			if (current->target_node->above_median)
				cost = num_of_nodes(src) - current->index + current->target_node->index;
			else
				cost = max(num_of_nodes(src) - current->index, num_of_nodes(dest) - current->target_node->index);
		}
		current->cost = cost;
		current = current->next_node;
	}
}
