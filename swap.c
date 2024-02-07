/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:24:07 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/07 08:40:27 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack, char type_stack)
{
	t_list	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
	if (type_stack == 'a')
		ft_printf("sa\n");
	else if (type_stack == 'b')
		ft_printf("sb\n");
}

void	ft_swap_all(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a, 'y');
	ft_swap(stack_b, 'z');
	ft_printf("ss\n");
}
