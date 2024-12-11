/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/11 12:27:51 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/**
 * @brief Makes first node the last.
 */
void	rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*current;

	first = *head;
	*head = (*head)->next_node;
	current = *head;
	while (current->next_node)
		current = current->next_node;
	current->next_node = first;
	first->next_node = NULL;
	node_index(*head);
	position_to_median(*head);
}

/**
 * @brief Makes last node the first.
 */
void	rev_rotate(t_stack **head)
{
	t_stack	*previous;
	t_stack	*current;

	current = *head;
	while (current->next_node)
	{
		previous = current;
		current = current->next_node;
	}
	previous->next_node = NULL;
	current->next_node = *head;
	*head = current;
	node_index(*head);
	position_to_median(*head);
}

/**
 * @brief (Reverse) rotate both stacks at the same time.
 */
void	rr_rrr(t_stack **stack1, t_stack **stack2, void (*f)(t_stack **))
{
	f(stack1);
	f(stack2);
}

/**
 * @brief Swaps first and second node.
 */
void	swap(t_stack **head)
{
	t_stack *first;
	t_stack	*second;

	first = (*head);
	second = (*head)->next_node;
	first->next_node = second->next_node;
	second->next_node = first;
	*head = second;
	node_index(*head);
	position_to_median(*head);
}

void	push_ab(t_stack **src_head, t_stack **dst_head)
{
	t_stack	*new_head;

	new_head = *src_head;
	*src_head = (*src_head)->next_node;
	new_head->next_node = (*dst_head);
	*dst_head = new_head;
	node_index(*src_head);
	node_index(*dst_head);
	position_to_median(*src_head);
	position_to_median(*dst_head);
	target_node(*src_head, *dst_head);
}
