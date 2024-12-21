/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cond.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/21 14:08:49 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Helper function that rotates the stack based on the position of the
 * cheapest node.
 */
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

/**
 * @brief Helper function #2 that rotates the stack based on the position of the
 * cheapest node.
 */
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

/**
 * @brief Depending on the position and the target of the head node of the src
 * stack, rotates all stacks needed to bring the node and its target to the
 * head of their corresponding stack, using the least amount of rotations.
 */
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

/**
 * @brief Pushes the cheapest node from one stack to the other.
 * 
 * @note When rev_flag == true, means it pushes back from b to a.
 */
void	push_cheapest(t_stack **src, t_stack **dest, bool rev_flag)
{
	t_stack	*cheapest;

	calculate_cost(*src, *dest);
	is_cheapest(*src);
	cheapest = *src;
	while (cheapest->cheapest == false)
		cheapest = cheapest->next_node;
	while ((*src)->nbr != cheapest->nbr
		|| (*dest)->nbr != cheapest->target->nbr)
		push_cond(src, dest, cheapest, rev_flag);
	(*src)->cheapest = false;
	if (!rev_flag)
		push(src, dest, false, "pb\n");
	else
		push(src, dest, true, "pa\n");
}
