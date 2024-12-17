/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/17 19:05:24 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

/**
 * @brief Checks if the input arr is already sorted.
 */
bool	already_sorted(t_stack *head)
{
	while (head->next_node)
	{
		if (head->nbr > head->next_node->nbr)
			return (false);
		head = head->next_node;
	}
	return (true);
}

void	free_list(t_stack **head, char **array, int len)
{
	t_stack	*current;
	t_stack	*next;
	char	**ptr;

	if (len == 2)
	{
		ptr = array;
		while (*ptr)
		{
			free(*ptr);
			ptr++;
		}
		free(array);
	}
	current = *head;
	while (current != NULL)
	{
		next = current->next_node;
		free(current);
		current = next;
	}
	*head = NULL;
}
