/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitris <dimitris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:10:26 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/16 01:15:30 by dimitris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value, int position_count)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = value;
	node->init_pos = position_count;
	node->sign = nbr_sign(value);
	node->length = nbr_length(value);
	node->next_nbr = NULL;
	return (node);
}

t_stack	*stack_init(char **array)
{
	t_stack	*s;
	t_stack	*ptr;
	int		init_pos_count;
	int		maxdigit;

	init_pos_count = 1;
	array++;
	maxdigit = array_max_digits(array);
	s = new_node(ft_atoi(*array), init_pos_count++);
	array++;
	ptr = s;
	while (*array)
	{
		ptr->next_nbr = new_node(ft_atoi(*array), init_pos_count++);
		ptr = ptr->next_nbr;
		array++;
	}
	target_position(s, maxdigit);
	return (s);
}

/**
 * @param size Size of stack
 * @param max_len Number digits of the biggest number in the stack.
 */
void	target_position(t_stack *node, int digits)
{
	t_stack	*ptr;
	int		**buckets;

	ptr = node;
	buckets = buckets_alloc(ptr, digits);
	ptr = node;
	buckets = buckets_init(ptr, digits);
}

void	print_node(t_stack *head)			//<-------- PRINTF
{
	t_stack	*node;

	node = head;
	while (node)
	{
		printf("stack[%d]: value= %d\ttarget= %d\n", node->init_pos, node->nbr, node->target_pos);
		node = node->next_nbr;
	}
}
