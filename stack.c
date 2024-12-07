/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:10:26 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/30 17:11:44 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	rotations(t_stack **a, t_stack *ptr, int target_index)
{
	int	iterations;
	int position;

	position = 1;
	while (ptr && ptr->target_pos != target_index)
	{
		ptr = ptr->next_nbr;
		position++;
	}
	if (position > 1 && position <= target_index / 2)
		iterations = position - 1;
	if (target_index != 1 && position > target_index / 2)
		iterations = target_index + 1 - position;
	while (iterations > 0)
	{
		if (position <= target_index / 2)
			rotate(a);
		else
			rev_rotate(a);
		iterations--;
	}
}


void	sort_stack(t_stack **a, t_stack **b, int target_index)
{
	t_stack	*current;

	while (*a)
	{
		current = *a;
		rotations(a, current, target_index);
		push_ab(a, b);
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
