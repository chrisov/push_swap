/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:50:23 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/22 16:33:14 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Allocates space for an (int) 2D matrix.
 * 
 * @param magnitude Order of magnitude of the biggest number of the array.
 * @param col_index Continuously traverses through the array.
 * 
 * @returns Matrix (int).
 */
static int	**buckets_alloc(int *array, int array_size)
{
	int		**matrix;
	int		magnitude;
	int		columns;
	int		col_index;

	magnitude = max_order_of_magnitude(array);
	matrix = malloc(magnitude * sizeof(int *));
	if (!matrix)
		return (NULL);
	while (magnitude > 0)
	{
		columns = 0;
		col_index = 0;
		while (col_index < array_size)
		{
			if (nbr_length(array[col_index]) == magnitude)
				columns++;
			col_index++;
		}
		if (columns > 0)
		{
			matrix[magnitude - 1] = malloc (columns * sizeof(int));
			if (!matrix[magnitude - 1])
				return (NULL);
		}
		else
			return (NULL);
		magnitude--;
	}
	return (matrix);
}

/**
 * @brief Uses the bubble sort algorithm to sort an array in ascending order.
 */
static void	bucket_sort(int *array, int array_size)
{
	int	temp;
	int	index;

	while (*array)
	{
		if (*array)
		{
			while (array_size >= 1)
			{
				index = 0;
				while (index < array_size - 1)
				{
					if (array[index] > array[index + 1])
					{
						temp = array[index];
						array[index] = array[index + 1];
						array[index + 1] = temp;
					}
					index++;
				}
				array_size--;
			}
		}
		array++;
	}
}

/**
 * @brief Initializes an (int) matrix with the values of an (int) array,
 * where each row contains the numbers of the array of the same order
 * of magnitude.
 */
static void	buckets_init(int *array, int array_size, int **matrix)
{
	int	index;
	int	column;
	int	magnitude;

	magnitude = max_order_of_magnitude(array);
	while (magnitude > 0)
	{
		if (matrix[magnitude - 1] == NULL)
		{
			magnitude--;
			continue ;
		}
		index = 0;
		column = 0;
		while (index < array_size)
		{
			if (nbr_length(array[index]) == magnitude)
				matrix[magnitude - 1][column++] = array[index];
			index++;
		}
		bucket_sort(matrix[magnitude - 1], column);
		magnitude--;
	}
}

/**
 * @brief Given an (int) *array allocates memory for an (int) 2D matrix,
 * initializes it, sorts each row in an ascending order and appends 
 * each row to an (int) *result.
 * 
 * @note array_size = argc - 1.
 * 	
 * @returns A sorted (int) *array.
 */
int	*buckets(int *array, int array_size)
{
	int	**buckets;
	int	*result;
	int	*ptr;

	buckets = buckets_alloc(array, array_size);
	buckets_init(array, array_size, buckets);
	result = malloc (array_size * sizeof(int));
	if (!result)
		return (0);
	ptr = result;
	while (*buckets)
	{
		while (**buckets)
			*ptr++ = *(*buckets)++;
		buckets++;
	}
	return (result);
}
