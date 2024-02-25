/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:51:19 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/23 01:20:00 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_position_in_array(int *array, t_list *stack_a)
{
	int	i;
	int	j;

	j = ft_lstsize(stack_a);
	i = 0;
	while (stack_a)
	{
		while (i < j)
		{
			if (stack_a->value == array[i])
			{
				stack_a->index = i;
				break ;
			}
			i++;
		}
		i = 0;
		stack_a = stack_a->next;
	}
}

int	find_index(t_list *a, int x, int p)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->index <= x || a->index <= x + p)
			break ;
		i++;
		a = a->next;
	}
	return (i);
}

void	ft_push_to_a(t_list **stack_a, t_list **stack_b)
{
	int	highest;
	int	position;

	highest = find_highest(*stack_b);
	position = find_position(*stack_b, highest);
	while (ft_lstsize(*stack_b) > 0)
	{
		if (highest == (*stack_b)->value)
		{
			ft_push(stack_b, stack_a, 'b');
			if (ft_lstsize(*stack_b) > 0)
			{
				highest = find_highest(*stack_b);
				position = find_position(*stack_b, highest);
			}
		}
		else
		{
			if (position <= (ft_lstsize(*stack_b) / 2)
				&& highest != (*stack_b)->value)
				ft_rotate(stack_b, 'b');
			else
				ft_rev_rotate(stack_b, 'b');
		}
	}
}

void	ft_sort_chunk(t_list **stack_a, t_list **stack_b, int *array, int p)
{
	int	num_ele;
	int	i;

	i = 0;
	num_ele = ft_lstsize(*stack_a);
	ft_position_in_array(array, *stack_a);
	while (i < num_ele)
	{
		if ((*stack_a)->index <= i)
		{
			ft_push(stack_a, stack_b, 'a');
			ft_rotate(stack_b, 'b');
			i++;
		}
		else if ((*stack_a)->index <= i + p)
		{
			ft_push(stack_a, stack_b, 'a');
			i++;
		}
		else if (find_index(*stack_a, i, p) < ft_lstsize(*stack_a) / 2)
			ft_rotate(stack_a, 'a');
		else
			ft_rev_rotate(stack_a, 'a');
	}
	ft_push_to_a(stack_a, stack_b);
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	*array;

	array = ft_fill_aray(*stack_a);
	ft_sort_array(array, ft_lstsize(*stack_a));
	if (ft_lstsize(*stack_a) < 400)
		ft_sort_chunk(stack_a, stack_b, array, 15);
	else
		ft_sort_chunk(stack_a, stack_b, array, 30);
	free(array);
}
