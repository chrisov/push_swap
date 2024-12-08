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
	t_stack	*head;

	if (argc > 1)
	{
		argv++;
		head = new_node(ft_atoi(*argv));
		a = head;
		argv++;
		while (*argv)
		{
			a->next_nbr = new_node(ft_atoi(*argv));
			a = a->next_nbr;
			argv++;
		}
		a = head;
		print_node(a);
		sort_stack_of_three(&head);
		print_node(head);
	}
}