# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 14:31:01 by aarponen          #+#    #+#              #
#    Updated: 2023/09/13 12:46:35 by aarponen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra -g
HEADER = includes/push_swap.h

INC_DIR = includes
LIBFT_DIR = Libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRC_DIR = src
SRC_FILES = main.c validation.c sort_moves.c sorting.c sort_big_pos.c sort_big_cost.c sort_big_move.c
OBJ_DIR = obj
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT_LIB)
	$(CC) $(FLAGS) -o $@ $^
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c -o $@ $< -I$(INC_DIR) -I$(LIBFT_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
