/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitris <dimitris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:50:23 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/17 20:45:53 by dimitris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Allocates space for an (int) 2D matrix.
 * 
 * @param magnitude Order of magnitude of the biggest number of the array.
 * @param i Continuously traverses through the array.
 * 
 * @returns Matrix (int).
 */
static int	**buckets_alloc(int *array, int size)
{
	int		**matrix;
	int		magnitude;
	int		columns;
	int		i;

	magnitude = max_order_of_magnitude(array);
	matrix = malloc(magnitude * sizeof(int *));
	if (!matrix)
		return (NULL);
	while (magnitude > 0)
	{
		columns = 0;
		i = 0;
		while (i < size)
		{
			if (nbr_length(array[i]) == magnitude)
				columns++;
			i++;
		}
		if (columns > 0)
			matrix[magnitude - 1] = malloc (columns * sizeof(int));
		else
			return (NULL);
		if (!matrix[magnitude - 1])
			return (NULL);
		magnitude--;
	}
	return (matrix);
}

/**
 * @brief Initializes an (int) matrix with the values of an (int) array,
 * where each row contains the numbers of the array of the same order
 * of magnitude.
 */
static void	buckets_init(int *array, int size, int **matrix)
{
	int	i;
	int	column;
	int	magnitude;

	magnitude = max_order_of_magnitude(array);
	while (magnitude > 0)
	{
		i = 0;
		column = 0;
		if (matrix[magnitude - 1] == NULL)
		{
			magnitude--;
			continue ;
		}
		while (i < size)
		{
			if (nbr_length(array[i]) == magnitude)
			{
				matrix[magnitude - 1][column] = array[i];
				column++;
			}
			i++;
		}
		magnitude--;
	}
}

static void	bucket_sort(int **matrix)
{
	int	temp;
	int	row;
	int	src_index;
	int	dst_index;

	row = 0;
	while (matrix[row])
	{
		src_index = 0;
		dst_index = 1;
		while (matrix[row][dst_index])
		{
			if (matrix[row][src_index] < matrix[row][dst_index])
			{
				if (dst_index == src_index + 1)
				{
					src_index = 0;
					dst_index++;
				}
				else
					src_index++;
			}
			else
			{
				temp = matrix[row][dst_index];
				matrix[row][dst_index] = matrix[row][src_index];
				matrix[row][src_index] = temp;
				if (dst_index == src_index + 1)
				{
					src_index = 0;
					dst_index++;
				}
				else
					src_index++;
			}
		}
		row++;
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

	buckets = buckets_alloc(array, array_size);
	buckets_init(array, array_size, buckets);
	bucket_sort(buckets);
	result = malloc (array_size * sizeof(int));
	if (!result)
		return (0);
	while (buckets)
	{
		*result = **buckets;
		result++;
		buckets++;
	}
	return (result);
}
