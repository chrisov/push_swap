/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/12 15:24:43 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_condition(t_stack **src, t_stack **dest, t_stack *cheapest)
{
	if (cheapest->index == cheapest->target_node->index)
	{
		if (cheapest->above_median)
			rr_rrr(src, dest, rotate, "rr\n");
		else
			rr_rrr(src, dest, rev_rotate, "rrr\n");
	}
	else
	{
		if (cheapest->index > cheapest->target_node->index)
		{
			if (cheapest->above_median)
				rotate(src, "ra\n");
			else
				rev_rotate(src, "rra\n");
		}
		else
		{
			if (cheapest->target_node->above_median)
				rotate(dest, "rb\n");
			else
				rev_rotate(dest, "rrb\n");
		}
	}
}

void	push_cheapest(t_stack **src, t_stack **dest, bool rev_flag)
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
	(*src)->cheapest = false;
	if (!rev_flag)
		push(src, dest, false, "pab\n");
	else
		push(src, dest, true, "pba\n");
}
