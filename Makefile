# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 00:12:14 by amousaid          #+#    #+#              #
#    Updated: 2024/02/25 19:50:00 by amousaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
RM = rm -rf

PUSH_SRC = ./mandatory/push_swap.c\
 			./mandatory/add_to_list.c\
			./mandatory/check_arg.c\
			./mandatory/free_all.c\
			./mandatory/swap.c\
			./mandatory/push.c\
			./mandatory/rotate.c\
			./mandatory/sort_3_5.c\
			./mandatory/array.c\
			./mandatory/check_spaces.c\
			./mandatory/big_sort.c\

BONUS_SRC = ./bonus/checker.c\
			./bonus/applic.c\
			./bonus/check_all.c\
			./bonus/get_next_line.c\
			./bonus/get_next_line_utils.c\
			./mandatory/add_to_list.c\
			./mandatory/check_arg.c\
			./mandatory/free_all.c\
			./mandatory/swap.c\
			./mandatory/push.c\
			./mandatory/rotate.c\
			./mandatory/sort_3_5.c\
			./mandatory/array.c\
			./mandatory/check_spaces.c\
			./mandatory/big_sort.c\

all: $(NAME)

bonus: $(BONUS)

$(LIBFT):
		$(MAKE) --no-print-directory -C ./libft
		
$(FT_PRINTF):
		$(MAKE) --no-print-directory -C ./ft_printf
		
$(NAME): $(LIBFT) $(FT_PRINTF) $(PUSH_SRC) 
	$(CC) $(CFLAGS) $(PUSH_SRC) $(LIBFT) $(FT_PRINTF) -o push_swap
	@echo "✅IS MAKE✅"

$(BONUS): $(LIBFT) $(FT_PRINTF) $(BONUS_SRC)
	$(CC) $(CFLAGS) $(BONUS_SRC) $(LIBFT) $(FT_PRINTF) -o checker
	@echo "✅BONUS✅"
clean:
	$(MAKE) clean --no-print-directory -C ./libft
	$(MAKE) clean --no-print-directory -C ./ft_printf
	@echo "🧹IS CLEAN🧹"

fclean: clean
	$(MAKE) fclean --no-print-directory -C ./libft
	$(MAKE) fclean --no-print-directory -C ./ft_printf
	$(RM) $(NAME)
	$(RM) $(BONUS)
	@echo "🧹IS FULL CLEAN🧹"

re: fclean all

.SILENT:
