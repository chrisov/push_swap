/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/17 18:53:53 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_cheap1(t_stack **stack, t_stack *cheap, bool rev_flag)
{
	if (cheap->above_median)
	{
		if (!rev_flag)
			rotate(stack, "ra\n");
		else
			rotate(stack, "rb\n");
	}
	else
	{
		if (!rev_flag)
			rev_rotate(stack, "rra\n");
		else
			rev_rotate(stack, "rrb\n");
	}
}

static void	rotate_cheap2(t_stack **stack, t_stack *cheap, bool rev_flag)
{
	if (cheap->target->above_median)
	{
		if (!rev_flag)
			rotate(stack, "rb\n");
		else
			rotate(stack, "ra\n");
	}
	else
	{
		if (!rev_flag)
			rev_rotate(stack, "rrb\n");
		else
			rev_rotate(stack, "rra\n");
	}
}

void	push_cond(t_stack **src, t_stack **dst, t_stack *cheap, bool rev_flag)
{
	if (cheap->i == cheap->target->i)
	{
		if (cheap->above_median)
			rrr(src, dst, rotate, "rr\n");
		else
			rrr(src, dst, rev_rotate, "rrr\n");
	}
	else
	{
		if (cheap->i > cheap->target->i)
			rotate_cheap1(src, cheap, rev_flag);
		else
			rotate_cheap2(dst, cheap, rev_flag);
	}
}
