/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:10:26 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/16 13:14:38 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Create a new node in the stack and init most of its attributes.
 * 
 * @param value The value given to the node.
 * @param position Position of the node in the stack.
 * 
 * @returns The newly created node.
 */
t_stack	*new_node(int value, int position)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = value;
	node->init_pos = position;
	node->sign = nbr_sign(value);
	node->length = nbr_length(value);
	node->next_nbr = NULL;
	return (node);
}

/**
 * @brief Initializes a stack, given an array of str.
 * 
 * @param s The stack to be returned.
 * @param ptr Points to the stack and is used to traverse the array and
 * create the nodes. 
 * @param init_pos_count Increments every time a node is created.
 * @param max_magn The order of magnitude of the biggest number in the array.
 * 
 * @returns s.
 */
t_stack	*stack_init(char **array)
{
	t_stack	*s;
	t_stack	*ptr;
	int		init_pos_count;
	int		max_magn;

	init_pos_count = 1;
	array++;
	max_magn = max_order_of_magn(array);
	s = new_node(ft_atoi(*array), init_pos_count++);
	array++;
	ptr = s;
	while (*array)
	{
		ptr->next_nbr = new_node(ft_atoi(*array), init_pos_count++);
		ptr = ptr->next_nbr;
		array++;
	}
	target_position(s,	max_magn);
	return (s);
}

/**
 * @brief Determines the target_position of each node in the stack.
 * 
 * @param magnitude Order of magnitude of the biggest number.
 * @param max_len Number digits of the biggest number in the stack.
 */
void	target_position(t_stack *node, int magnitude)
{
	t_stack	*ptr;
	int		**buckets;

	ptr = node;
	buckets = buckets_alloc(ptr, magnitude);
	ptr = node;
	buckets = buckets_init(ptr, magnitude);
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
