# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 18:26:55 by gamoreno          #+#    #+#              #
#    Updated: 2022/09/30 20:11:30 by gamoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Compilation ###

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I.

### Executable ###

NAME	=	libft.a

### Inculdes ###

OBJ_PATH = objs
HEADER = includes
SRC_PATH = sources

### Source Files ###

SOURCES	= 	ft_strcmp.c ft_atof.c ft_isdigit.c ft_substr.c ft_strchr.c\
		ft_strlen.c ft_strdup.c ft_itoa.c ft_strjoin.c ft_ftoa.c\
		ft_putstr_fd.c ft_atoli.c ft_atoi.c ft_bzero.c ft_calloc.c\
		ft_abs.c
			

### Objects ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

### COLORS ###
NOC         = \033[0m
GREEN       = \033[1;32m
CYAN        = \033[1;36m

### RULES ###

all:		tmp $(NAME)

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)
		@echo "$(GREEN)libft made succesfully$(NOC)"

tmp:
		@mkdir -p objs

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
		@$(CC) $(FLAGS) -c -o $@ $<
		@echo "$(CYAN)Creation of object file -> $(CYAN)$(notdir $@)... $(GREEN)[Done]$(NOC)"

clean:
		rm -rf $(OBJ_PATH)


fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re bonus
