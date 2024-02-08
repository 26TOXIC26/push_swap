# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 00:12:14 by amousaid          #+#    #+#              #
#    Updated: 2024/02/08 23:58:47 by amousaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
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

all: $(NAME)

$(LIBFT):
		$(MAKE) --no-print-directory -C ./libft
		
$(FT_PRINTF):
		$(MAKE) --no-print-directory -C ./ft_printf
		
$(NAME): $(LIBFT) $(FT_PRINTF) $(PUSH_SRC) 
	$(CC) $(CFLAGS) $(PUSH_SRC) $(LIBFT) $(FT_PRINTF) -o push_swap
	@echo "-----------[DONE]----------|"
	@echo "[LIBFT] is ready           |"
	@echo "[FT_PRINTF] is ready       |"
	@echo "[PUSH_SWAP] is ready       |"
	@echo "-----------[DONE]----------|"

clean:
	$(MAKE) clean --no-print-directory -C ./libft
	$(MAKE) clean --no-print-directory -C ./ft_printf
	@echo "-----------[DONE]----------|"
	@echo "[LIBFT OBJ] is clean.	   |"
	@echo "[FT_PRINTF OBJ] is clean.  |"
	@echo "---------------------------|"
fclean: clean
	$(MAKE) fclean --no-print-directory -C ./libft
	$(MAKE) fclean --no-print-directory -C ./ft_printf
	$(RM) $(NAME)
	@echo "[PUSH_SWAP] is clean.      |"
	@echo "---------------------------|"
re: fclean all

.SILENT:
