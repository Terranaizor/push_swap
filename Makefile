# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nradin <nradin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 13:37:00 by nradin            #+#    #+#              #
#    Updated: 2023/01/18 19:10:25 by nradin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.c						\
		push_swap.c					\
		stack_utils_1.c				\
		stack_utils_2.c				\
		stack_operations.c			\
		stack_mixed_operations.c	\
		check_rotates.c				\
		rotations.c					\
		lis.c						\
		push_back.c					\

NAME = push_swap

LIBFT = libft

PRINTF = printf

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c push_swap.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@gcc -o $(NAME) $(OBJECTS_PREFIXED) libft/libft.a printf/libftprintf.a

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f libft.a

re: fclean all
