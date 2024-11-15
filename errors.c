/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitris <dimitris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:13:00 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/15 00:52:28 by dimitris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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
