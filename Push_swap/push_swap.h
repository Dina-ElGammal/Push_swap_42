/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delgamma <delgamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:17:49 by delgamma          #+#    #+#             */
/*   Updated: 2024/06/24 11:12:04 by delgamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct Node
{
	int			num;
	struct Node	*next;
}				t_node;

void			addnode(t_node **head_node, int data);
void			sa(t_node **stack_a);
void			sb(t_node **stack_b);
void			ss(t_node **stack_a, t_node **stack_b);
void			ra(t_node **stack_a);
void			rb(t_node **stack_b);
void			rr(t_node **stack_a, t_node **stack_b);
void			rra(t_node **stack_a);
void			rrb(t_node **stack_b);
void			rrr(t_node **stack_a, t_node **stack_b);
void			pa(t_node **stack_A, t_node **stack_B);
void			pb(t_node **stack_A, t_node **stack_B);
void			freenode(t_node **heada, t_node **headb);
char			**ft_split(char *str);
int				chk_and_fillstack(int argc, char **argv, t_node **stack_a);
int				is_sorted(t_node **hnode);
int				count_elements_list(t_node **stk_list);
void			sort_lst(t_node **stk_1, t_node **stk_2);
int				get_min(t_node **head_node);
void			push_num_top(int list_size, int num, t_node **head_node,
					int is_stack_a);
void			sort_arr(int *int_arr, int arr_size);
void			sort_chunk_stka(t_node **stk_main);
int				get_next_min(int last_min, t_node **head_node);
int				get_next_max(int last_max, t_node **head_node);
void			move_chunk(int chunk_max, t_node **stk_a, t_node **stk_b);
void			push_back_chuncks(t_node **stka, t_node **stkb);
void			free_str_arr(char **str, int curr_indx);
void			push_remaining(int arr_size, int *sorted_arr, t_node **stk_1,
					t_node **stk_2);
void			sort_3(t_node **stk_main);
void			push_num_top_sub(int num_index, int list_size,
					t_node **head_node, int is_stack_a);

#endif
