/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/03 13:03:31 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void	node_cost_calc(t_stack **src_node, t_stack **dest_node)
// {
// 	int		src_index;
// 	int		dest_pos;
// 	t_stack	*current_dest;

// 	src_index = 0;
// 	while (src_node)
// 	{
// 		dest_pos = 0;
// 		current_dest = *dest_node;
// 		while (current_dest &&  (*src_node)->nbr < current_dest->nbr)
// 		{
// 			dest_pos++;
// 			current_dest = current_dest->next_nbr;
// 		}
// 		(*src_node)->index = src_index;
// 		(*src_node)->cost = src_index++ + dest_pos + 1;
// 		(*src_node) = (*src_node)->next_nbr;
// 	}
// }



// void	push_descend_order(t_stack **a, t_stack **b)
// {
// 	push_ab(a, b);
// 	push_ab(a, b);
// }