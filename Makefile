#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 11:28:17 by ngoguey           #+#    #+#              #
#    Updated: 2015/01/13 11:01:13 by ngoguey          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

# LIBFT
LFTPATH = libft/
LFTIPATH = $(LFTPATH)includes/
LFT = -L $(LFTPATH) -lft

# FT_ERROR
ERRSRCPATH = ft_error
ERRINCLUDE = $(ERRSRCPATH)/

OBJPATH = obj
SRCPATH = .
INCLUDE = ./

CC = gcc

LIBS = $(LFT)
INCLUDES = -I $(INCLUDE) -I $(LFTIPATH) -I $(ERRINCLUDE)


BASEFLAGS = -Wall -Wextra
CFLAGS = $(BASEFLAGS) -Werror -O2
DEBUGFLAGS = $(BASEFLAGS) -g

LFTCALL = all
LFTRE = re
LFTG = g
LFTGRE = gre

SRCSFILES = main.c free_mem.c args_saving.c args_saving_pertype.c\
print_long_format.c print_small_format.c sort_func.c print_directories.c\
print_targets.c metatab_functions.c print_long_format_acls.c
ERRSRCSFILES = ft_error.c

SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.c=$(OBJPATH)/%.o)
ERRSRC = $(addprefix $(ERRSRCPATH)/,$(ERRSRCSFILES))
ERROBJECTS = $(ERRSRC:$(ERRSRCPATH)/%.c=$(OBJPATH)/%.o)

RM = rm -rf

Y = \033[0;33m
R = \033[0;31m
G = \033[0;32m
E = \033[39m

all:
	make l
	make $(NAME)

$(NAME): $(OBJECTS) $(ERROBJECTS)
	@echo -e "$(Y)[COMPILING FT_LS] $(G) $(CC) -o $@ $(CFLAGS) objs.o error.o $(LIBS) $(E)"
	@$(CC) -o $@ $(CFLAGS) $(OBJECTS) $(ERROBJECTS) $(LIBS)
	@echo -e "$(Y)[COMPILING FT_LS DONE]$(E)"

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

$(ERROBJECTS): $(OBJPATH)/%.o : $(ERRSRCPATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)

l:
	@echo -e "$(Y)[COMPILING LIBFT] $(G) make -C $(LFTPATH) $(LFTCALL) $(E)"
	make -C $(LFTPATH) $(LFTCALL)
	@echo -e "$(Y)[COMPILING LIBFT DONE]$(E)"

g: _g _gft all

# re rules
re: fclean all
rel: _relft l
rea: _relft re

# gre rules
gre: _g _gft re
grel: _greft l
grea: _g _greft re

# eval rules
_g:
	$(eval CFLAGS = $(DEBUGFLAGS))
_relft:
	$(eval LFTCALL = $(LFTRE))
_gft:
	$(eval LFTCALL = $(LFTG))
_greft:
	$(eval LFTCALL = $(LFTGRE))
