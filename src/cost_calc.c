/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/11 16:06:22 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_cheapest(t_stack **src, t_stack **dest)
{
	t_stack	*cheapest;
	int		i_src;
	int		i_dest;

	i_src = 0;
	cheapest = *src;
	while (cheapest->cheapest == false)
		cheapest = cheapest->next_node;
	i_src = cheapest->index;
	i_dest = cheapest->target_node->index;
	while (i_src > 0 || i_dest > 0)
	{
		if (i_src == i_dest)
		{
			if (cheapest->above_median)
				rr_rrr(src, dest, rotate, "rr");
			else
				rr_rrr(src, dest, rev_rotate, "rrr");
		}
		else
		{
			if (i_src > i_dest)
			{
				if (cheapest->above_median)
					rotate(src, "ra");
				else
					rev_rotate(src, "rra");
			}
			else
			{
				if (cheapest->target_node->above_median)
					rotate(dest, "rb");
				else
					rev_rotate(dest, "rrb");
			}
		}
		i_src--;
		i_dest--;
	}
	push_ab(src, dest, "pab");
}
