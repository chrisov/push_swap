/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/10 12:42:33 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	target_value(t_stack *src, t_stack *dst)
{
	t_stack	*current;
	int		csn;

	while (src)
	{
		current = dst;
		csn = INT_MIN;
		while (current)
		{
			if (src->nbr > current->nbr && current->nbr > csn)
				csn = current->nbr;
			current = current->next_nbr;
		}
		if (csn == INT_MIN)
			src->target_position = max_value_node(dst);
		else
			src->target_position = csn;
		src = src->next_nbr;
	}
}

int	cost_calc(t_stack *src, t_stack *dest)
{
	int	cost;
	int	src_cost;
	int	dest_cost;
	int	cost_index;

	src_cost = 0;
	cost = num_of_nodes(src) / 2 + num_of_nodes(dest) / 2;
	while (src)
	{
		if (src->target_position <= num_of_nodes(dest) / 2)
			dest_cost = src->target_position;
		else
			dest_cost = num_of_nodes(dest) - src->target_position;
		if (src_cost + dest_cost < cost)
		{
			cost = src_cost + dest_cost;
			cost_index = src_cost;
		}
		src_cost++;
		src = src->next_nbr;
	}
	return (cost_index);
}

int	max_value_node(t_stack *head)
{
	int max;
	
	max = head->nbr;
	while (head)
	{
		if (head->nbr > max)
			max = head->nbr;
		head = head->next_nbr;
	}
	return (max);
}

int	max_index_node(t_stack *head)
{
	int max;
	int	i;
	int	result;

	i = 0;
	result = i;
	max = head->nbr;
	while (head)
	{
		if (head->nbr > max)
		{
			result = i;
			max = head->nbr;
		}
		i++;
		head = head->next_nbr;
	}
	return (result);
}

