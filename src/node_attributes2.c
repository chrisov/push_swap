/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_attributes2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/21 14:08:30 by dchrysov         ###   ########.fr       */
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

/**
 * @brief Finds the node with the max value in the stack.
 */
t_stack	*find_max_node(t_stack *head)
{
	t_stack	*max;

	max = head;
	while (head)
	{
		if (head->nbr > max->nbr)
			max = head;
		head = head->next_node;
	}
	return (max);
}

/**
 * @brief Finds the node with the max value in the stack.
 */
t_stack	*find_min_node(t_stack *head)
{
	t_stack	*min;

	min = head;
	while (head)
	{
		if (head->nbr < min->nbr)
			min = head;
		head = head->next_node;
	}
	return (min);
}

/**
 * @brief Last step to bring the min value to the top of the stack.
 */
void	bring_min_top(t_stack **head)
{
	t_stack	*min;

	min = find_min_node(*head);
	while ((*head)->nbr != min->nbr)
	{
		if (min->above_median)
			rotate(head, "ra\n");
		else
			rev_rotate(head, "rra\n");
	}
}
