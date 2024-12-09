/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/09 14:19:33 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cheapest_node_index(t_stack *src_node, t_stack *dest_node)
{
	int		src_index;
	int		dest_index;
	int		node_index;
	int		cost;
	t_stack	*current_dest;

	src_index = 0;
	while (src_node)
	{
		current_dest = dest_node;
		dest_index = 0;
		while (src_node->nbr < current_dest->nbr)
		{
			dest_index++;
			current_dest = current_dest->next_nbr;
		}
		if (src_index <= num_of_nodes(src_node) / 2 && dest_index <= num_of_nodes(dest_node) / 2)
			cost = (dest_index - src_index) + 1;
		src_index++;
		src_node = src_node->next_nbr;
	}
	return (node_index);
}
