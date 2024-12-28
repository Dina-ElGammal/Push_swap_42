/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delgamma <delgamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:17:05 by delgamma          #+#    #+#             */
/*   Updated: 2024/06/24 10:19:12 by delgamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_index(int num, t_node **h_node)
{
	int		indx;
	t_node	*current;

	indx = 0;
	current = *h_node;
	while (current)
	{
		if (num != current->num)
		{
			indx++;
			current = current->next;
		}
		else
			break ;
	}
	return (indx);
}

void	push_num_top(int list_size, int num, t_node **head_node, int is_stack_a)
{
	int	index;

	index = ft_get_index(num, head_node);
	if (!is_stack_a && index == 1)
		sb(head_node);
	else if (index > 0)
	{
		push_num_top_sub(index, list_size, head_node, is_stack_a);
	}
}

int	get_max(t_node **head_node)
{
	int		max;
	t_node	*current;

	current = *head_node;
	max = current->num;
	while (current)
	{
		if (current->num > max)
		{
			max = current->num;
		}
		current = current->next;
	}
	return (max);
}

int	get_next_min(int last_min, t_node **head_node)
{
	int		min;
	t_node	*current;

	current = (*head_node)->next;
	min = current->num;
	while (current)
	{
		if (current->num < min && current->num != last_min)
		{
			min = current->num;
		}
		current = current->next;
	}
	return (min);
}

int	get_next_max(int last_max, t_node **head_node)
{
	int		max;
	t_node	*current;

	current = *head_node;
	max = current->num;
	while (current)
	{
		if (current->num > max && current->num != last_max)
		{
			max = current->num;
		}
		current = current->next;
	}
	return (max);
}
