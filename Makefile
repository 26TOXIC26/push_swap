# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 00:12:14 by amousaid          #+#    #+#              #
#    Updated: 2024/02/19 15:39:12 by amousaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
RM = rm -rf

PUSH_SRC = push_swap.c\
 			add_to_list.c\
			check_arg.c\
			free_all.c\
			swap.c\
			push.c\
			rotate.c\
			sort_3_5.c\
			array.c\
			check_spaces.c\
			

all: $(NAME)

$(LIBFT):
		$(MAKE) --no-print-directory -C ./libft
		
$(FT_PRINTF):
		$(MAKE) --no-print-directory -C ./ft_printf
		
$(NAME): $(LIBFT) $(FT_PRINTF) $(PUSH_SRC) 
	$(CC) $(CFLAGS) $(PUSH_SRC) $(LIBFT) $(FT_PRINTF) -o push_swap
	@echo "  [IS MAKE!!]"

clean:
	$(MAKE) clean --no-print-directory -C ./libft
	$(MAKE) clean --no-print-directory -C ./ft_printf
	@echo "  [IS CLEAN!]"

fclean: clean
	$(MAKE) fclean --no-print-directory -C ./libft
	$(MAKE) fclean --no-print-directory -C ./ft_printf
	$(RM) $(NAME)
	@echo "[IS FULL CLEAN]"

re: fclean all

.SILENT:
