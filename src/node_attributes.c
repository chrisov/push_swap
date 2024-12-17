/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_attributes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/16 14:40:43 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	node_index(t_stack *head)
{
	int	index;

	index = 0;
	while (head)
	{
		head->index = index++;
		head = head->next_node;
	}
}

void	target_csn_node(t_stack *src, t_stack *dst)
{
	t_stack	*current;
	int		target;

	if (dst)
	{
		while (src)
		{
			src->target_node = find_max_node(dst);
			current = dst;
			target = INT_MIN;
			while (current)
			{
				if (src->nbr > current->nbr && current->nbr > target)
				{
					target = current->nbr;
					src->target_node = current;
				}
				current = current->next_node;
			}
			if (target == INT_MIN)
				src->target_node = find_max_node(dst);
			src = src->next_node;
		}
	}
}

void	target_cbn_node(t_stack *src, t_stack *dst)
{
	t_stack	*current;
	int		target;

	if (dst)
	{
		while (src)
		{
			src->target_node = find_min_node(dst);
			current = dst;
			target = INT_MAX;
			while (current)
			{
				if (src->nbr < current->nbr && current->nbr < target)
				{
					target = current->nbr;
					src->target_node = current;
				}
				current = current->next_node;
			}
			if (target == INT_MAX)
				src->target_node = find_min_node(dst);
			src = src->next_node;
		}
	}
}

void	position_to_median(t_stack *head)
{
	int		len;

	len = num_of_nodes(head);
	if (len == 2)
	{
		head->above_median = true;
		head->next_node->above_median = false;
	}
	else
	{
		while (head)
		{
			if (head->index <= len / 2)
				head->above_median = true;
			else
				head->above_median = false;
			head = head->next_node;
		}
	}
}

void	is_cheapest(t_stack *head)
{
	t_stack	*current;
	int		min_cost;
	int		cheapest_index;

	min_cost = head->cost;
	cheapest_index = head->index;
	current = head;
	while (current)
	{
		if (current->cost < min_cost)
		{
			min_cost = current->cost;
			cheapest_index = current->index;
		}
		current = current->next_node;
	}
	while (cheapest_index-- > 0)
		head = head->next_node;
	head->cheapest = true;
}

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

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
