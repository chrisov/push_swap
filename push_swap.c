/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:10:26 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/14 17:16:09 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>									// <-----------------------

void	*init_stack(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = value;
	node->next_nbr = NULL;
	return (node);
}

void	print_stack(t_stack *head)
{
	t_stack	*node;

	node = head;
	while (node != NULL)
	{
		printf("\n%d", node->nbr);
		node = node->next_nbr;
	}
	printf("\nNULL\n\n");
}

int	main(int argc, char **argv)
{
	t_stack	*head;

	head = NULL;
	if (argc == 1)
		return (0);
	else
	{
		argv++;
		while (*argv)
		{
			head = (t_stack*) init_stack(ft_atoi(*argv));
			argv++;
		}
	}
	print_stack(head);
	return (0);
}