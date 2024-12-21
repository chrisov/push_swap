/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/21 15:12:14 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Creates a new node and initializes with the given value.
 */
static t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = value;
	node->next_node = NULL;
	node->previous_node = NULL;
	node->cheapest = false;
	return (node);
}

/**
 * @brief Initialization of stack.
 */
void	stack_init(t_stack **head, char **array)
{
	t_stack	*current;
	t_stack	*temp;

	(*head) = new_node(ft_atoi(*array));
	(*head)->i = 0;
	current = (*head);
	array++;
	while (*array)
	{
		temp = current;
		current->next_node = new_node(ft_atoi(*array));
		current = current->next_node;
		current->previous_node = temp;
		current->i = current->previous_node->i + 1;
		array++;
	}
	if (already_sorted(*head))
		exit(0);
}

/**
 * @brief Counts the number of nodes in a stack
 */
int	stck_len(t_stack *head)
{
	int	result;

	result = 0;
	while (head)
	{
		result++;
		head = head->next_node;
	}
	return (result);
}

/**
 * @brief Sorts a stack of two nodes.
 */
void	sort_stack_of_two(t_stack **head)
{
	if ((*head)->nbr > (*head)->next_node->nbr)
		swap(head);
}

/**
 * @brief Sorts a stack of three nodes.
 */
void	sort_stack_of_three(t_stack **head)
{
	int	first;
	int	second;
	int	third;

	first = (*head)->nbr;
	second = (*head)->next_node->nbr;
	third = (*head)->next_node->next_node->nbr;
	if (second > first && second > third)
	{
		rev_rotate(head, "rra\n");
		if (first < third)
			swap(head);
	}
	if (first > second && first > third)
	{
		if (second > third)
		{
			swap(head);
			rev_rotate(head, "rra\n");
		}
		else
			rotate(head, "ra\n");
	}
	if (third > second && third > first && first > second)
		swap(head);
}
