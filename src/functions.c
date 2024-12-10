/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/10 14:53:20 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	target_position(t_stack *src, t_stack *dst)
{
	t_stack	*current;
	int		csn;
	int		csn_index;

	while (src)
	{
		current = dst;
		csn = INT_MIN;
		csn_index = 0;
		while (current)
		{
			if (src->nbr > current->nbr && current->nbr > csn)
			{
				csn = current->nbr;
				src->target_position = csn_index;
			}
			csn_index++;
			current = current->next_nbr;
		}
		if (csn == INT_MIN)
			src->target_position = max_index_node(dst);
		src = src->next_nbr;
	}
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

