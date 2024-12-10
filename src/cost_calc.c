/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/09 15:21:43 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cheapest_node_index(t_stack *src_node, t_stack *dest_node)
{
	t_stack	*current_src;
	t_stack	*current_dest;
	int		src_index;
	int		dest_index;

	src_index = 0;
	current_src = src_node;
	while (current_src)
	{
		current_dest = dest_node;
		dest_index = 0;
		while (current_src->nbr < current_dest->nbr)
		{
			dest_index++;
			current_dest = current_dest->next_nbr;
		}
		current_src->cost = cost_calc()
		src_index++;
		current_src = current_src->next_nbr;
	}
	return (node_index);
}

int	cost_calc()
{
	
}