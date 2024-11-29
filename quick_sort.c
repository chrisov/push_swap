/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:50:23 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/29 16:59:02 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	left_index;
	int	right_index;

	pivot = arr[high];
	left_index = low;
	right_index = high - 1;
	while (left_index <= right_index)
	{
		while (left_index <= right_index && arr[right_index] >= pivot)
			right_index--;
		while (left_index <= right_index && arr[left_index] <= pivot)
			left_index++;
		if (left_index < right_index)
			swap_int(&arr[left_index], &arr[right_index]);	
	}
	swap_int(&arr[left_index], &arr[high]);
	return (left_index);
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

// #include <stdio.h>
// int	main(void)
// {
// 	int	arr[13] = {3, 17, 0, 4933, -10000, 17, 666, -1, 990, 22, -3321, 532, 83};
// 	int i;

// 	quick_sort(arr, 0, 13);
// 	i = 0;
// 	while (i < 13)
// 		printf("%d ", arr[i++]);
// 	printf("\n");
// 	return (0);
// }
