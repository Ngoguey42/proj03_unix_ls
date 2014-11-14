#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 11:29:36 by ngoguey           #+#    #+#              #
#    Updated: 2014/11/14 08:23:15 by ngoguey          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NNAME = ft
NAME = lib$(NNAME).a

INCLUDE = ./includes
SRCPATH = srcs
PTFSRCPATH = $(SRCPATH)/printf
OBJPATH = obj

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = ar rc
RM = rm -rf

Y = \033[0;33m
R = \033[0;31m
E = \033[39m

COUNT = 0
OBJPERLINES = 4
TABLEN = 28
W = 0

SRCSFILES = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putendl.c\
	ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
	ft_putnchar.c ft_putnbr_base.c \
	ft_isblank.c ft_isdigit.c ft_isxdigit.c ft_isspace.c ft_isgraph.c \
	ft_isupper.c ft_islower.c ft_isprint.c ft_isalnum.c ft_isalpha.c\
	ft_ispunct.c ft_iscntrl.c ft_isascii.c ft_tolower.c ft_toupper.c\
	ft_ispair.c ft_atoi.c \
	ft_revstr.c ft_pad_string.c ft_maxintlen.c \
	ft_lutoa.c ft_lutoa_a.c ft_itoa_c.c ft_itoa_a.c ft_itoa.c ft_utoa.c\
	ft_strcpy.c ft_strncpy.c ft_strlcpy.c ft_strcmp.c ft_strncmp.c\
	ft_strspn.c ft_strlcat.c ft_striter.c ft_striteri.c ft_strmap.c\
	ft_strlen.c ft_strstr.c ft_strcat.c ft_strchr.c ft_strcspn.c ft_strncat.c \
	ft_strdup.c ft_memcpy.c ft_memset.c ft_bzero.c ft_strrchr.c ft_strnstr.c \
	ft_memcmp.c ft_memmove.c ft_memchr.c ft_memccpy.c ft_strmapi.c\
	ft_myassert.c ft_match.c ft_myputnchar.c ft_memprint.c\
	ft_strjoin.c ft_strcharlen.c ft_strsplit.c\
	ft_strnew.c ft_strclr.c ft_strequ.c ft_memalloc.c ft_memdel.c ft_strdel.c \
	ft_strjoinfree.c ft_strnequ.c ft_strtrim.c ft_strsub.c \
	ft_powi.c ft_sqrtfloor.c ft_pythai.c \
	ft_abs.c ft_div.c operations.c \
	ft_dbltype.c ft_getbitarray.c \
	ft_log2.c ft_log16.c ft_log10.c ft_ceil.c ft_floor.c \
	evlxpr_calculate.c evlxpr_list.c evlxpr_convert_chain.c ft_eval_expr.c\
	ft_lstnew.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c\
	ft_lstmap.c ft_lstdupone.c ft_lstdup.c ft_lstiterif.c ft_lstfind.c \
	ft_lstdelwhere.c ft_lstpushwhere.c ft_lstnewwhere.c ft_lstpullwhere.c\
	ft_lstlast.c ft_lstparams.c ft_lstat.c ft_lstrev.c\
	ft_lstfreecont.c ft_lstsize.c ft_lstprntone.c ft_lstprnt.c ft_lstdelif.c

PTFSRCSFILES = add_color_flags.c                build_hex_float_norm.c           ft_printf.c\
add_color_tags.c                 build_hex_float_unnorm.c         \
buffer_flushcols.c               build_integers.c                 get_varg.c\
buffer_flushcols_concat.c        build_nonprintable_string.c      parse_format.c\
buffer_printf.c                  build_nonprintable_string_deps.c populate_build_nbr.c\
build_bonuses.c                  build_uppercases.c               store_opt_1to5.c\
build_chars_and_strings.c        calc_return_value.c              store_opt_6to8.c\
build_dependencies.c             debug.c\
build_hex_float.c                ft_getprintf.c

SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.c=$(OBJPATH)/%.o)


PTFSRC = $(addprefix $(PTFSRCPATH)/,$(PTFSRCSFILES))
PTFOBJECTS = $(PTFSRC:$(PTFSRCPATH)/%.c=$(OBJPATH)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(PTFOBJECTS)
	@printf "\n$(Y)%-6s$(E) $(R)%s$(E) lines\n" "total" $(shell wc -l $(SRC) | cut -d' ' -f5)
	@printf "$(Y)%-6s$(E) $(NAME) $(R)$(OBJPATH)/%.o$(E)\n" "$(LIB)"
	@$(LIB) $(NAME) $(OBJECTS) $(PTFOBJECTS)
	@printf "$(Y)%-6s$(E) $(NAME)\n" "ranlib"
	@ranlib $(NAME)

text1:
	@printf "$(Y)%-6s$(E) -o $(R)$(OBJPATH)/%%.o$(E) $(CFLAGS) -I $(INCLUDE) -c $(SRCPATH)/%%.c\n" "$(CC)"

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.c
	@if [ $(W) -eq 0 ] ; then printf "$(Y)%-6s$(E) -o $(R)$(OBJPATH)/%%.o$(E) $(CFLAGS) -I $(INCLUDE) -c $(SRCPATH)/%%.c\n" "$(CC)" ; fi
	$(eval W = 1)
	@mkdir -p $(dir $@)
	$(eval COUNT = $(shell echo "($(COUNT) + 1) % $(OBJPERLINES)" | bc))
	@printf "$(R)%-*s$(E)" $(TABLEN) "$@"
	@if [ $(COUNT) -eq 0 ] ; then echo "" ; fi
	@$(CC) -o $@ $(CFLAGS) -I $(INCLUDE) -c $<

$(PTFOBJECTS): $(OBJPATH)/%.o : $(PTFSRCPATH)/%.c
	$(CC) -o $@ -I $(INCLUDE) -c $<

clean:
	@printf "$(Y)%-6s$(E) $(OBJPATH)\n" "$(RM)"
	@$(RM) $(OBJPATH)

fclean: clean
	@printf "$(Y)%-6s$(E) $(NAME)\n" "$(RM)"
	@$(RM) $(NAME)

re: fclean all