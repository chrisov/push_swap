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

// static void	rotate_cheap(t_stack **stack, t_stack *cheap, bool rev_flag)
// {
// 	if (cheap->above_median)
// 	{
// 		if (!rev_flag)
// 			rotate(stack, "ra\n");
// 		else
// 			rotate(stack, "rb\n");
// 	}
// 	else
// 	{
// 		if (!rev_flag)
// 			rev_rotate(stack, "rra\n");
// 		else
// 			rev_rotate(stack, "rrb\n");
// 	}
// }

// static void	push_cond(t_stack **src, t_stack **dst, t_stack *cheap, bool rv_flg)
// {
// 	if (cheap->i == cheap->target->i)
// 	{
// 		if (cheap->above_median)
// 			rrr(src, dst, rotate, "rr\n");
// 		else
// 			rrr(src, dst, rev_rotate, "rrr\n");
// 	}
// 	else
// 	{
// 		if (cheap->i > cheap->target->i)
// 			rotate_cheap(src, cheap, rv_flg);
// 		else
// 			rotate_cheap(dst, cheap, rv_flg);
// 	}
// }

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

/**
 * @brief Calculates the node's cost of transferring it to the other stack.
 */
void	calculate_cost(t_stack *s, t_stack *d)
{
	t_stack	*ptr;
	int		cost;

	ptr = s;
	while (ptr)
	{
		cost = 0;
		if (ptr->above_median)
		{
			if (ptr->target->above_median)
				cost = max(ptr->i, ptr->target->i);
			else
				cost = ptr->i + stck_len(d) - ptr->target->i;
		}
		else
		{
			if (ptr->target->above_median)
				cost = stck_len(s) - ptr->i + ptr->target->i;
			else
				cost = max(stck_len(s) - ptr->i, stck_len(d) - ptr->target->i);
		}
		ptr->cost = cost;
		ptr = ptr->next_node;
	}
}