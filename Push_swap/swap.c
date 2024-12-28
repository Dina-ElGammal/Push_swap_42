/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delgamma <delgamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:15:39 by delgamma          #+#    #+#             */
/*   Updated: 2024/06/19 10:24:09 by delgamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **head)
{
	int	temp;

	if ((*head) != NULL && (*head)->next != NULL)
	{
		temp = (*head)->num;
		(*head)->num = (*head)->next->num;
		(*head)->next->num = temp;
	}
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
	write(1, "sa", 2);
	write(1, "\n", 1);
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	write(1, "sb", 2);
	write(1, "\n", 1);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss", 2);
	write(1, "\n", 1);
}
