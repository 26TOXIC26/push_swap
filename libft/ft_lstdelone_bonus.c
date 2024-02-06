/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:57:24 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/05 08:56:01 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	// del(&lst->value);
	free(lst);
	lst = NULL;
}
// void del(int *value)
// {
//     free(value);
//     printf("rani wslt lhna\n");
//     value = NULL;
// }
// int main()
// {
//     char *pt = ft_strdup("test");
//     t_list *head = ft_lstnew(pt);
//     printf("%s\n", head -> content);
//     ft_lstdelone(head, del);
//     printf("%s\n", *((char *)head ->content));
// }