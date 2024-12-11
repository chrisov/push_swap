/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/11 16:06:22 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_condition(t_stack **src, t_stack **dest, t_stack *cheapest)
{
	if (cheapest->index == cheapest->target_node->index)
	{
		if (cheapest->above_median)
			rr_rrr(src, dest, rotate, "rr");
		else
			rr_rrr(src, dest, rev_rotate, "rrr");
	}
	else
	{
		if (cheapest->index > cheapest->target_node->index)
		{
			if (cheapest->above_median)
				rotate(src, "ra");
			else
				rev_rotate(src, "rra");
		}
		else
		{
			if (cheapest->target_node->above_median)
				rotate(dest, "rb");
			else
				rev_rotate(dest, "rrb");
		}
	}
}

void	push_cheapest(t_stack **src, t_stack **dest)
{
	t_stack	*cheapest;

	calculate_cost(*src, *dest);
	is_cheapest(*src);
	cheapest = *src;
	while (cheapest->cheapest == false)
		cheapest = cheapest->next_node;
	while ((*src)->nbr != cheapest->nbr
			|| (*dest)->nbr != cheapest->target_node->nbr)
		push_condition(src, dest, cheapest);
	push(src, dest, false, "pab");
}
