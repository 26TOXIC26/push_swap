/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 07:41:36 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/12 23:21:55 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack, char type)
{
	t_list	*tmp;

	if ((ft_lstsize(*stack)) < 2)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
	if (type == 'a')
		write(1, "ra\n", 3);
	else if (type == 'b')
		write(1, "rb\n", 3);
}

void	ft_rotate_all(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a, 'y');
	ft_rotate(stack_b, 'z');
	write(1, "rr\n", 3);
}

void	ft_rev_rotate(t_list **stack, char type)
{
	t_list	*tmp;
	t_list	*tmp2;

	if ((ft_lstsize(*stack)) < 2)
		return ;
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
		write(1, "rra\n", 4);
	else if (type == 'b')
		write(1, "rrb\n", 4);
}

void	ft_rev_rotate_all(t_list **stack_a, t_list **stack_b)
{
	ft_rev_rotate(stack_a, 'y');
	ft_rev_rotate(stack_b, 'z');
	write(1, "rrr\n", 4);
}
