EXENAME=fdf
CMPNAME=gcc
CMPFLAG=-Wall -Werror -Wextra
SRCNAME=
OBJNAME=$(SRCNAME:.c=.o)


all: $(EXENAME)

$(EXENAME): objectify

objectify:
	$(CMPNAME) $(CMPFLAG)

clean:

fclean: clean

re: fclean all
