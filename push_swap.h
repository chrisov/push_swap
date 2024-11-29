/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:47 by dchrysov          #+#    #+#             */
/*   Updated: 2024/11/29 13:43:48 by dchrysov         ###   ########.fr       */
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
	int				length;
	int				init_pos;
	int				target_pos;
	struct s_stack	*next_nbr;
}					t_stack;

int			main(int argc, char **argv);
int			ft_atoi(const char *str);
int			*atoi_array(char **array, int size);
int			ft_isdigit(char c);
int			nbr_length(int value);
int			count_of_buckets(int *array, int array_size);
void		quick_sort(int *arr, int low, int high);
char		*nbr_sign(int number);
char		*ft_itoa(int n);
void		print_node(t_stack *head);
t_stack		*new_node(int value, int position, int target_pos);
t_stack		*stack_init(int *array, int array_size, int *sorted_array);

#endif
