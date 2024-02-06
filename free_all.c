/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:50:43 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/06 21:51:21 by amousaid         ###   ########.fr       */
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

int	ft_free_all_ta3_all(char *numbers, char **num_split, t_list **stack_a)
{
	free(numbers);
	ft_free_all(num_split);
	ft_lstclear(stack_a);
	return (0);
}