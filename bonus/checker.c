/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:50:02 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/26 02:57:52 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	main(int argc, char **argv)
{
	static char			*numbers;
	static char			**num_split;
	static t_list		*stack_a;
	static t_list		*stack_b;

	if (argc < 2 || (ft_check_n(argc, argv) != 0))
		return (0);
	numbers = ft_join(argc, argv);
	if (ft_check_arg(numbers) == 0)
	{
		free(numbers);
		return (ft_printf("Error\n"));
	}
	num_split = ft_split(numbers, ' ');
	if (ft_split_to_node(num_split, 0, NULL, &stack_a) == 0)
	{
		if (ft_call_appli(&stack_a, &stack_b) == 0)
		{
			ft_free_all_ta3_all(numbers, num_split, &stack_a, &stack_b);
			return (ft_printf("Error\n"));
		}
		ft_ok_ko(stack_a, stack_b);
	}
	ft_free_all_ta3_all(numbers, num_split, &stack_a, &stack_b);
}
