/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:10:26 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/12 15:19:06 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

struct s_Node
{
	int				nbr;
	struct s_Node	*next;
};

static void	init_llist(struct s_Node **head, int number)
{
	struct s_Node	*node;

	node = (struct s_Node *)malloc(sizeof(struct s_Node));
	node->nbr = number;
	node->next = *head;
	*head = node;
}

void	print_llist(struct s_Node *head)
{
	struct s_Node	*current;

	current = head;
	while (current != NULL)
	{
		printf("\n%d", current->nbr);
		current = current->next;
	}
	printf("\nNULL\n\n");
}

int	main(int argc, char **argv)
{
	struct s_Node	*head;

	head = NULL;
	if (argc == 1)
		return (0);
	else
	{
		argv++;
		while (*argv)
		{
			init_llist(&head, ft_atoi(*argv));
			argv++;
		}
	}
	print_llist(head);
	return (0);
}