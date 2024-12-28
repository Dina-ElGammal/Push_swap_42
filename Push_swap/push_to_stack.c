/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delgamma <delgamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:15:27 by delgamma          #+#    #+#             */
/*   Updated: 2024/06/19 10:23:35 by delgamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushtostack(t_node **head_from, t_node **head_to)
{
	t_node	*new_node;

	if (*head_from != NULL)
	{
		new_node = (*head_from);
		*head_from = (*head_from)->next;
		if (head_to != NULL && *head_to != NULL)
			new_node->next = *head_to;
		else
			new_node->next = NULL;
		*head_to = new_node;
	}
}

void	pa(t_node **stack_A, t_node **stack_B)
{
	pushtostack(stack_B, stack_A);
	write(1, "pa", 2);
	write(1, "\n", 1);
}

void	pb(t_node **stack_A, t_node **stack_B)
{
	pushtostack(stack_A, stack_B);
	write(1, "pb", 2);
	write(1, "\n", 1);
}
