/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/16 14:41:26 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Makes first node last.
 */
void	rotate(t_stack **head, char *msg)
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
	if (msg)
		ft_putstr_fd(msg, 1);
}

/**
 * @brief Makes last node first.
 */
void	rev_rotate(t_stack **head, char *msg)
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
	if (msg)
		ft_putstr_fd(msg, 1);
}

/**
 * @brief Rotate both stacks at the same time.
 */
void	rr_rrr(t_stack **s1, t_stack **s2, void (*f)(t_stack **, char *), char *msg)
{
	f(s1, NULL);
	f(s2, NULL);
	ft_putstr_fd(msg, 1);
}

/**
 * @brief Swaps first and second node.
 */
void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	first = (*head);
	second = (*head)->next_node;
	first->next_node = second->next_node;
	second->next_node = first;
	*head = second;
	node_index(*head);
	position_to_median(*head);
	ft_putstr_fd("sa\n", 1);
}

/**
 * @brief Rule for pushing head node from src stack to dest stack.
 * 
 * @note When rev_flag = false, target_node is the closest smaller number (->b).
 * @note When rev_flag = true, target_node is the closest bigger number (a<-).
 */
void	push(t_stack **src_head, t_stack **dst_head, bool rev_flag, char *msg)
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
	if (!rev_flag)
		target_csn_node(*src_head, *dst_head);
	else
		target_cbn_node(*src_head, *dst_head);
	ft_putstr_fd(msg, 1);
}
