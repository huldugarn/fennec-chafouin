# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:57:32 by rle-corr          #+#    #+#              #
#    Updated: 2016/02/23 16:26:19 by rle-corr         ###   ########.fr        #
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
SRC_NAME = ft_atoi.c		ft_bzero.c		ft_isalnum.c    ft_isalpha.c \
		   ft_isascii.c		ft_isdigit.c	ft_islower.c	ft_isprint.c \
		   ft_isupper.c		ft_itoa.c		ft_lstadd.c		ft_lstdel.c \
		   ft_lstdelone.c	ft_lstiter.c	ft_lstmap.c		ft_lstnew.c \
		   ft_memalloc.c	ft_memccpy.c	ft_memchr.c		ft_memcmp.c \
		   ft_memcpy.c		ft_memdel.c		ft_memmove.c	ft_memset.c \
		   ft_putchar.c		ft_putchar_fd.c	ft_putendl.c	ft_putendl_fd.c \
		   ft_putnbr.c		ft_putnbr_fd.c	ft_putstr.c		ft_putstr_fd.c \
		   ft_squareroot.c	ft_strcat.c		ft_strclr.c		ft_strchr.c \
		   ft_strcmp.c		ft_strcpy.c		ft_strdel.c		ft_strdup.c \
		   ft_strequ.c		ft_striter.c	ft_striteri.c	ft_strjoin.c \
		   ft_strlcat.c		ft_strlen.c		ft_strmap.c		ft_strmapi.c \
		   ft_strncat.c		ft_strncmp.c	ft_strncpy.c	ft_strndup.c \
		   ft_strnequ.c		ft_strnjoin.c	ft_strnew.c		ft_strnextoccur.c \
		   ft_strnstr.c		ft_strrchr.c	ft_strsplit.c	ft_strstr.c \
		   ft_strsub.c		ft_strtrim.c	ft_tolower.c	ft_lstpushback.c
SRC_FULL = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

.PHONY: all, clean, fclean, re

all : $(NAME)

$(NAME): $(OBJ_NAME)
	@$(ARCHIVES) $(NAME) $(OBJ_NAME)
	@echo Library created.

$(OBJ_NAME):
	@$(CMP_NAME) $(CMP_FLAG) $(INC_PATH) -c $(SRC_NAME) 

clean:
	@$(DELETING) $(OBJ_NAME)
	@echo Objects deleted.

fclean: clean
	@$(DELETING) $(NAME)
	@echo Library deleted.

re: fclean all
