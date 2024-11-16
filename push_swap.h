/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:47 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/16 12:49:51 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>						// <----------------- PRINTF
# include <stdbool.h>
# include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
	int				nbr;
	int				length;
	int				init_pos;
	int				target_pos;
	char			*sign;
	struct s_stack	*next_nbr;
}					t_stack;

int			main(int argc, char **argv);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			nbr_length(int value);
int			max_order_of_magnitude(char **array);
int			**buckets_alloc(t_stack *s, int maxlen);
int			**buckets_init(t_stack *s, int digits);
char		*nbr_sign(int number);
char		*ft_itoa(int n);
void		target_position(t_stack *node, int size, int max_len);
void		print_node(t_stack *head);
t_stack		*new_node(int value, int position);
t_stack		*stack_init(char **array);

#endif
