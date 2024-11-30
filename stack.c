/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:10:26 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/30 14:35:38 by dchrysov         ###   ########.fr       */
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

static int	number_of_duplicates(t_stack *stack, int value)
{
	int	result;

	result = 0;
	while (stack)
	{
		if (stack->nbr == value)
			result++;
		stack = stack->next_nbr;
	}
	return (result);
}

/**
 * @brief Create a new node in the stack and init most of its attributes.
 * 
 * @param value The value given to the node.
 * @param position Position of the node in the stack.
 * 
 * @returns The newly created node.
 */
static t_stack	*new_node(int value, int target_pos)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = value;
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
	t_stack	*current;
	int		target_pos;
	int		i;
	int		duplicates;

	i = 0;
	target_pos = target_position(array[i], sorted_array);
	s = new_node(array[i], target_pos);
	i++;
	current = s;
	while (i < array_size)
	{
		duplicates = number_of_duplicates(s, array[i]);
		target_pos = target_position(array[i], sorted_array) + duplicates;
		current->next_nbr = new_node(array[i], target_pos);
		current = current->next_nbr;
		i++;
	}
	return (s);
}

void	sort_stack(t_stack **a, t_stack **b, int target_index)
{
	t_stack	*current;
	int		position;
	int		iterations;

	while (target_index > 0)
	{
		current = *a;
		position = 1;
		while (current && current->target_pos != target_index)
		{
			current = current->next_nbr;
			position++;
		}
		if (position < target_index / 2)
			iterations = position;
		else
			iterations = target_index + 2 - position;
		while (iterations > 1)
		{
			if (position < target_index / 2)
				rotate(a);							//<----- rotate (init_pos - 1)  times
			else
				rev_rotate(a);
			iterations--;
		}
		printf("\"position: %d\"\n", position);
		print_nodes(*a, *b);
		push_ab(a, b);
		print_nodes(*a, *b);
		printf("\n\n");
		target_index--;
	}
}

void	print_nodes(t_stack *a_head, t_stack *b_head)			//<-------- PRINTF
{
	while (a_head)
	{
		if (!a_head)
		{
			printf("\t\t\t%d\n", b_head->nbr);
			b_head = b_head->next_nbr;
		}
		if (!b_head)
		{
			printf("%d\t[->%d] \t\t\n", a_head->nbr, a_head->target_pos);
			a_head = a_head->next_nbr;
		}
		if (a_head && b_head)
		{
			printf("%d\t[->%d] \t\t%d\n", a_head->nbr,a_head->target_pos, b_head->nbr);
			a_head = a_head->next_nbr;
			b_head = b_head->next_nbr;
		}
	}
	printf("_\t\t\t_\n");
	printf("a\t\t\tb\n\n\n\n");
}

void	print_node(t_stack *head)			//<-------- PRINTF
{
	t_stack	*node;
	int		i = 1;

	node = head;
	while (node)
	{
		printf("[%d]:\t%d\t[->%d]\n", i++, node->nbr, node->target_pos);
		node = node->next_nbr;
	}
}
