/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utilits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delgamma <delgamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:16:20 by delgamma          #+#    #+#             */
/*   Updated: 2024/06/26 14:21:51 by delgamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int data)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		return (0);
	newnode->num = data;
	newnode->next = NULL;
	return (newnode);
}

void	addnode(t_node **head_node, int data)
{
	t_node	*temp;
	t_node	*new_node;

	new_node = create_node(data);
	if (!head_node || !*head_node)
	{
		*head_node = new_node;
	}
	else
	{
		temp = *head_node;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	freenode(t_node **heada, t_node **headb)
{
	t_node	*temp;
	t_node	*temp2;

	while (*heada)
	{
		temp = *heada;
		*heada = (*heada)->next;
		free(temp);
	}
	while (*headb)
	{
		temp2 = *headb;
		*headb = (*headb)->next;
		free(temp2);
	}
}

int	is_sorted(t_node **hnode)
{
	t_node	*tmp;

	if (!hnode || !*hnode)
	{
		return (1);
	}
	tmp = *hnode;
	while (tmp->next)
	{
		if (tmp->next->num > tmp->num)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int	count_elements_list(t_node **stk_list)
{
	int		num_of_elements;
	t_node	*temp;

	num_of_elements = 0;
	temp = *stk_list;
	while (temp)
	{
		num_of_elements++;
		temp = temp->next;
	}
	return (num_of_elements);
}
