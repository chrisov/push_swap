/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitris <dimitris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:47 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/15 00:57:12 by dimitris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>						// <-----------------------
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				length;
	int				digit;
	int				current_pos;
	int				target_pos;
	char			*sign;
	struct s_stack	*next_nbr;
}					t_stack;

int			main(int argc, char **argv);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			nbr_length(int value);
char		*nbr_sign(int number);
void		print_node(t_stack *head);
t_stack		*new_node(int value, int position);
t_stack		*stack_init(char **value);

#endif
