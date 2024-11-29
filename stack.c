/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:10:26 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/29 13:42:57 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculates the target position of each node
 */
static int	target_position(int value, int *sorted_array)
{
	int	i;
	int	target_index;

	i = 0;
	target_index = 1;
	while (sorted_array[i++] != value)
		target_index++;
	return (target_index);
}

/**
 * @brief Create a new node in the stack and init most of its attributes.
 * 
 * @param value The value given to the node.
 * @param position Position of the node in the stack.
 * 
 * @returns The newly created node.
 */
t_stack	*new_node(int value, int position, int target_pos)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = value;
	node->init_pos = position;
	node->length = nbr_length(value);
	node->target_pos = target_pos;
	node->next_nbr = NULL;
	return (node);
}

/**
 * @brief Initializes a stack, given an array of str.
 * 
 * @param s The stack to be returned.
 * @param ptr Points to the stack and is used to traverse the array and
 * create the nodes. 
 * @param init_pos Increments every time a node is created.
 * @param max_magn The order of magnitude of the biggest number in the array.
 * 
 * @returns s.
 */
t_stack	*stack_init(int *array, int array_size, int *sorted_array)
{
	t_stack	*s;
	t_stack	*s_ptr;
	int		init_pos;
	int		target_pos;
	int		i;

	i = 0;
	init_pos = 1;
	target_pos = target_position(array[i], sorted_array);
	s = new_node(array[i], init_pos++, target_pos);
	i++;
	s_ptr = s;
	while (i < array_size)
	{
		target_pos = target_position(array[i], sorted_array);
		s_ptr->next_nbr = new_node(array[i], init_pos++, target_pos);
		s_ptr = s_ptr->next_nbr;
		i++;
	}
	return (s);
}

void	print_node(t_stack *head)			//<-------- PRINTF
{
	t_stack	*node;

	node = head;
	while (node)
	{
		printf("stack[%d]:\t\tvalue= %d\t\ttarget= %d\n", node->init_pos, node->nbr, node->target_pos);
		node = node->next_nbr;
	}
}
