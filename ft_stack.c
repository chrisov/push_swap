/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitris <dimitris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:10:26 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/15 03:24:47 by dimitris         ###   ########.fr       */
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
	node->current_pos = position_count;
	node->sign = nbr_sign(value);
	node->length = nbr_length(value);
	node->next_nbr = NULL;
	return (node);
}

t_stack	*stack_init(char **array, int array_size)
{
	t_stack	*s;
	t_stack	*ptr;
	int		position_count;
	int		maxlen;

	position_count = 1;
	array++;
	maxlen = array_max_len(array);
	s = new_node(ft_atoi(*array++), position_count++);
	target_position(s, array_size, maxlen);
	ptr = s;
	while (*array)
	{
		ptr->next_nbr = new_node(ft_atoi(*array++), position_count++);
		target_position(ptr, array_size, maxlen);
		ptr = ptr->next_nbr;
	}
	return (s);
}

/**
 * @param size Size of stack
 * @param max_len Number digits of the biggest number in the stack.
 */
void	target_position(t_stack *node, int size, int max_len)
{
	t_stack	*ptr;
	int		length;
	int		position;
	int		digit;

	ptr = node;
	length = max_len;
	position = size;
	while (ptr)
	{
		if (ptr->length == length)
		{
			digit = 9;
			while (digit >= 0)
			{
				if ((ft_itoa(ptr->nbr)[length - 1] - '0') == digit)
				{
					ptr->target_pos = position;
					position--;
					break ;
				}
				digit--;
			}
			length--;
		}
		ptr = ptr->next_nbr;
	}
}

void	print_node(t_stack *head)			//<-------- PRINTF
{
	t_stack	*node;

	node = head;
	while (node)
	{
		printf("stack[%d]: value= %d\ttarget= %d\n", node->current_pos, node->nbr, node->target_pos);
		node = node->next_nbr;
	}
}
