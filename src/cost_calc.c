/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:16 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/11 15:13:53 by dchrysov         ###   ########.fr       */
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
				rr_rrr(src, dest, rotate);
			else
				rr_rrr(src, dest, rev_rotate);
		}
		else
		{
			if (i_src > i_dest)
			{
				if (cheapest->above_median)
					rotate(src);
				else
					rev_rotate(src);
			}
			else
			{
				if (cheapest->above_median)
					rotate(dest);
				else
					rev_rotate(dest);
			}
		}
		i_src--;
		i_dest--;
	}
	push_ab(src, dest);
}
