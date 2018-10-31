# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwood <gwood@42.us.org>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/30 14:30:20 by mhurd             #+#    #+#              #
#    Updated: 2018/10/30 15:17:50 by gwood            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= wolf3d

SRC		= main.c \
			vec2d.c \
			mat2d.c \
			mat2d_tr.c \
			drawline2d.c \
			drawtri2d.c \
			vec3d.c \
			mat3d.c \
			mat3d_tr.c \
			drawline3d.c \
			drawtri3d.c \
			vertex.c \
			vertlist.c \
			vertlist_add.c \
			parser.c \
			rect_init.c \
			indexlist.c \
			indexlist_add.c \
			trilist.c \
			trilist_add.c \
			cube_init.c \
			init.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

LIBFT	= ./libft/libft.a
LIBINC	= -I./libft/includes
LIBLINK	= -L./libft -lft

SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./objs/
BINDIR	= ./
X11INC	=

OS		:= $(shell uname)
D_OS	=

ifeq ($(OS), Windows_NT)
	D_OS := Windows
else
	D_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(D_OS), Darwin)
	X11INC = -I/opt/X11/include
	X11LINK = -L/opt/X11/lib -lX11 -lXext -lm
endif

ifeq ($(D_OS), Linux)
	BINDIR = ./bin/
	X11LINK = -L/usr/lib/x86_64-linux-gnu -lX11 -lXext -lm
endif

all: obj bin libft $(NAME)

obj:
	@mkdir -p $(OBJDIR)

bin:
	@mkdir -p $(BINDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@echo $(NAME): Compiling $@
	@$(CC) $(CFLAGS) $(X11INC) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	@echo $(NAME): Compiling libft
	@make --no-print-directory -C ./libft

$(NAME): $(OBJ)
	@echo $(NAME): Compiling $(NAME)
	@$(CC) -o $(BINDIR)$(NAME) $(OBJ) $(LIBLINK) $(X11LINK)

clean:
	@rm -rf $(OBJDIR)
	@make --no-print-directory -C ./libft clean

fclean:
	@rm -rf $(OBJDIR)
	@rm -rf $(NAME)
	@make --no-print-directory -C ./libft fclean

re: fclean all
