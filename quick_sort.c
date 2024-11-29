/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:50:23 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/29 13:29:20 by dchrysov         ###   ########.fr       */
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
// 	int	arr[100] = {-20126, 22197, 16477, -51386, -54401, 5259, -97025, 96376, -71723, -78841, -72153, -94412, 16850, -62317, 32996, 11635, -80129, 55595, 87458, 8685, 65521, 75458, -69621, 27169, 45693, -1387, -15335, -75002, -13248, -96559, 65283, -13679, 9599, -91202, 29838, -45508, 13509, -53948, 97814, -76714, 51568, -50693, -58683, -13630, 23821, 30736, -3965, 97875, 53288, 80324, -55390, 54968, -86823, -74721, -12896, -41055, -71941, 84469, -62000, -98445, 89778, -70510, 35549, 49009, -53562, 81534, 79864, -85168, -61925, -34038, -57874, 20720, -23074, -58051, 3902, 40471, -48390, -7265, 83690, 51531, 52784, -87981, 79934, -42313, 46887, -5710, -88754, -80984, -26452, 55230, -54038, -43063, 29949, 24526, 36901, -46454, 75099, 3182, -7119, -47592};
// 	int i;

// 	quick_sort(arr, 0, 100);
// 	i = 0;
// 	while (i < 100)
// 		printf("%d ", arr[i++]);
// 	printf("\n");
// 	return (0);

// }
