/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:19:24 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/20 22:58:09 by amousaid         ###   ########.fr       */
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

int ft_find_in_array(int target, int *array, int border)
{
	int i;

	i = 0;
	while (i <= border)
	{
		if (target == array[i])
			return (1);	
		i++;
	}
	return 0;
}

int ft_position_in_array(int *array, t_list *stack_a, int border)
{
	int i;

	i = 0;
	while(stack_a)
	{
		if (ft_find_in_array(stack_a->value, array, border) == 1)
			return (i);
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}
int ft_position_in_chunk(int *array, int value, int border)
{
	int i;
	int position;

	i = border - 19;
	position = 1;
	while (i <= border)
	{
		if (array[i]==value)
			return (position);
		i++;
		position++;
	}
	return (position);
}
void ft_sort_chunk(t_list **stack_a, t_list **stack_b, int *array)
{
	int border;
	int highest;
	int position;
	// int old_bo;
	
	border = (ft_lstsize(*stack_a) / 12) - 1;
	// old_bo = border;
	while(ft_lstsize(*stack_a) > 0)
	{
		if(ft_find_in_array((*stack_a)->value, array, border) == 1)
		{
			if (ft_position_in_chunk(array, (*stack_a)->value, border) < 21)
			{
				ft_push(stack_a, stack_b, 'a');	
				ft_rotate(stack_b, 'b');
			}
			else
				ft_push(stack_a, stack_b, 'a');
			if (ft_lstsize(*stack_b) >= (border + 1))
				border = border + ((ft_lstsize(*stack_a) + ft_lstsize(*stack_b)) / 12);
		}
		else
		{
			if ((ft_position_in_array(array, *stack_a, border)) <= (ft_lstsize(*stack_a) / 2))
				ft_rotate(stack_a, 'a');
			else
				ft_rev_rotate(stack_a, 'a');	
		}
	}
	highest = find_highest(*stack_b);
	position = find_position(*stack_b, highest);
	while(ft_lstsize(*stack_b) > 0)
	{
		if(highest == (*stack_b)->value)
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
			if(position <= (ft_lstsize(*stack_b) / 2) && highest != (*stack_b)->value)
				ft_rotate(stack_b, 'b');
			else
				ft_rev_rotate(stack_b, 'b');
		}	
	}
}

void ft_sort(t_list **stack_a, t_list **stack_b)
{
	int *array;

	array = ft_fill_aray(*stack_a);
	ft_sort_array(array, ft_lstsize(*stack_a));
	ft_sort_chunk(stack_a, stack_b, array);
	
	// stack_b = NULL;
	free(array);
}


void ft_call_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2 &&
			(*stack_a)->value > (*stack_a)->next->value)
		ft_swap(stack_a, 'a');
	else if (ft_lstsize(*stack_a) == 3)
		ft_sort_3(stack_a);
	else if (ft_lstsize(*stack_a) == 5 || ft_lstsize(*stack_a) == 4)
		ft_sort_5(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) > 5 && ft_lstsize(*stack_a) <= 500)
		ft_sort(stack_a, stack_b);
	
	// ft_print_list(*stack_a);
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
		return (0);
	if (ft_check_null(argc, argv) == 0)
		return (ft_printf("Error\n"));
	if (ft_check_full_space(argc, argv) == 0)
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
		ft_call_sort(&stack_a, &stack_b);
	ft_free_all_ta3_all(numbers, num_split, &stack_a, &stack_b);
}
