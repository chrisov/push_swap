/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/10 16:03:12 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// static int	max(int n1, int n2)
// {
// 	if (n1 < n2)
// 		return (n2);
// 	return (n1);
// }

// int	cost_calc(t_stack *src, t_stack *dest)
// {
// 	t_stack *current_src;
// 	int	src_pos;
// 	int	cost;
// 	int	cost_index;

// 	src_pos = 0;
// 	cost = INT_MAX;
// 	cost_index = 0;
// 	current_src = src;
// 	while (current_src)
// 	{
// 		if (src_pos <= num_of_nodes(src) / 2)
// 		{
// 			if (current_src->target_position <= num_of_nodes(dest) / 2)
// 			{
// 				printf("%d\n", max(src_pos, current_src->target_position));
// 				if (max(src_pos, current_src->target_position) < cost)
// 				{
// 					cost = max(src_pos, current_src->target_position);
// 					cost_index = src_pos;
// 				}
// 			}
// 			else
// 			{
// 				printf("%d\n", src_pos + num_of_nodes(dest) - current_src->target_position);
// 				if (src_pos + num_of_nodes(dest) - current_src->target_position < cost)
// 				{
// 					cost = src_pos + num_of_nodes(dest) - current_src->target_position;
// 					cost_index = src_pos;
// 				}
// 			}
// 		}
// 		else
// 		{
// 			if (current_src->target_position > num_of_nodes(dest) / 2)
// 			{
// 				printf("%d\n", max(num_of_nodes(src) - src_pos, num_of_nodes(dest) - current_src->target_position));
// 				if (max(num_of_nodes(src) - src_pos, num_of_nodes(dest) - current_src->target_position) < cost)
// 				{
// 					cost = max(num_of_nodes(src) - src_pos, num_of_nodes(dest) - current_src->target_position);
// 					cost_index = src_pos;
// 				}
// 			}
// 			else
// 			{
// 				printf("%d\n", num_of_nodes(src) - src_pos + current_src->target_position);
// 				if (num_of_nodes(src) - src_pos + current_src->target_position < cost)
// 				{
// 					cost = num_of_nodes(src) - src_pos + current_src->target_position;
// 					cost_index = src_pos;
// 				}
// 			}
// 		}
// 		src_pos++;
// 		current_src = current_src->next_node;
// 	}
// 	return (cost_index);
// }


