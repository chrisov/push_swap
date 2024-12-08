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

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = value;
	node->next_nbr = NULL;
	return (node);
}

void	sort_stack_of_three(t_stack **head)
{
	int	first;
	int	second;
	int	third;

	first = (*head)->nbr;
	second = (*head)->next_nbr->nbr;
	third = (*head)->next_nbr->next_nbr->nbr;
	if (second > first && second > third)
	{
		rev_rotate(head);
		if (first < third)
			swap(head);
	}
	if (first > second && first > third)
	{
		if (second > third)
		{
			swap(head);
			rev_rotate(head);
		}
		else
			rotate(head);
	}
	if (third > second && third > first && first > second)
		swap(head);
}

void	print_node(t_stack *head)			//<-------- PRINTF
{
	t_stack	*node;

	node = head;
	while (node)
	{
		printf("%d -> ", node->nbr);
		node = node->next_nbr;
	}
	printf("NULL\n");
}
