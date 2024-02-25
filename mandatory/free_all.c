/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:50:43 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/12 09:02:09 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_free_all_ta3_all(char *numbers, char **num_split, t_list **stack_a,
		t_list **stack_b)
{
	free(numbers);
	ft_free_all(num_split);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	return (0);
}
