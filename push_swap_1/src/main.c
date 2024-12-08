/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/03 12:58:00 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*temp;

	if (argc > 1)
	{
		temp = new_node(ft_atoi(*argv));
		a = temp;
		(*argv)++;
		while (*argv)
		{
			temp = new_node(ft_atoi(*argv));
			(*argv)++;
		}
		while (a)
		{
			printf("%d ", a->nbr);
			a = a->next_nbr;
		}
	}
}