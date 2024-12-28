/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delgamma <delgamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:14:07 by delgamma          #+#    #+#             */
/*   Updated: 2024/06/24 10:57:21 by delgamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	stack_a = (t_node **)malloc(sizeof(t_node));
	stack_b = (t_node **)malloc(sizeof(t_node));
	*stack_a = NULL;
	*stack_b = NULL;
	if (argc >= 2)
	{
		if (chk_and_fillstack(argc, argv, stack_a) && !is_sorted(stack_a))
			sort_lst(stack_a, stack_b);
		else
		{
			write(1, "Error\n", 6);
			freenode(stack_a, stack_b);
			free(stack_a);
			free(stack_b);
			return (0);
		}
	}
	freenode(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
