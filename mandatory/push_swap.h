/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:48:22 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/25 02:39:01 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

char	**ft_free_all(char **ptr);
int		ft_split_to_node(char **num_split, long tmp_num, t_list *tmp_node,
			t_list **stack_a);
int		ft_check_space(char *s);
int		ft_check_num(t_list **lst, int num);
int		ft_check(char *s);
int		ft_check_arg(char *s);
int		ft_free_all_ta3_all(char *numbers, char **num_split, t_list **stack_a,
			t_list **stack_b);
int		ft_check_null(int argc, char **argv);
int		ft_check_spaces(char *argv);
int		ft_check_full_space(int argc, char **argv);
// sorting functions
void	ft_swap(t_list **stack, char type_stack);
void	ft_push(t_list **stack_from, t_list **stack_to, char type_from);
void	ft_swap_all(t_list **stack_a, t_list **stack_b, char type);
void	ft_rotate(t_list **stack, char type);
void	ft_rotate_all(t_list **stack_a, t_list **stack_b, char type);
void	ft_rev_rotate(t_list **stack, char type);
void	ft_rev_rotate_all(t_list **stack_a, t_list **stack_b, char type);
void	ft_sort_3(t_list **stack_a);
void	ft_sort_5(t_list **stack_a, t_list **stack_b);
int		find_position(t_list *stack, int value);
int		find_highest(t_list *stack);
void	ft_position_in_array(int *array, t_list *stack_a);
int		find_index(t_list *a, int x, int p);
void	ft_push_to_a(t_list **stack_a, t_list **stack_b);
void	ft_sort_chunk(t_list **stack_a, t_list **stack_b, int *array, int p);
void	ft_sort(t_list **stack_a, t_list **stack_b);
// array
int		*ft_fill_aray(t_list *stack);
int		ft_check_array(int *array, int size_arr);
void	ft_sort_array(int *array, int size_arr);

#endif