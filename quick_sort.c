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

void swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	left_item;
	int	right_item;

	pivot = arr[high];
	left_item = low;
	right_item = high - 1;
	while (left_item < right_item)
	{
		while (arr[right_item] >= pivot)
			right_item--;
		while (arr[left_item] <= pivot)
			left_item++;
		if (left_item < right_item)
			swap_int(&arr[left_item], &arr[right_item]);	
	}
	swap_int(&arr[left_item], &arr[high]);
	return (left_item);
}

void	quick_sort(int *arr, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}

#include <stdio.h>
int	main(void)
{
	int	arr[13] = {3, 17, 0, 4933, -10000, 17, 666, -1, 990, 22, -3321, 532, 83};
	int i;
	// int	pivot;

	// pivot = partition(arr, 0, 12);
	quick_sort(arr, 0, 12);
	i = 0;
	while (i < 13)
		printf("%d ", arr[i++]);
	printf("\n");
	return (0);

}
