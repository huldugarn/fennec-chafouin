# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:57:32 by rle-corr          #+#    #+#              #
#    Updated: 2016/05/12 11:53:59 by rle-corr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -----------------------------------------------------------------------------#
#	Variables 
# -----------------------------------------------------------------------------#

# ----	Variable de processus  ------------------------------------------------#
EXENAME = exe
LIBNAME = libftprintf.a
CMPNAME = gcc
CMPFLAG = -Wall -Werror -Wextra
LIBFLAG = -lftprintf
ARCHIVE = ar -rc

# ----	Variable d'environnement  ---------------------------------------------#
HOMEDIR = $(shell pwd)
INC_DIR = $(HOMEDIR)/includes
SRC_DIR = $(HOMEDIR)/sources
OBJ_DIR = $(HOMEDIR)/objects

# ----	Listes de fichiers	---------------------------------------------------#
INCLIBS = $(addprefix $(INC_DIR)/,libft/libft.a)
SRCNAME = main.c\
		  aux0_options_management.c\
		  aux1_options_lengths.c\
		  aux2_conversions_hub.c\
		  aux3_conversions_alpha.c\
		  aux4_conversions_num.c\
		  aux5_unicode.c
SRCFULL = $(addprefix $(SRC_DIR)/,$(SRCNAME))
SRCLIST = $(basename $(notdir $(SRCFULL)))
OBJFULL = $(addprefix $(OBJ_DIR)/,$(addsuffix .o, $(SRCLIST)))

# -----------------------------------------------------------------------------#
#	Aide 
# -----------------------------------------------------------------------------#

.PHONY: help

help:
	@echo "<*----------------------------------------------------------------*>"
	@echo " | Available rules"
	@echo " |   - all	:	code compilation and library creation"
	@echo " |   - clean	:	objects deleting"
	@echo " |   - fclean	:	objects and executable deleting"
	@echo " |   - re	:	fclean + all"
	@echo "<*----------------------------------------------------------------*>"

# -----------------------------------------------------------------------------#
#	Compilation 
# -----------------------------------------------------------------------------#

.PHONY: all, exe, lib, mkdir_objects, clean, lclean, fclean, re

all: inc lib

# ----	Gestion des includes  -------------------------------------------------#
inc:
	@make -C $(INC_DIR)/libft/

# ----	Création de l'éxécutable  ---------------------------------------------#
exe: lib
	@$(CMPNAME) $(LIBFLAG) $(INCLIBS) test.c -o $(EXENAME)
	@echo Program_created

# ----	Création de la librairie  ---------------------------------------------#

lib: mkdir_objects $(OBJFULL)
	@echo Objects_created
	@$(ARCHIVE) $(LIBNAME) $(OBJFULL)
	@echo Library_created

# ----	Création du répertoire objets  ----------------------------------------#
mkdir_objects:
	@mkdir $(OBJ_DIR)

# ----	Compilation des sources	 ----------------------------------------------#
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CMPNAME) -c $(CMPFLAG) -I$(INC_DIR) -o $@ $<

# ----	Règles de nettoyage	 --------------------------------------------------#
clean:
	@/bin/rm -Rf $(OBJ_DIR)
	@echo Objects_deleted

lclean: clean
	@/bin/rm -f $(LIBNAME)
	@echo Library_deleted

fclean: lclean
	@/bin/rm -f $(EXENAME)
	@echo Program_deleted

re: fclean all clean
