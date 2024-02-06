/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:19:24 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/06 09:41:21 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_num(t_list **lst, int num)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next)
	{
		if (num == tmp->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

char	**ft_free_all(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}

int	ft_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == '-' || s[i] == '+') && ((i != 0 && s[i - 1] != ' ') || s[i
					+ 1] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_arg(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	if (ft_check(s) == 0)
		return (0);
	return (1);
}

int	ft_free_all_ta3_all(char *numbers, char **num_split, t_list **stack_a)
{
	free(numbers);
	ft_free_all(num_split);
	ft_lstclear(stack_a);
	return (0);
}

int	ft_check_sort(t_list **stack_a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *stack_a;
	tmp2 = tmp1->next;
	while (tmp1 && tmp2)
	{
		while (tmp2)
		{
			if (tmp1->value > tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp1->next;
	}
	return (0);
}

int	ft_split_to_node(char **num_split, long tmp_num, t_list *tmp_node,
		t_list **stack_a)
{
	int		i;
	long	tmp_num2;

	i = 0;
	while (num_split[i])
	{
		tmp_num2 = tmp_num;
		tmp_num = ft_atoi(num_split[i]);
		if (tmp_num > INT_MAX || tmp_num < INT_MIN)
			return (ft_printf("[YOU'VE CROSSED THE INTEGER LIMITS]\n"));
		if (i != 0)
		{
			if ((ft_check_num(stack_a, tmp_num) == 0 || tmp_num2 == tmp_num)
				&& i != 0)
				return (ft_printf("[DOUBLE NUMBER!!]\n"));
		}
		tmp_node = ft_lstnew(tmp_num);
		ft_lstadd_back(stack_a, tmp_node);
		i++;
	}
	if (ft_check_sort(stack_a) == 0)
		return (ft_printf("[YOUR NUMBERS ARE PRE-SORTED]\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	char		*numbers;
	static char	**num_split;
	t_list		*stack_a;
	char		*tmp;

	i = 1;
	stack_a = NULL;
	if (argc > 2)
	{
		while (i < argc)
		{
			tmp = numbers;
			numbers = ft_strjoin(numbers, argv[i++]);
			free(tmp);
		}
		if (ft_check_arg(numbers) == 0)
			return (ft_printf("[ERROR IN ARGUMENT]\n"));
		num_split = ft_split(numbers, ' ');
		if (ft_split_to_node(num_split, 0, NULL, &stack_a) > 0)
			return (ft_free_all_ta3_all(numbers, num_split, &stack_a));
		ft_free_all_ta3_all(numbers, num_split, &stack_a);
	}
	else
		ft_printf("[YOU NEED MORE ARGUMENT]\n");
}
