/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:47 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/09 14:01:24 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>						// <----------------- PRINTF
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_stack
{
	int				nbr;
	int				cost;
	struct s_stack	*next_nbr;
}				t_stack;

void	rotate(t_stack **head);
void	rev_rotate(t_stack **head);
void	swap(t_stack **head);
void	push_ab(t_stack **src_head, t_stack **dst_head);
void	sort_stack_of_three(t_stack **head);
void	print_node(t_stack *head);			//<-------- PRINTF
void	stack_init(t_stack **stack, char **array);
int		num_of_nodes(t_stack *head);
int		cheapest_node(t_stack *src_node, t_stack *dest_node);
int		stack_min(t_stack *head);
int		stack_max(t_stack *head);

#endif
