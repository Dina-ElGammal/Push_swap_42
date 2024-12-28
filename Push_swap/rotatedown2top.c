/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatedown2top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delgamma <delgamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:15:16 by delgamma          #+#    #+#             */
/*   Updated: 2024/06/19 10:23:42 by delgamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_down2top(t_node **head)
{
	t_node	*newhead;
	t_node	*tempnode;

	if ((*head) != NULL && (*head)->next != NULL)
	{
		tempnode = *head;
		while (tempnode->next->next != NULL)
			tempnode = tempnode->next;
		newhead = tempnode->next;
		tempnode->next = NULL;
		newhead->next = *head;
		*head = newhead;
	}
}

void	rra(t_node **stack_a)
{
	r_down2top(stack_a);
	write(1, "rra", 3);
	write(1, "\n", 1);
}

void	rrb(t_node **stack_b)
{
	r_down2top(stack_b);
	write(1, "rrb", 3);
	write(1, "\n", 1);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr", 3);
	write(1, "\n", 1);
}
