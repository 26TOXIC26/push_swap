/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:19:24 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/11 00:07:56 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_list *stack_a)
{
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
}

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
	ft_push(stack_a, stack_b, 'a');
	ft_push(stack_a, stack_b, 'a');
	ft_sort_3(stack_a);
	if ((*stack_b)->value < (*stack_b)->next->value)
		ft_swap(stack_b, 'b');
	ft_push(stack_b, stack_a, 'b');
	ft_rotate(stack_a, 'a');
	ft_push(stack_b, stack_a, 'b');
}

int	ft_check_null(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i++][0] == '\0')
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			i;
	static char	*numbers;
	static char	**num_split;
	t_list		*stack_a;
	t_list		*stack_b;
	char		*tmp;

	if (argc < 2)
		return (ft_printf("Error\n"));
	if (ft_check_null(argc, argv) == 0)
		return (ft_printf("Error\n"));
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < argc)
	{
		tmp = numbers;
		numbers = ft_strjoin(numbers, argv[i++]);
		free(tmp);
	}
	if (ft_check_arg(numbers) == 0)
	{
		free(numbers);
		return (ft_printf("Error\n"));
	}
	num_split = ft_split(numbers, ' ');
	if (ft_split_to_node(num_split, 0, NULL, &stack_a) == 0)
	{
		if (ft_lstsize(stack_a) == 2)
		{
			ft_swap(&stack_a, 'a');
			ft_print_list(stack_a);
			return (0);
		}
		else if (ft_lstsize(stack_a) == 3)
			ft_sort_3(&stack_a);
		else
			ft_sort_5(&stack_a, &stack_b);
		ft_print_list(stack_a);
	}
	ft_free_all_ta3_all(numbers, num_split, &stack_a);
}
