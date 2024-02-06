/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:48:22 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/06 23:25:53 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

char	**ft_free_all(char **ptr);
int		ft_split_to_node(char **num_split, long tmp_num, t_list *tmp_node,
			t_list **stack_a);
int		ft_check_space(char *s);
int		ft_check_num(t_list **lst, int num);
int		ft_check(char *s);
int		ft_check_arg(char *s);
int		ft_check_sort(t_list **stack_a);
int		ft_free_all_ta3_all(char *numbers, char **num_split, t_list **stack_a);
void ft_swap_a(t_list **stack_a);
#endif
