/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort_utilits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delgamma <delgamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:16:20 by delgamma          #+#    #+#             */
/*   Updated: 2024/06/24 10:20:16 by delgamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_num_top_sub(int num_index, int list_size, t_node **head_node,
		int is_stack_a)
{
	int	away_from_down;

	away_from_down = list_size - num_index;
	if (away_from_down > num_index)
	{
		while (num_index-- > 0)
		{
			if (is_stack_a)
				ra(head_node);
			else
				rb(head_node);
		}
	}
	else
	{
		while (away_from_down-- > 0)
		{
			if (is_stack_a)
				rra(head_node);
			else
				rrb(head_node);
		}
	}
}

void	push_back_chuncks(t_node **stka, t_node **stkb)
{
	int		stkb_size;
	int		max_num;
	t_node	*current;

	max_num = (*stkb)->num;
	current = *stkb;
	while (current)
	{
		max_num = get_next_max(max_num, stkb);
		stkb_size = count_elements_list(stkb);
		push_num_top(stkb_size, max_num, stkb, 0);
		pa(stka, stkb);
		current = *stkb;
	}
}

void	move_chunk(int chunk_max_num, t_node **stk_a, t_node **stk_b)
{
	int		next_num;
	int		stka_size;
	t_node	*current;

	stka_size = count_elements_list(stk_a);
	if ((*stk_a)->num <= chunk_max_num)
	{
		pb(stk_a, stk_b);
		stka_size--;
	}
	current = *stk_a;
	while (current)
	{
		next_num = current->num;
		current = current->next;
		if (next_num <= chunk_max_num)
		{
			push_num_top(stka_size, next_num, stk_a, 1);
			pb(stk_a, stk_b);
			stka_size--;
			current = *stk_a;
		}
	}
}

void	free_str_arr(char **str, int curr_indx)
{
	int	i;

	i = curr_indx;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	push_remaining(int arr_size, int *sorted_arr, t_node **stk_1,
		t_node **stk_2)
{
	int	stka_count;

	if (*stk_1)
	{
		stka_count = count_elements_list(stk_1);
		if (stka_count == 1)
			pb(stk_1, stk_2);
		else if (stka_count == 2)
		{
			pb(stk_1, stk_2);
			pb(stk_1, stk_2);
		}
		else if (stka_count == 3)
		{
			sort_3(stk_1);
		}
		else
		{
			move_chunk(sorted_arr[arr_size - 4], stk_1, stk_2);
			sort_3(stk_1);
		}
	}
}
