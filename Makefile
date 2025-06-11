# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 19:45:19 by jfernand          #+#    #+#              #
#    Updated: 2025/05/16 18:46:06 by jfernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the project
NAME= so_long

# Object files
CFILES= ./so_long.c

# .h files
HFILES= ./so_long.h \

# Libft files
LIBFT= ./libft
LIBFT_A= $(LIBFT)/libft.a

# Minilibx files
MINILIBX= ./minilibx-linux
MINILIBX_A= $(MINILIBX)/libmlx_Linux.a

# .c bonus files
#BFILES= 

# Object files
OFILES= $(CFILES:.c=.o)

# Bonus object files
BOFILES= $(BFILES:.c=.o)

# Compiler
CC=@cc

# Flags for compiler
CCFLAGS=-Wall      \
        -Wextra    \
        -Werror    \
		-g         \
		-I.        \
		-I$(MINILIBX) \

RFLAGS= -lm \
		-lX11 \
		-lXext \

# Command used to clean target
RM = rm -rf

#
# Compilation and linking
#
all: $(NAME)

$(NAME): $(LIBFT_A) $(MINILIBX_A) $(OFILES) 
	@ echo 'Building binary: $@'
	$(CC) $(CCFLAGS) $(OFILES) $(LIBFT_A) $(MINILIBX_A) $(RFLAGS) -o $@
	@ echo 'Finished building binary: $@'

$(OFILES): %.o:%.c
	@ echo 'Building target: $@'
	@ $(CC) $(CCFLAGS) -c $< -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

$(MINILIBX_A):
	$(MAKE) -C $(MINILIBX)

clean:
	@ $(RM) $(OFILES)
	@ $(MAKE) -C $(LIBFT) clean

fclean: clean
	@ $(RM) $(NAME)
	@ $(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY= all clean fclean re 




