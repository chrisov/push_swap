/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:13:00 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/30 15:48:31 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @note Handle the out of int range edge case.
 */
// static int	error_handling(int size, char **array)
// {
// 	int	i;
// 	int	j;

// 	i = 1;
// 	while (array[i])
// 	{
// 		if (!(ft_isdigit((int)array[i]) == 1))
// 			return (1);
// 		i++;
// 	}
// 	i = 1;
// 	while (i < size / 2)
// 	{
// 		j = i + 1;
// 		while (j <= size)
// 		{
// 			if (array[j] == array[i])
// 				return (2);
// 			else
// 				break ;
// 			j++;
// 		}
// 		i ++;
// 	}
// 	return (3);
// }
