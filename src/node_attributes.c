/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_attributes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/17 18:51:47 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Calculates the index value of the node in the stack.
 */
void	node_index(t_stack *head)
{
	int	index;

	index = 0;
	while (head)
	{
		head->i = index++;
		head = head->next_node;
	}
}

/**
 * @brief Calculates the target node of the given src node as the one with the 
 * closest smaller number, during the transfering to stack b phase.
 * 
 * @note If no node with closest smaller number is found, then points to the
 * biggest one in the b stack. 
 */
void	target_csn_node(t_stack *src, t_stack *dst)
{
	t_stack	*current;
	int		target;

	if (dst)
	{
		while (src)
		{
			src->target = find_max_node(dst);
			current = dst;
			target = INT_MIN;
			while (current)
			{
				if (src->nbr > current->nbr && current->nbr > target)
				{
					target = current->nbr;
					src->target = current;
				}
				current = current->next_node;
			}
			if (target == INT_MIN)
				src->target = find_max_node(dst);
			src = src->next_node;
		}
	}
}

/**
 * @brief Calculates the target node of the given src node as the one with the 
 * closest bigger number, during the transfering back to stack a phase.
 * 
 * @note If no node with closest bigger number is found, then points to the
 * smallest one in the a stack.
 */
void	target_cbn_node(t_stack *src, t_stack *dst)
{
	t_stack	*current;
	int		target;

	if (dst)
	{
		while (src)
		{
			src->target = find_min_node(dst);
			current = dst;
			target = INT_MAX;
			while (current)
			{
				if (src->nbr < current->nbr && current->nbr < target)
				{
					target = current->nbr;
					src->target = current;
				}
				current = current->next_node;
			}
			if (target == INT_MAX)
				src->target = find_min_node(dst);
			src = src->next_node;
		}
	}
}

/**
 * @brief Determines the position of the node in the stack, in relation to
 * the stack's median.
 */
void	position_to_median(t_stack *head)
{
	int		len;

	len = stck_len(head);
	if (len == 2)
	{
		head->above_median = true;
		head->next_node->above_median = false;
	}
	else
	{
		while (head)
		{
			if (head->i <= len / 2)
				head->above_median = true;
			else
				head->above_median = false;
			head = head->next_node;
		}
	}
}

/**
 * @brief Gives the is_cheapest flag to the node with the smallest cost. 
 */
void	is_cheapest(t_stack *head)
{
	t_stack	*current;
	int		min_cost;
	int		cheapest_index;

	min_cost = head->cost;
	cheapest_index = head->i;
	current = head;
	while (current)
	{
		if (current->cost < min_cost)
		{
			min_cost = current->cost;
			cheapest_index = current->i;
		}
		current = current->next_node;
	}
	while (cheapest_index-- > 0)
		head = head->next_node;
	head->cheapest = true;
}
