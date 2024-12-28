/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delgamma <delgamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:16:57 by delgamma          #+#    #+#             */
/*   Updated: 2024/06/26 14:47:35 by delgamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_sort_arr(int size_of_arr, t_node **stk_m)
{
	int		*arr;
	int		i;
	t_node	*temp;

	temp = *stk_m;
	arr = (int *)malloc(size_of_arr * sizeof(int));
	i = 0;
	while (i < size_of_arr && temp)
	{
		arr[i] = temp->num;
		temp = temp->next;
		i++;
	}
	sort_arr(arr, size_of_arr);
	return (arr);
}

void	sort_3(t_node **stk_main)
{
	int	e1;
	int	e2;
	int	e3;

	e1 = (*stk_main)->num;
	e2 = (*stk_main)->next->num;
	e3 = (*stk_main)->next->next->num;
	if ((e1 > e2) && (e2 < e3) && (e1 < e3))
		sa(stk_main);
	else if ((e1 < e2) && (e2 > e3) && (e1 > e3))
		rra(stk_main);
	else if ((e1 < e2) && (e2 > e3) && (e1 < e3))
	{
		sa(stk_main);
		ra(stk_main);
	}
	else if ((e1 > e2) && (e2 > e3))
	{
		sa(stk_main);
		rra(stk_main);
	}
	else if ((e1 > e2) && (e2 < e3))
		ra(stk_main);
}

void	sort_5(int size_of_list, t_node **stk_main, t_node **stack_2)
{
	int	current_min;

	current_min = get_min(stk_main);
	push_num_top(size_of_list, current_min, stk_main, 1);
	pb(stk_main, stack_2);
	if (size_of_list == 5)
	{
		current_min = get_min(stk_main);
		push_num_top(size_of_list - 1, current_min, stk_main, 1);
		pb(stk_main, stack_2);
	}
	sort_3(stk_main);
	pa(stk_main, stack_2);
	if (size_of_list == 5)
		pa(stk_main, stack_2);
}

void	sort_main_algo(int size_of_list, t_node **stk_main, t_node **stack_2)
{
	int	*sorted_array;
	int	chunck_size;
	int	number_of_chunks;
	int	current_chunck_key;

	if (size_of_list <= 100)
		number_of_chunks = 5;
	else
		number_of_chunks = 13;
	sorted_array = fill_sort_arr(size_of_list, stk_main);
	chunck_size = size_of_list / number_of_chunks;
	current_chunck_key = chunck_size - 1;
	while (number_of_chunks >= 1)
	{
		move_chunk(sorted_array[current_chunck_key], stk_main, stack_2);
		number_of_chunks--;
		current_chunck_key += chunck_size;
	}
	push_remaining(size_of_list, sorted_array, stk_main, stack_2);
	free(sorted_array);
	push_back_chuncks(stk_main, stack_2);
}

void	sort_lst(t_node **stk_1, t_node **stk_2)
{
	int	size;

	size = count_elements_list(stk_1);
	if (size == 2)
		sa(stk_1);
	else if (size == 3)
		sort_3(stk_1);
	else if (size <= 5)
		sort_5(size, stk_1, stk_2);
	else
		sort_main_algo(size, stk_1, stk_2);
}
