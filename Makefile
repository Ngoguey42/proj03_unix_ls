#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 11:28:17 by ngoguey           #+#    #+#              #
#    Updated: 2014/11/12 15:56:01 by ngoguey          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls


ERRSRCPATH = ft_error
ERRINCLUDE = $(ERRSRCPATH)/

SRCPATH = .
INCLUDE = ./

OBJPATH = obj

LFTPATH = libft/
LFTIPATH = $(LFTPATH)includes/

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRCSFILES = main.c debug.c free_mem.c args_saving.c args_saving_pertype.c\
print_long_format.c print_small_format.c print_target_format.c
ERRSRCSFILES = ft_error.c


SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.c=$(OBJPATH)/%.o)

ERRSRC = $(addprefix $(ERRSRCPATH)/,$(ERRSRCSFILES))
ERROBJECTS = $(ERRSRC:$(ERRSRCPATH)/%.c=$(OBJPATH)/%.o)

all: $(NAME)

$(NAME): cpllibft $(OBJECTS) $(ERROBJECTS)
	@echo "[COMPILING FT_LS]"
	$(CC) -o $@ $(CFLAGS) $(OBJECTS) $(ERROBJECTS) -L $(LFTPATH) -lft
	@echo -e "[COMPILING FT_LS DONE]\n"

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) -I $(LFTIPATH) -I $(INCLUDE) -I $(ERRINCLUDE) -L $(LFTPATH) -lft -c $<

$(ERROBJECTS): $(OBJPATH)/%.o : $(ERRSRCPATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) -I $(LFTIPATH) -I $(INCLUDE) -I $(ERRINCLUDE) -L $(LFTPATH) -lft -c $<

cpllibft:
	@echo "[COMPILING LIBFT]"
	make -C $(LFTPATH)
	@echo "[COMPILING LIBFT DONE]"

clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

relft:
	make -C $(LFTPATH) re