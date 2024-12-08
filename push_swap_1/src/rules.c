/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/03 12:58:00 by dchrysov         ###   ########.fr       */
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
	*head = (*head)->next_nbr;
	current = *head;
	while (current->next_nbr)
		current = current->next_nbr;
	current->next_nbr = first;
	first->next_nbr = NULL;
	write(STDOUT_FILENO, "ra\n", 3);
}

/**
 * @brief Makes last node the first.
 */
void	rev_rotate(t_stack **head)
{
	t_stack	*previous;
	t_stack	*current;

	current = *head;
	while (current->next_nbr)
	{
		previous = current;
		current = current->next_nbr;
	}
	previous->next_nbr = NULL;
	current->next_nbr = *head;
	*head = current;
	write(STDOUT_FILENO, "rra\n", 4);
}

void	push_ab(t_stack **src_head, t_stack **dst_head)
{
	t_stack	*new_head;

	new_head = *src_head;
	*src_head = (*src_head)->next_nbr;
	new_head->next_nbr = (*dst_head);
	*dst_head = new_head;
}

void	swap(t_stack **head)
{
	t_stack *temp;

	temp = *head;
	(*head) = (*head)->next_nbr;
	(*head)->next_nbr = temp;
	temp->next_nbr = temp->next_nbr->next_nbr;
}