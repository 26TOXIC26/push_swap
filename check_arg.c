/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:47:33 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/06 21:50:21 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_num(t_list **lst, int num)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next)
	{
		if (num == tmp->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == '-' || s[i] == '+') && ((i != 0 && s[i - 1] != ' ') || s[i
					+ 1] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_arg(char *s)
{
	int	i;

	i = 0;
	if (ft_check_space(s) == 0)
		return (0);
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	if (ft_check(s) == 0)
		return (0);
	return (1);
}

int	ft_check_sort(t_list **stack_a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *stack_a;
	tmp2 = tmp1->next;
	if (ft_lstsize(*stack_a) < 2)
		return (2);
	while (tmp1 && tmp2)
	{
		while (tmp2)
		{
			if (tmp1->value > tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp1->next;
	}
	return (0);
}
