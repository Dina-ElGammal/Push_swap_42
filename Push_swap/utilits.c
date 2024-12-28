/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delgamma <delgamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:16:46 by delgamma          #+#    #+#             */
/*   Updated: 2024/06/19 10:24:18 by delgamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

size_t	getwordcount(char *S)
{
	int		i;
	size_t	wcount;

	i = 0;
	wcount = 0;
	while (S[i])
	{
		while (S[i] && (S[i] == ' ' || S[i] == '\t' || S[i] == '\n'))
			i++;
		if (S[i])
			wcount++;
		while (S[i] && (S[i] != ' ' && S[i] != '\t' && S[i] != '\n'))
			i++;
	}
	return (wcount);
}

char	**ft_split(char *str)
{
	size_t	i;
	size_t	j;
	int		k;
	char	**splt_str;

	i = 0;
	j = 0;
	k = 0;
	splt_str = (char **)malloc(sizeof(char *) * (getwordcount(str) + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > j)
		{
			splt_str[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(splt_str[k++], &str[j], (int)(i - j));
		}
	}
	splt_str[k] = NULL;
	return (splt_str);
}

int	get_min(t_node **head_node)
{
	int		min;
	t_node	*current;

	current = *head_node;
	min = current->num;
	while (current)
	{
		if (current->num < min)
		{
			min = current->num;
		}
		current = current->next;
	}
	return (min);
}

void	sort_arr(int *int_arr, int arr_size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < (arr_size - 1))
	{
		if (int_arr[i] > int_arr[i + 1])
		{
			tmp = int_arr[i];
			int_arr[i] = int_arr[i + 1];
			int_arr[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
