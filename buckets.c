/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:50:23 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/22 20:17:05 by dchrysov         ###   ########.fr       */
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
static int	**buckets_alloc(int *array, int array_size, int *total_cols)
{
	int		**matrix;
	int		magnitude;
	int		column;
	int		col_index;

	magnitude = max_order_of_magnitude(array, array_size);
	total_cols += magnitude - 1;
	matrix = malloc(magnitude * sizeof(int *));
	if (!matrix)
		return (NULL);
	while (magnitude > 0)
	{
		column = 0;
		col_index = 0;
		while (col_index < array_size)
		{
			if (nbr_length(array[col_index]) == magnitude)
				column++;
			col_index++;
		}
		if (column > 0)
		{
			matrix[magnitude - 1] = malloc (column * sizeof(int));
			if (!matrix[magnitude - 1])
				return (NULL);
			*total_cols-- = column;
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

	magnitude = max_order_of_magnitude(array, array_size);
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

static int	*sorted_array(int *array, int **matrix, int row_nbr, int *col_nbr)
{
	int	row;
	int	column;
	int	i;

	row = 0;
	i = 0;
	while (row < row_nbr)
	{
		column = 0;
		while (column < *col_nbr)
			array[i++] = matrix[row][column++];
		row++;
		col_nbr++;
	}
	return (array);
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
	int	*cols_nbr;
	int	*result;
	int	rows_nbr;

	rows_nbr = max_order_of_magnitude(array, array_size);
	cols_nbr = malloc(rows_nbr * sizeof(int));
	if (!cols_nbr)
		return (NULL);
	buckets = buckets_alloc(array, array_size, cols_nbr);
	buckets_init(array, array_size, buckets);
	result = malloc (array_size * sizeof(int));
	if (!result)
		return (NULL);
	result = sorted_array(result, buckets, rows_nbr, cols_nbr);
	return (result);
}
