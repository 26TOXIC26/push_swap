/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 07:19:00 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/12 23:16:01 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **stack_from, t_list **stack_to, char type_from)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*stack_from == NULL)
		return ;
	tmp1 = *stack_from;
	*stack_from = (*stack_from)->next;
	tmp2 = *stack_to;
	*stack_to = tmp1;
	(*stack_to)->next = tmp2;
	if (type_from == 'b')
		write(1, "pa\n", 3);
	else if (type_from == 'a')
		write(1, "pb\n", 3);
}
