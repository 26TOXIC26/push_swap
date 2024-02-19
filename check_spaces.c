/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:26:58 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/19 15:27:44 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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