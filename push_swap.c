/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:19:24 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/06 21:52:32 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	static char	*numbers;
	static char	**num_split;
	t_list		*stack_a;
	char		*tmp;

	i = 1;
	stack_a = NULL;
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
