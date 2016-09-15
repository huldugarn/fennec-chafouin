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
LIBNAME = ft_printf.a
CMPNAME = gcc
CMPFLAG = -Wall -Werror -Wextra
LIBFLAG = -lft
ARCHIVE = ar -rc

# ----	Variable d'environnement  ---------------------------------------------#
HOMEDIR = $(shell pwd)
INC_DIR = $(HOMEDIR)/includes
SRC_DIR = $(HOMEDIR)/sources
OBJ_DIR = $(HOMEDIR)/objects

# ----	Listes de fichiers	---------------------------------------------------#
SRCNAME = main.c\
		  aux0_options_management.c\
		  aux1_options_lengths.c\
		  aux2_conversions_hub.c\
		  aux3_conversions_alpha.c\
		  aux4_conversions_num.c\
		  aux5_unicode.c
SRCFULL = $(addprefix $(SRC_DIR)/,$(SRCNAME))
SCRLIST = $(basename $(notdir $(SRCFULL)))
OBJFULL = $(addprefix $(OBJ_DIR)/,$(addsuffix .o, $(SRCLIST)))

# -----------------------------------------------------------------------------#
#	Aide 
# -----------------------------------------------------------------------------#

.PHONY: help

help:
	@echo "<*----------------------------------------------------------------*>"
	@echo " | Available rules"
	@echo " |   - all	:	code compilation and executable creation"
	@echo " |   - clean	:	objects deleting"
	@echo " |   - fclean	:	objects and executable deleting"
	@echo " |   - re	:	fclean + all"
	@echo "<*----------------------------------------------------------------*>"

# -----------------------------------------------------------------------------#
#	Compilation 
# -----------------------------------------------------------------------------#

.PHONY: all, exe, lib, mkdir_objects, clean, lclean, fclean, re

all: exe

# ----	Création de l'éxécutable  ---------------------------------------------#
exe: lib
	@$(CMPNAME) $(LIBFLAG) -o $(EXENAME)
	@echo Program_created

# ----	Création de la librairie  ---------------------------------------------#
lib: mkdir_objects $(OBJFULL)
	@$(ARCHIVES) $(LIBNAME) $(OBJFULL)
	@echo Library_created

test: mkdir_objects $(OBJFULL)
	@echo Good to go

# ----	Création du répertoire objets  ----------------------------------------#
ifeq ($(strip $( $(wildcard $(OBJ_DIR)) ) ), )
mkdir_objects:
	@mkdir $(OBJ_DIR)
	@echo obj_dir_created
else
mkdir_objects:
	@echo obj_dir_exist
endif

# ----	Compilation des sources	 ----------------------------------------------#
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo tset
	$(CMPNAME) -c $(CMPFLAG) -I$(INC_DIR) -o $@ $<

# ----	Règles de nettoyage	 --------------------------------------------------#
clean:
	@rm -Rf $(OBJ_DIR)
	@echo Obj_dir_deleted

lclean: clean
	@rm -f $(LIBNAME)
	@echo Library_deleted

fclean: lclean
	@rm -f $(EXENAME)
	@echo Program_deleted

re: fclean all clean
