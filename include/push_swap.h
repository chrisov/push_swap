/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:47 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/18 12:52:20 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				nbr;
	int				i;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*previous_node;
	struct s_stack	*next_node;
}				t_stack;

//	Rules

void	rrr(t_stack **s1, t_stack **s2, void (*f)(t_stack **, char *),
			char *msg);
void	rotate(t_stack **head, char *msg);
void	rev_rotate(t_stack **head, char *msg);
void	swap(t_stack **head);
void	push(t_stack **src_head, t_stack **dst_head, bool rev_flag, char *msg);

//	Params

char	**menu(int argc, char **argv);

//	Sorting

t_stack	*find_max_node(t_stack *head);
t_stack	*find_min_node(t_stack *head);
int		stck_len(t_stack *head);
void	bring_min_top(t_stack **head);

// Error check
bool	already_sorted(t_stack *head);

// Node attributes
void	node_index(t_stack *head);
void	position_to_median(t_stack *head);
void	calculate_cost(t_stack *src, t_stack *dest);
void	is_cheapest(t_stack *head);
void	target_csn_node(t_stack *src, t_stack *dst);
void	target_cbn_node(t_stack *src, t_stack *dst);
void	stack_init(t_stack **stack, char **array, int len);
void	push_cheapest(t_stack **src, t_stack **dest, bool rev_flag);
void	sort_stack_of_two(t_stack **head);
void	sort_stack_of_three(t_stack **head);
void	bring_min_top(t_stack **head);
void	push_cond(t_stack **src, t_stack **dst, t_stack *cheap, bool rev_flag);

//	Free

void	free_array(char **array);
void	free_stack(t_stack **head);

#endif
