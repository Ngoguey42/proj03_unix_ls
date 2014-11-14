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

INCLUDE = ./
SRCPATH = .
OBJPATH = obj
LFTPATH = libft/
LFTIPATH = includes/

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRCSFILES = main.c

SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.c=$(OBJPATH)/%.o)

all: $(NAME)

$(NAME): cpllibft $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(OBJECTS) -L $(LFTPATH) -lft

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.c
	mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) -I $(LFTPATH)$(LFTIPATH) -I $(INCLUDE) -L $(LFTPATH) -lft -c $<

cpllibft:
	make -C $(LFTPATH)

clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

relft:
	make -C $(LFTPATH) re