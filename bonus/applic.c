/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:17:25 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/25 02:21:24 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_applic_op(char *move, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		ft_swap(stack_a, 'x');
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		ft_swap(stack_b, 'x');
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		ft_swap_all(stack_a, stack_b, 'x');
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		ft_rotate(stack_a, 'x');
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		ft_rotate(stack_b, 'x');
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		ft_rotate_all(stack_a, stack_b, 'x');
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		ft_rev_rotate(stack_a, 'x');
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		ft_rev_rotate(stack_b, 'x');
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		ft_rev_rotate_all(stack_a, stack_b, 'x');
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		ft_push(stack_b, stack_a, 'x');
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		ft_push(stack_a, stack_b, 'x');
	else
		return (0);
	return (1);
}

int	ft_call_appli(t_list **stack_a, t_list **stack_b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (ft_applic_op(move, stack_a, stack_b) == 0)
			return (0);
		free(move);
		move = get_next_line(0);
	}
	free(move);
	return (1);
}
