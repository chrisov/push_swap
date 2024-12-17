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

/**
 * @brief Compares two integers and returns the biggest.
 */
static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	push_cond(t_stack **src, t_stack **dest, t_stack *cheap, bool rv_flg)
{
	if (cheap->index == cheap->target_node->index)
	{
		if (cheap->above_median)
			rrr(src, dest, rotate, "rr\n");
		else
			rrr(src, dest, rev_rotate, "rrr\n");
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

/**
 * @brief Calculates the node's cost of transferring it to the other stack.
 */
void	calculate_cost(t_stack *src, t_stack *dest)
{
	t_stack	*current;
	int		cost;

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
