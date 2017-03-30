# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:57:32 by rle-corr          #+#    #+#              #
#    Updated: 2016/11/22 11:49:54 by rle-corr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE_NAME = lem_in
TMP_NAME = test
CMP_NAME = gcc
CMP_FLAG = -Wall -Werror -Wextra
DELETING = rm -f
ARCHIVES = ar -rc
# deuxieme -I pour indiquer le chemin de la Libft et eviter de le mettre en absolu en entete de source
INC_PATH = -I./includes -I./Libft
LIB_PATH = -L./Libft
LIB_NAME = -lft
LIB_FLAG = $(LIB_PATH) $(LIB_NAME)
SRC_PATH = ./sources
SRC_NAME = main.c read.c
SRC_FULL = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

.PHONY: all, clean, fclean, re

all : $(EXE_NAME)

$(EXE_NAME): ./Libft/libft.a
	@$(CMP_NAME) $(CMP_FLAG) $(LIB_FLAG) $(INC_PATH) $(SRC_FULL) -o $(EXE_NAME)
#	@$(CMP_NAME) $(CMP_FLAG) $(LIB_FLAG) $(INC_PATH) $(SRC_FULL) -o $(TMP_NAME)
	@echo Executable created.

./Libft/libft.a:
	@make -C ./Libft/

clean:
	@$(DELETING) $(OBJ_NAME)
	@make -C ./Libft/ clean
	@echo Objects deleted.

fclean: clean
	@$(DELETING) $(EXE_NAME)
	@$(DELETING) ./Libft/libft.a 
	@echo Library deleted.

re: fclean all
