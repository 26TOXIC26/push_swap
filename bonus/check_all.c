/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:19:22 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/26 03:05:37 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_check_n(int argc, char **argv)
{
	if (ft_check_null(argc, argv) == 0)
		return (ft_printf("Error\n"));
	if (ft_check_full_space(argc, argv) == 0)
		return (ft_printf("Error\n"));
	return (0);
}

int	ft_check_sort(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a->next;
	while (tmp)
	{
		while (tmp)
		{
			if (stack_a->value > tmp->value)
				return (0);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
		tmp = stack_a->next;
	}
	return (1);
}

void	ft_ok_ko(t_list *stack_a, t_list *stack_b)
{
	if (ft_lstsize(stack_a) > 0 && ft_check_sort(stack_a)
		== 1 && ft_lstsize(stack_b) == 0)
		write(1, "Ok\n", 3);
	else
		write(1, "Ko\n", 3);
}
