/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/03 13:03:31 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	target_position(t_stack *src, t_stack *dst)
{
	t_stack	*current;
	int		csn;
	int		csn_i;
	int		i;

	while (src)
	{
		current = dst;
		csn_i = max_index_node(current);
		csn = max_value_node(current);
		i = 0;
		while (current)
		{
			if (src->nbr > current->nbr && current->nbr < csn && 
				src->nbr - current->nbr > src->nbr - csn && src->nbr < csn)
			{
					csn = current->nbr;
					csn_i = i;
			}
			i++;
			current = current->next_nbr;
		}
		src->target_position = csn_i;
		src = src->next_nbr;
	}
}

int	cost_calc(t_stack *src, t_stack *dest)
{
	int	cost;
	int	src_cost;
	int	dest_cost;
	int cost_index;
	
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

