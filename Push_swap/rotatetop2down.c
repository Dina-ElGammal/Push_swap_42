/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatetop2down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delgamma <delgamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:15:10 by delgamma          #+#    #+#             */
/*   Updated: 2024/06/19 10:23:51 by delgamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_top2down(t_node **head)
{
	t_node	*temp;
	t_node	*last;

	if ((*head) != NULL && (*head)->next != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		temp->next = NULL;
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = temp;
	}
}

void	ra(t_node **stack_a)
{
	r_top2down(stack_a);
	write(1, "ra", 2);
	write(1, "\n", 1);
}

void	rb(t_node **stack_b)
{
	r_top2down(stack_b);
	write(1, "rb", 2);
	write(1, "\n", 1);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr", 2);
	write(1, "\n", 1);
}
