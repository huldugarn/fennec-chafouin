# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/22 11:29:45 by rle-corr          #+#    #+#              #
#    Updated: 2016/09/22 11:29:49 by rle-corr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
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
SRC_NAME = main.c\
		   aux0_options_management.c	aux1_options_lengths.c \
		   aux2_conversions_hub.c		aux3_conversions_alpha.c \
		   aux4_conversions_num.c		aux5_unicode.c	ft_memset.c\
		   ft_atoi.c	ft_islower.c	ft_itoa.c		ft_isdigit.c\
		   ft_lstnew.c	ft_memalloc.c	ft_putchar.c	ft_lstpushback.c\
		   ft_putendl.c	ft_putnbr.c		ft_putstr.c		ft_strchr.c\
		   ft_strjoin.c	ft_strlen.c		ft_strndup.c	ft_strnew.c\
		   ft_strsub.c	ft_strnjoin.c	ft_toupper.c	ft_bzero.c\
		   ft_strcpy.c	ft_strncpy.c	ft_memmove.c	ft_memcpy.c
SRC_FULL = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

.PHONY: all, clean, fclean, re

all : $(NAME)

$(NAME): $(OBJ_NAME)
	$(ARCHIVES) $(NAME) $(OBJ_NAME)
	@ranlib $(NAME)
	@echo Libftprintf : Library created

$(OBJ_NAME):
	$(CMP_NAME) $(CMP_FLAG) $(INC_PATH) -c $(SRC_NAME) 

clean:
	$(DELETING) $(OBJ_NAME)
	@echo Libftprintf : Objects deleted

fclean: clean
	$(DELETING) $(NAME)
	@echo Libftprintf : Library deleted

re: fclean all
