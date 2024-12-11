/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:47 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/10 14:53:28 by dchrysov         ###   ########.fr       */
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
	int				index;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*previous_node;
	struct s_stack	*next_node;
}				t_stack;

void	rotate(t_stack **head);
void	rev_rotate(t_stack **head);
void	swap(t_stack **head);
void	push_ab(t_stack **src_head, t_stack **dst_head);
// 
void	sort_stack_of_three(t_stack **head);
void	print_nodes(t_stack *head, t_stack *dest);			//<-------- PRINTF
void	stack_init(t_stack **stack, char **array);
int		num_of_nodes(t_stack *head);
t_stack	*find_max_node(t_stack *head);
t_stack	*find_min_node(t_stack *head);
int		max_index_node(t_stack *head);
int		min_value_node(t_stack *head);
int		cost_calc(t_stack *src, t_stack *dest);
// void	set_node_attributes(t_stack *src, t_stack *dest);
void	node_index(t_stack *head);
void	print_node(t_stack *head);
void	target_node(t_stack *src, t_stack *dst);
void	position_to_median(t_stack *head);
void	calculate_cost(t_stack *src, t_stack *dest);
void	is_cheapest(t_stack *head);

#endif
