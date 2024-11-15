/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitris <dimitris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:10:26 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/15 00:58:27 by dimitris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value, int position)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = value;
	node->current_pos = position;
	node->sign = nbr_sign(value);
	node->length = nbr_length(value);
	node->next_nbr = NULL;
	return (node);
}

t_stack	*stack_init(char **value)
{
	t_stack	*s;
	t_stack	*ptr;
	int		counter;

	counter = 1;
	value++;
	s = new_node(ft_atoi(*value), counter++);
	ptr = s;
	value++;
	while (*value)
	{
		ptr->next_nbr = new_node(ft_atoi(*value++), counter++);
		ptr = ptr->next_nbr;

	}
	return (s);
}

void	print_node(t_stack *head)			//<-------- PRINTF
{
	t_stack	*node;

	node = head;
	while (node != NULL)
	{
		printf("stack[%d]: value= %d\tlength= %d\tsign= %s\n", node->current_pos, node->nbr, node->length, node->sign);
		node = node->next_nbr;
	}
}
