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
 * @param rows Order of rows of the biggest number of the array.
 * @param array_index Continuously traverses through the array.
 * 
 * @returns Matrix (int).
 */
static int	**buckets_alloc(int *array, int array_size, int *bucket_cols)
{
	int		**matrix;
	int		rows;
	int		column;
	int		array_index;

	rows = count_of_buckets(array, array_size);
	matrix = calloc(rows , sizeof(int *));
	if (!matrix)
		return (NULL);
	bucket_cols += rows - 1;
	while (rows > 0)
	{
		column = 0;
		array_index = 0;
		while (array_index < array_size)
		{
			if (nbr_length(array[array_index]) == rows)
				column++;
			array_index++;
		}
		if (column > 0)
		{
			matrix[rows - 1] = calloc (column , sizeof(int));
			if (!matrix[rows - 1])
				return (NULL);
			*bucket_cols-- = column;
		}
		else
			*bucket_cols-- = 0;
		int j = 0;
		while (j <= column)
			printf("%d ", matrix[rows][j++]);
		printf("\n");
		rows--;
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
 * of rows.
 */
static void	buckets_init(int *array, int array_size, int **matrix)
{
	int	array_index;
	int	column;
	int	rows;

	rows = count_of_buckets(array, array_size);
	while (rows > 0)
	{
		if (matrix[rows - 1] == NULL)
		{
			rows--;
			continue ;
		}
		array_index = 0;
		column = 0;
		while (array_index < array_size)
		{
			if (nbr_length(array[array_index]) == rows)
				matrix[rows - 1][column++] = array[array_index];
			array_index++;
		}
		bucket_sort(matrix[rows - 1], column);
		rows--;
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
	int	rows_nbr;
	int	*cols_nbr;
	int	*result;
	int	**buckets;

	rows_nbr = count_of_buckets(array, array_size);
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
