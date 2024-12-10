/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/03 12:58:00 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_atoi(const char *str)
{
	int	res;
	int	count;
	int	sign;

	res = 0;
	count = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		if (count > 0)
			return (0);
		str++;
		count++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}

static t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = value;
	node->next_nbr = NULL;
	return (node);
}

void	stack_init(t_stack **head, char **array)
{
	t_stack	*current;

	array++;
	(*head) = new_node(ft_atoi(*array));
	current = (*head);
	array++;
	while (*array)
	{
		current->next_nbr = new_node(ft_atoi(*array++));
		current = current->next_nbr;
	}
}

void	sort_stack_of_three(t_stack **head)
{
	int	first;
	int	second;
	int	third;

	first = (*head)->nbr;
	second = (*head)->next_nbr->nbr;
	third = (*head)->next_nbr->next_nbr->nbr;
	if (second > first && second > third)
	{
		rev_rotate(head);
		if (first < third)
			swap(head);
	}
	if (first > second && first > third)
	{
		if (second > third)
		{
			swap(head);
			rev_rotate(head);
		}
		else
			rotate(head);
	}
	if (third > second && third > first && first > second)
		swap(head);
}

int	num_of_nodes(t_stack *head)
{
	int	result;

	result = 0;
	while (head)
	{
		result++;
		head = head->next_nbr;
	}
	return (result);
}

void	print_node(t_stack *head)			//<-------- PRINTF
{
	t_stack	*node;

	if (!head)
		printf("NULL");
	else
	{
		node = head;
		while (node)
		{
			printf("%d[->%d] -> ", node->nbr, node->target_position);
			node = node->next_nbr;
		}
		printf("NULL\n");
	}
}