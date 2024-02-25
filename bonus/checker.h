/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:50:48 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/25 02:38:35 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../mandatory/push_swap.h"
# include "get_next_line.h"

int		ft_applic_op(char *move, t_list **stack_a, t_list **stack_b);
int		ft_call_appli(t_list **stack_a, t_list **stack_b);
int		ft_check_n(int argc, char **argv);
int		ft_check_sort(t_list *stack_a);
void	ft_ok_ko(t_list *stack_a, t_list *stack_b);
#endif
