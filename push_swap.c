/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:19:24 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/18 16:44:21 by amousaid         ###   ########.fr       */
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

long ft_find_in_array(int target, int *array, int border)
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

void ft_check_chunk(t_list **stack_a, t_list **stack_b, int *array)
{
	int border;
	int highest;
	int position;
	
	border = (ft_lstsize(*stack_a) / 5) - 1;
	while(ft_lstsize(*stack_a) > 0)
	{
		// ft_printf("ana hna");
		if(ft_find_in_array((*stack_a)->value, array, border) == 1)
		{
			ft_push(stack_a, stack_b, 'a');			
			if (ft_lstsize(*stack_b) >= (border + 1))
				border = border + ((ft_lstsize(*stack_a) + ft_lstsize(*stack_b)) / 5);
		}
		else
			ft_rev_rotate(stack_a, 'a');
	}

	// printf("ana hna\n");
	highest = find_highest(*stack_b);
	while(ft_lstsize(*stack_b) > 1)
	{
		if(highest == (*stack_b)->value)
		{
			ft_push(stack_b, stack_a, 'b');
			highest = find_highest(*stack_b);
		}
		position = find_position(*stack_b, highest);
		if(position > (ft_lstsize(*stack_b) / 2))
			ft_rev_rotate(stack_b, 'b');
		else
			ft_rotate(stack_b, 'b');
	}
	ft_push(stack_b, stack_a, 'b');
	// ft_print_list(*stack_a);
}

void ft_sort(t_list **stack_a, t_list **stack_b)
{
	int *array;
	int i;

	i = 0;
	array = ft_fill_aray(*stack_a);
	ft_sort_array(array, ft_lstsize(*stack_a));
	ft_check_chunk(stack_a, stack_b, array);
	
	// stack_b = NULL;
	free(array);
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

int ft_check_spaces(char *argv)
{
	int i;
	
	i = 0;
	while (argv[i])
	{
		if (argv[i++] != ' ')
			return (1);
	}
	return (0);
}
int ft_check_full_space(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_check_space(argv[i++]) == 0)
			return (0);
	}
	return (1);
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
		else
			ft_sort(stack_a, stack_b);
		

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
