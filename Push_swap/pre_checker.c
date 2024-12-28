/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delgamma <delgamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:16:08 by delgamma          #+#    #+#             */
/*   Updated: 2024/06/26 14:25:40 by delgamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\f' || *nptr == '\r'
		|| *nptr == '\n' || *nptr == '\v')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return ((long)(sign * result));
}

int	args_check(char *str)
{
	int	i;
	int	flag;

	i = 0;
	if (str[0] == ' ' || str[0] == '\t')
		return (0);
	while (str[i] != '\0')
	{
		flag = 0;
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] != '\0')
		{
			if (++flag == 1)
				i++;
			else if (flag > 1)
				return (0);
		}
		else if ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0' && str[i
					+ 1] <= '9'))
			i = i + 2;
		else
			return (0);
	}
	return (1);
}

int	is_dupplicate(t_node **lst, int num)
{
	t_node	*tmp;

	if (!lst || !*lst)
	{
		return (0);
	}
	tmp = *lst;
	while (tmp)
	{
		if (tmp->num == num)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_and_add(char *str, t_node **stk_a)
{
	long	num;

	num = 0;
	if (!args_check(str))
		return (0);
	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	else
	{
		if (!is_dupplicate(stk_a, (int)num))
			addnode(stk_a, (int)num);
		else
			return (0);
	}
	return (1);
}

int	chk_and_fillstack(int arc, char **arv, t_node **stack_a_head)
{
	int		i;
	int		j;
	char	**splt_str;

	i = 1;
	j = 0;
	while (i < arc)
	{
		j = 0;
		splt_str = ft_split(arv[i]);
		while (splt_str[j])
		{
			if (check_and_add(splt_str[j], stack_a_head))
				free(splt_str[j++]);
			else
			{
				free_str_arr(splt_str, j);
				return (0);
			}
		}
		free(splt_str);
		i++;
	}
	return (1);
}
