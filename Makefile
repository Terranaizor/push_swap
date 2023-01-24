# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nradin <nradin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 13:37:00 by nradin            #+#    #+#              #
#    Updated: 2023/01/24 19:16:28 by nradin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	push_swap.c					\
		stack_utils_1.c				\
		stack_utils_2.c				\
		stack_operations.c			\
		stack_mixed_operations.c	\
		rotations.c					\
		long_inc_seq.c				\
		push_back.c					\
		parse_input.c				\
		atoi_error.c				\
		input_utils.c				\

SRC_MAIN = 	main.c

SRCS_BONUS = 	checker.c	\

NAME = push_swap
BONUS = checker

LIBFT = inc/libft/

PRINTF = inc/printf/

OBJS_DIR = objs/
OBJS_BONUS_DIR = objs_bonus/
SRCS_DIR = srcs/push_swap/
SRCS_BONUS_DIR = srcs/checker/

OBJS = $(SRCS:.c=.o)
OBJ_MAIN = $(SRC_MAIN:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
OBJECT_MAIN_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJ_MAIN))
OBJECTS_BONUS_PREFIXED = $(addprefix $(OBJS_BONUS_DIR), $(OBJS_BONUS))
SOURCES_PREFIXED = $(addprefix $(SRCS_DIR), $(SRCS))
SOURCE_MAIN_PREFIXED = $(addprefix $(SRCS_DIR), $(SRC_MAIN))
SOURCES_BONUS_PREFIXED = $(addprefix $(SRCS_BONUS_DIR), $(SRCS_BONUS))

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c inc/push_swap.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -c $< -o $@

$(OBJS_BONUS_DIR)%.o : $(SRCS_BONUS_DIR)%.c inc/push_swap.h
	@mkdir -p $(OBJS_BONUS_DIR)
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED) $(OBJECT_MAIN_PREFIXED)
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@gcc -o $(NAME) $(OBJECTS_PREFIXED) $(OBJECT_MAIN_PREFIXED) inc/libft/libft.a inc/printf/libftprintf.a

$(BONUS): $(OBJECTS_BONUS_PREFIXED) $(OBJECTS_PREFIXED)
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@gcc -o $(BONUS) $(OBJECTS_BONUS_PREFIXED) $(OBJECTS_PREFIXED) inc/libft/libft.a inc/printf/libftprintf.a

bonus: $(BONUS)

all: $(NAME) $(BONUS)

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(OBJS_BONUS_DIR)
	@make fclean -C $(LIBFT)
	@make fclean -C $(PRINTF)


fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS)

re: fclean all
