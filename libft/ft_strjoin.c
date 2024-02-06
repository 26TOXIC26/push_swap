/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:01:13 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/03 22:37:00 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *d, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = ' ';
	d[i+1] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 && !s2)
	{
		result = malloc(ft_strlen(s1) + 2);
		ft_strcpy (result, s1);
	}
	else if (!s1 && s2)
	{
		result = malloc(ft_strlen(s2) + 2);
		ft_strcpy (result, s2);
	}
	else
	{
		result = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
		if (result == NULL)
			return (NULL);
		ft_strcpy(result, s1);
		ft_strcpy(result + ft_strlen(s1), s2);
	}
	return (result);
}
