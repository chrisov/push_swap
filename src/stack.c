/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/10 12:42:35 by dchrysov         ###   ########.fr       */
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
	node->next_node = NULL;
	node->previous_node = NULL;
	node->cheapest = false;
	return (node);
}

/**
 * @brief Initialization of stack.
 */
void	stack_init(t_stack **head, char **array)
{
	t_stack	*current;
	t_stack *temp;

	array++;
	(*head) = new_node(ft_atoi(*array));
	(*head)->index = 0;
	current = (*head);
	array++;
	while (*array)
	{
		temp = current;
		current->next_node = new_node(ft_atoi(*array));
		current = current->next_node;
		current->previous_node = temp;
		current->index = current->previous_node->index + 1;
		array++;
	}
}

/**
 * @brief Counts the number of nodes in a stack
 */
int	num_of_nodes(t_stack *head)
{
	int	result;

	result = 0;
	while (head)
	{
		result++;
		head = head->next_node;
	}
	return (result);
}


void	sort_stack_of_three(t_stack **head)
{
	int	first;
	int	second;
	int	third;

	first = (*head)->nbr;
	second = (*head)->next_node->nbr;
	third = (*head)->next_node->next_node->nbr;
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

void	print_nodes(t_stack *src, t_stack *dest)			//<-------- PRINTF
{
	if (dest)
	{
		while (src)
		{
			printf("(%d): %d[%d]\t->[%d] ",src->cost, src->nbr, src->index, src->target_node->index);
			if (src->above_median)
				printf("(above median)");
			else
				printf("(below median)");
			if (src->cheapest)
				printf(" (cheapest)\t\t");
			else
				printf("\t\t\t");
			if (dest)
			{
				printf("%d[%d]\t", dest->nbr, dest->index);
				if (dest->above_median == true)
					printf("(above median)");
				else
					printf("(below median)");
				dest = dest->next_node;
			}
			else
				printf(" ");
			printf("\n");
			src = src->next_node;
		}
	}
	else
	{
		while (src)
		{
			printf("(%d): %d[%d]\t", src->cost, src->nbr, src->index);
			if (src->above_median == true)
				printf("(above median)");
			else
				printf("(below median)");
			printf("\n");
			src = src->next_node;
		}
	}
}

void	print_node(t_stack *head)
{
	while (head)
	{
		printf("%d[%d] -> [%d]\n", head->nbr, head->index, head->target_node->nbr);
		head = head->next_node;
	}
}