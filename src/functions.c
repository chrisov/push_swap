/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:18:11 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/09 14:19:34 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_min(t_stack *head)
{
	int	min;

	min = head->nbr;
	while (head)
	{
		if (head->nbr < min)
			min = head->nbr;
		head = head->next_nbr;
	}
	return (min);
}

int	stack_max(t_stack *head)
{
	int	max;

	max = head->nbr;
	while (head)
	{
		if (head->nbr > max)
			max = head->nbr;
		head = head->next_nbr;
	}
	return (max);
}
