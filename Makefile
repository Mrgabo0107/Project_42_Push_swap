# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:34:13 by gamoreno          #+#    #+#              #
#    Updated: 2022/09/09 16:37:27 by gamoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Compilation ###

CC      = cc
FLAGS  = -Wall -Wextra -Werror -g

### Executable ###

NAME   = push_swap

### Includes ###

OBJ_PATH  = objs
HEADER = includes
SRC_PATH  = sources
LIBFT = libft

### Source Files ###

SOURCES =	main.c\
			parsing.c\
			init_1.c\
			init_2.c\
			error.c\
			operations_1.c\
			operations_2.c\
			operations_3.c\
			algorithm.c\
			split_a_to_b_1.c\
			split_a_to_b_2.c\
			split_a_to_b_3.c\
			split_a_to_b_4.c\
			split_b_to_a_1.c\
			split_b_to_a_2.c\
			split_b_to_a_3.c\
			split_b_to_a_4.c\
			split_helpers_1.c\
			split_helpers_2.c\
			group_operations_1.c\
			group_operations_2.c\
			group_operations_helpers.c\
			attracts_1.c\
			attracts_2.c
	
### Objects ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

### COLORS ###
NOC         = \033[0m
GREEN       = \033[1;32m
CYAN        = \033[1;36m

### RULES ###

all: lib tmp $(NAME)

lib:
	@make --no-print-directory -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -L $(LIBFT) -o $@ $^ -l:libft.a 
	@echo "$(GREEN)Project compiled succesfully$(NOC)"

tmp:
	@mkdir -p objs

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/*.h
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(CYAN)Creation of object file -> $(CYAN)$(notdir $@)... $(GREEN)[Done]$(NOC)"

clean:
	@echo "$(GREEN)Cleaning libraries$(NOC)"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH)

fclean:
	@echo "$(GREEN)Cleaning libraries files$(NOC)"
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: tmp, re, fclean, clean
