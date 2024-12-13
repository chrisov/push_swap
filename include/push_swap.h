/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:47 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/12 15:10:33 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../include/libft/include/libft.h"

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

# include <stdio.h>						// <----------------- PRINTF

typedef struct s_stack
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

void	rr_rrr(t_stack **s1, t_stack **s2, void (*f)(t_stack **, char *),
			char *msg);
void	rotate(t_stack **head, char *msg);
void	rev_rotate(t_stack **head, char *msg);
void	swap(t_stack **head);
void	push(t_stack **src_head, t_stack **dst_head, bool rev_flag, char *msg);
// 
t_stack	*find_max_node(t_stack *head);
t_stack	*find_min_node(t_stack *head);
int		num_of_nodes(t_stack *head);
int		cost_calc(t_stack *src, t_stack *dest);
void	sort_stack_of_three(t_stack **head);
void	node_index(t_stack *head);
void	position_to_median(t_stack *head);
void	calculate_cost(t_stack *src, t_stack *dest);
void	is_cheapest(t_stack *head);
void	target_csn_node(t_stack *src, t_stack *dst);
void	target_cbn_node(t_stack *src, t_stack *dst);
void	stack_init(t_stack **stack, char **array);
void	push_cheapest(t_stack **src, t_stack **dest, bool rev_flag);
char	**num_args(char **arr, int len);
void	sort_stack_of_two(t_stack **head);
bool	already_sorted(t_stack *head);
void	sort_stack(t_stack **stack1, t_stack **stack2);
void	bring_min_top(t_stack **head);
void	free_list(t_stack **head, char **array, int len);
//
void	print_node(t_stack *head);
void	print_nodes(t_stack *head, t_stack *dest);
void	print_rev_nodes(t_stack *src, t_stack *dest);

#endif