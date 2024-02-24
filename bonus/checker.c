/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:50:02 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/24 21:35:34 by amousaid         ###   ########.fr       */
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

char	*ft_join(int argc, char **argv)
{
	static char	*numbers;
	char		*tmp;
	int			i;

	i = 1;
	while (i < argc)
	{
		tmp = numbers;
		numbers = ft_strjoin(numbers, argv[i++]);
		free(tmp);
	}
	return (numbers);
}

int	ft_check_op(char *move)
{
	char	*check_move;

	check_move = "sa\nsb\nss\nra\nrb\nrr\nrra\nrrb\nrrr\npa\npb";
	if (ft_strncmp(move, "sa\n", 3) != 0 && ft_strncmp(move, "sa\n", 3) != 0
		&& ft_strncmp(move, "sa\n", 3) != 0 && ft_strncmp(move, "sa\n", 3) != 0
		&& ft_strncmp(move, "sa\n", 3) != 0 && ft_strncmp(move, "sa\n", 3) != 0)
		return (0);
	else
		return (1);
}

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

int	main(int argc, char **argv)
{
	static char	*numbers;
	static char	**num_split;
	static char	*move;
	t_list		*stack_a;
	t_list		*stack_b;

	if (argc < 2)
		return (0);
	if (ft_check_n(argc, argv) != 0)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	numbers = ft_join(argc, argv);
	if (ft_check_arg(numbers) == 0)
	{
		free(numbers);
		return (ft_printf("Error\n"));
	}
	num_split = ft_split(numbers, ' ');
	if (ft_split_to_node(num_split, 0, NULL, &stack_a) == 0)
	{
		move = get_next_line(0);
		while (move)
		{
			if (ft_applic_op(move, &stack_a, &stack_b) == 0)
			{
				ft_free_all_ta3_all(numbers, num_split, &stack_a, &stack_b);
				return (ft_printf("Error\n"));
			}
			free(move);
			move = get_next_line(0);
		}
	}
	if (ft_check_sort(stack_a) == 1 && ft_lstsize(stack_b) == 0)
		write(1, "Ok\n", 3);
	else
		write(1, "Ko\n", 3);
	free(move);
	ft_free_all_ta3_all(numbers, num_split, &stack_a, &stack_b);
}
