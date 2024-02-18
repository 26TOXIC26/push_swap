/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:48:22 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/18 14:50:01 by amousaid         ###   ########.fr       */
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
int		ft_free_all_ta3_all(char *numbers, char **num_split, t_list **stack_a, t_list **stack_b);
// sorting functions
void	ft_swap(t_list **stack, char type_stack);
void	ft_push(t_list **stack_from, t_list **stack_to, char type_from);
void	ft_swap_all(t_list **stack_a, t_list **stack_b);
void	ft_rotate(t_list **stack, char type);
void	ft_rotate_all(t_list **stack_a, t_list **stack_b);
void	ft_rev_rotate(t_list **stack, char type);
void	ft_sort_3(t_list **stack_a);
void	ft_sort_5(t_list **stack_a, t_list **stack_b);
int		find_position(t_list *stack, int value);
int	find_highest(t_list *stack);

#endif