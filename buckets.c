/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:50:23 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/16 12:51:49 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**buckets_alloc(t_stack *s, int magnitude)
{
	int		**array;
	int		size;
	int		columns;
	t_stack	*ptr;

	array = malloc(magnitude * sizeof(int *));
	if (!array)
		return (0);
	size = magnitude;
	while (size >= 1)
	{
		columns = 0;
		ptr = s;
		while (ptr)
		{
			if (ptr->length == size)
				columns++;
			ptr = ptr->next_nbr;
		}
		array[size - 1] = malloc (columns * sizeof(int));
		if (!array[size - 1])
			return (0);
		size--;
	}
	return (array);
}

int	**buckets_init(t_stack *ptr, int magnitude)
{
	int	columns;
	int	**array;

	while (magnitude >= 1)
	{
		while (ptr)
		{
			columns = 0;
			if (ptr->length == magnitude)
			{
				array[magnitude - 1][columns] = ptr->nbr;
				columns++;
			}
			ptr = ptr->next_nbr;
		}
		magnitude--;
	}
}

void	bucket_sort(int **array)
{
	while (*array)
	{

	}
}