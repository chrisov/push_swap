/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/17 19:05:24 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	already_sorted(t_stack *head)
{
	while (head->next_node)
	{
		if (head->nbr > head->next_node->nbr)
			return (false);
		head = head->next_node;
	}
	return (true);
}

void	free_array(char **array)
{
	char	**ptr;

	ptr = array;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(array);
}

void	free_stack(t_stack **head)
{
	t_stack	*current;
	t_stack	*next;

	current = *head;
	while (current)
	{
		next = current->next_node;
		free(current);
		current = next;
	}
	*head = NULL;
}
