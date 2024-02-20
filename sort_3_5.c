/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:26:30 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/20 15:07:44 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_highest(t_list *stack)
{
	int	highest;

	highest = stack->value;
	while (stack)
	{
		if (highest < stack->value)
			highest = stack->value;
		stack = stack->next;
	}
	return (highest);
}
int find_smallest(t_list *stack)
{
	int smallest;

	smallest = stack->value;
	while(stack)
	{
		if (smallest > stack->value)
			smallest = stack->value;
		stack = stack->next;
	}
	return (smallest);
}

int find_position(t_list *stack, int value)
{
	int position;

	position = 0;
	while(value != stack->value)
	{
		position++;
		stack = stack->next;
	}
	return (position);
}

void	ft_sort_3(t_list **stack_a)
{
	int	highest;

	highest = find_highest(*stack_a);
	if (highest == (*stack_a)->value)
		ft_rotate(stack_a, 'a');
	else if (highest == (*stack_a)->next->value)
		ft_rev_rotate(stack_a, 'a');
	if (((*stack_a)->value) > ((*stack_a)->next->value))
		ft_swap(stack_a, 'a');
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	int smallest;
	int position;

	smallest = find_smallest(*stack_a);
	while(ft_lstsize(*stack_a) > 3)
	{
		if(smallest == (*stack_a)->value)
		{
			ft_push(stack_a, stack_b, 'a');
			smallest = find_smallest(*stack_a);
		}
		position = find_position(*stack_a, smallest);
		if(position > (ft_lstsize(*stack_a) / 2))
			ft_rev_rotate(stack_a, 'a');
		else
			ft_rotate(stack_a, 'a');
	}
	ft_sort_3(stack_a);
	while(ft_lstsize(*stack_b) > 0)
		ft_push(stack_b, stack_a, 'b');
}
