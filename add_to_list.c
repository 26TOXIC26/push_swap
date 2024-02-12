/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:51:56 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/12 11:27:21 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_split_to_node(char **num_split, long tmp_num, t_list *tmp_node,
		t_list **stack_a)
{
	long	tmp_num2;
	int		i;

	i = 0;
	while (num_split[i])
	{
		tmp_num2 = tmp_num;
		tmp_num = ft_atoi(num_split[i]);
		if (tmp_num > INT_MAX || tmp_num < INT_MIN)
			return (ft_printf("Error\n"));
		if (i != 0)
		{
			if ((ft_check_num(stack_a, tmp_num) == 0 || tmp_num2 == tmp_num)
				&& i != 0)
				return (ft_printf("Error\n"));
		}
		tmp_node = ft_lstnew(tmp_num);
		ft_lstadd_back(stack_a, tmp_node);
		i++;
	}
	return (0);
}
