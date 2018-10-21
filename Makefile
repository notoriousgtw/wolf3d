# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwood <gwood@42.us.org>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/30 14:30:20 by mhurd             #+#    #+#              #
#    Updated: 2018/10/20 23:23:19 by gwood            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= wolf3d

SRC		= main.c \
			vec2d.c \
			mat2d.c \
			mat2d_tr.c \
			drawline2d.c \
			vec3d.c \
			mat3d.c \
			mat3d_tr.c \
			drawline3d.c \
			vertlist.c \
			vertlist_add.c \
			linelist.c \
			linelist_add.c


OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

LIBFT	= ./libft/libft.a
LIBINC	= -I./libft/includes
LIBLINK	= -L./libft -lft

X11LINK = -L/usr/lib/x86_64-linux-gnu -lX11 -lXext -lm

SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./objs/
BINDIR	= ./bin/

all: obj libft $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@echo $(NAME): Compiling $@
	@$(CC) $(CFLAGS) -I $(INCDIR) $(LIBINC) -o $@ -c $<

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
