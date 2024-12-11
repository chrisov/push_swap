/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/11 11:56:41 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_max_node(t_stack *head)
{
	t_stack *max;
	
	max = head;
	while (head)
	{
		if (head->nbr > max->nbr)
			max = head;
		head = head->next_node;
	}
	return (max);
}

t_stack	*find_min_node(t_stack *head)
{
	t_stack *min;
	
	min = head;
	while (head)
	{
		if (head->nbr < min->nbr)
			min = head;
		head = head->next_node;
	}
	return (min);
}
