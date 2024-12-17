/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:50:29 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/16 13:39:53 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	char			**arr;

	arr = NULL;
	if (argc < 3)
		arr = num_args(argv, argc);
	else
		arr = ++argv;
	stack_init(&a, arr);
	b = NULL;
	sort_stack(&a, &b);
	bring_min_top(&a);
	// print_node(a);
	free_list(&a, arr, argc);
}

// make run -- 16 -59 -66 44 78 -40 63 -88 80 81