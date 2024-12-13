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

static void	push_cond(t_stack **src, t_stack **dest, t_stack *cheap, bool rv_flg)
{
	if (cheap->index == cheap->target_node->index)
	{
		if (cheap->above_median)
			rr_rrr(src, dest, rotate, "rr\n");
		else
			rr_rrr(src, dest, rev_rotate, "rrr\n");
	}
	else
	{
		if (cheap->index > cheap->target_node->index)
		{
			if (cheap->above_median)
			{
				if (!rv_flg)
					rotate(src, "ra\n");
				else
					rotate(src, "rb\n");
			}
			else
			{
				if (!rv_flg)
					rev_rotate(src, "rra\n");
				else
					rev_rotate(src, "rrb\n");
			}
		}
		else
		{
			if (cheap->target_node->above_median)
			{
				if (!rv_flg)
					rotate(dest, "rb\n");
				else
					rotate(dest, "ra\n");
			}
			else
			{
				if (!rv_flg)
					rev_rotate(dest, "rrb\n");
				else
					rev_rotate(dest, "rra\n");
			}
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
		push_cond(src, dest, cheapest, rev_flag);
	(*src)->cheapest = false;
	if (!rev_flag)
		push(src, dest, false, "pb\n");
	else
		push(src, dest, true, "pa\n");
}
