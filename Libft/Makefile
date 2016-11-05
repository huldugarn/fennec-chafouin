# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:57:32 by rle-corr          #+#    #+#              #
#    Updated: 2016/03/24 16:33:31 by rle-corr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CMP_NAME = gcc
CMP_FLAG = -Wall -Werror -Wextra
DELETING = rm -f
ARCHIVES = ar -rc
INC_PATH = -I.
LIB_PATH = -L.
LIB_NAME = -lft
LIB_FLAG = $(LIB_PATH) $(LIB_NAME)
SRC_PATH = .
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_NAME = ft_character_operations_1.c		ft_character_operations_2.c \
		   ft_atoi.c		ft_itoa.c		ft_lstadd.c		ft_lstdel.c \
		   ft_lstdelone.c	ft_lstiter.c	ft_lstmap.c		ft_lstnew.c \
		   ft_lstpushback.c \
		   ft_memory_operations_1.c			ft_memory_operations_2.c \
		   ft_string_operations_1.c \
		   ft_string_copy.c	ft_string_concatenate.c \
		   ft_string_join.c ft_string_duplicate.c \
		   ft_putchar.c		ft_putendl.c	ft_putendl_fd.c \
		   ft_putnbr.c		ft_putnbr_fd.c	ft_putstr.c\
		   ft_squareroot.c	ft_strclr.c		ft_strchr.c \
		   ft_strcmp.c		ft_strdel.c	\
		   ft_strequ.c		ft_striter.c	ft_striteri.c\
		   ft_strmap.c		ft_strmapi.c	ft_strncmp.c \
		   ft_strnequ.c		ft_strnextc.c\
		   ft_strnstr.c		ft_strrchr.c	ft_strsplit.c	ft_strstr.c \
		   ft_strsub.c		ft_strtrim.c \
		   get_next_line.c	ft_maths.c		ft_unicode.c
SRC_FULL = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

.PHONY: all, clean, fclean, re

all : $(NAME)

$(NAME): $(OBJ_NAME)
	@$(ARCHIVES) $(NAME) $(OBJ_NAME)
	@echo Libft       : Library created

$(OBJ_NAME):
	@$(CMP_NAME) $(CMP_FLAG) $(INC_PATH) -c $(SRC_NAME) 

clean:
	@$(DELETING) $(OBJ_NAME)
	@echo Libft       : Objects deleted

fclean: clean
	@$(DELETING) $(NAME)
	@echo Libft       : Library deleted

re: fclean all
