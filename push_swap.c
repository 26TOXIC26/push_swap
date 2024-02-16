/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:19:24 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/16 15:52:59 by amousaid         ###   ########.fr       */
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

int find_position(t_list *stack, int smallest)
{
	int position;

	position = 0;
	while(smallest != stack->value)
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
int *ft_fill_aray(t_list *stack)
{
	int *array;
	int i;

	i = 0;
	array = malloc(ft_lstsize(stack) * sizeof(int));
	if (!array)
		return (NULL);
	while(stack)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (array);
}
int ft_check_array(int *array, int size_arr)
{
	int i;
	int j;

	i = 0;
	j = i + 1;
	while ((i + 1) < size_arr)
	{
		while (j < size_arr)
		{
			if (array[i] > array[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}
void ft_sort_array(int *array, int size_arr)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = i + 1;
	while (ft_check_array(array, size_arr) == 0)
	{
		while (j < size_arr)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			i++;
			j++;
		}
		i = 0;
		j = i + 1;
	}
	
}
void ft_sort(t_list **stack_a, t_list **stack_b)
{
	int *array;
	int i;

	i = 0;
	array = ft_fill_aray(*stack_a);
	ft_sort_array(array, ft_lstsize(*stack_a));
	
	
	stack_b = NULL;
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

	if (argc < 3)
		return (0);
	if (ft_check_null(argc, argv) == 0)
		return (0);
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
			ft_swap(&stack_a, 'a');
		else if (ft_lstsize(stack_a) == 3)
			ft_sort_3(&stack_a);
		else if (ft_lstsize(stack_a) == 5 || ft_lstsize(stack_a) == 4)
			ft_sort_5(&stack_a, &stack_b);
		else
			ft_sort(&stack_a, &stack_b);
		// ft_print_list(stack_a);
	}
	ft_free_all_ta3_all(numbers, num_split, &stack_a, &stack_b);
	
}
