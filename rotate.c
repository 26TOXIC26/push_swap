/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 07:41:36 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/07 08:38:20 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_retate(t_list **stack, char type)
{
	t_list	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
	if (type == 'a')
		ft_printf("ra\n");
	else if (type == 'b')
		ft_printf("rb\n");
}

void	ft_rotate_all(t_list **stack_a, t_list **stack_b)
{
	ft_retate(stack_a, 'y');
	ft_retate(stack_b, 'z');
	ft_printf("rr\n");
}

void    ft_rev_rotate(t_list **stack, char type)
{
	t_list	*tmp;
	t_list	*tmp2;

    tmp = ft_lstlast(*stack);
    tmp2 = *stack;
    while (tmp2)
	{
		if (tmp2->next->next == NULL)
		{
			 tmp2->next = NULL;
			 break ;
		}
		tmp2 = tmp2->next;
	}
    ft_lstadd_front(stack, tmp);
    if (type == 'a')
		ft_printf("rra\n");
	else if (type == 'b')
		ft_printf("rrb\n");
}

void    ft_rev_rotate_all(t_list **stack_a, t_list **stack_b)
{
	ft_rev_rotate(stack_a, 'y');
    ft_rev_rotate(stack_b, 'z');
    ft_printf("rrr\n");
}
