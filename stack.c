/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:10:26 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/29 17:21:03 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculates the target position of each node.
 * 
 * @param value The value-number of the node.
 * @param sorted_array Array to be searched for each value that corresponds to
 * a specific node.
 * 
 * @returns The index of the value-number in the sorted array.
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

void	print_node(t_stack *a_head, t_stack *b_head)			//<-------- PRINTF
{
	while (a_head || b_head)
	{
		if (!a_head)
		{
			printf("\t\t\t%d\n", b_head->nbr);
			b_head = b_head->next_nbr;
		}
		if (!b_head)
		{
			printf("%d\t\t\t\n", a_head->nbr);
			a_head = a_head->next_nbr;
		}
		if (a_head && b_head)
		{
			printf("%d\t\t%d\n", a_head->nbr, b_head->nbr);
			a_head = a_head->next_nbr;
			b_head = b_head->next_nbr;
		}
	}
	printf("_\t\t_\n");
	printf("a\t\tb\n\n");
}
