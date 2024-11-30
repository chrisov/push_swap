/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:47 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/30 15:05:13 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>						// <----------------- PRINTF
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				nbr;
	int				target_pos;
	struct s_stack	*next_nbr;
}					t_stack;

t_stack		*stack_init(int *array, int array_size, int *sorted_array);
char		*nbr_sign(int number);
int			ft_atoi(const char *str);
int			*atoi_array(char **array, int size);
int			ft_isdigit(char c);
void		quick_sort(int *arr, int low, int high);
void		print_node(t_stack *head);
void		print_nodes(t_stack *a_head, t_stack *b_head);
void		rotate(t_stack **head);
void		rev_rotate(t_stack **head);
void		push_ab(t_stack **src_head, t_stack **dst_head);
int			sort_stack(t_stack **a, t_stack **b, int target);


#endif
