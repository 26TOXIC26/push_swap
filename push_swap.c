/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:19:24 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/09 00:15:36 by amousaid         ###   ########.fr       */
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

void	ft_rev_swap(t_list **stack_a, char type)
{
	ft_rev_rotate(stack_a, type);
	ft_swap(stack_a, type);
}

void	ft_rot_swap(t_list **stack_a, char type)
{
	ft_rotate(stack_a, type);
	ft_swap(stack_a, type);
}

void	ft_sort_3(t_list **stack_a)
{
	t_list	*head;
	t_list	*n1;
	t_list	*n2;

	head = (*stack_a);
	n1 = (*stack_a)->next;
	n2 = (*stack_a)->next->next;
	if ((head->value) > (n1->value) && (n1->value)
		< (n2->value) && (head->value) > (n2->value))
		ft_rotate(stack_a, 'a');
	else if ((head->value) > (n1->value) && (n1->value)
		< (n2->value) && (head->value) < (n2->value))
		ft_swap(stack_a, 'a');
	else if ((head->value) < (n1->value) && (n1->value)
		> (n2->value) && (head->value) > (n2->value))
		ft_rev_rotate(stack_a, 'a');
	else if ((head->value) < (n1->value) && (n1->value)
		> (n2->value) && (head->value) < (n2->value))
		ft_rev_swap(stack_a, 'a');
	else if ((head->value) > (n1->value) && (n1->value)
		> (n2->value) && (head->value) > (n2->value))
		ft_rot_swap(stack_a, 'a');
}

int	main(int argc, char **argv)
{
	int			i;
	static char	*numbers;
	static char	**num_split;
	t_list		*stack_a;
	char		*tmp;

	if (argc < 2)
		return (ft_printf("[YOU NEED MORE ARGUMENT]\n"));
	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		tmp = numbers;
		numbers = ft_strjoin(numbers, argv[i++]);
		free(tmp);
	}
	if (ft_check_arg(numbers) == 0)
	{
		free(numbers);
		return (ft_printf("[ERROR IN ARGUMENT]\n"));
	}
	num_split = ft_split(numbers, ' ');
	if (ft_split_to_node(num_split, 0, NULL, &stack_a) > 0)
		return (ft_free_all_ta3_all(numbers, num_split, &stack_a));
	// ft_sort_3(&stack_a);
	ft_print_list(stack_a);
	ft_free_all_ta3_all(numbers, num_split, &stack_a);
}
