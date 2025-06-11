# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 19:45:19 by jfernand          #+#    #+#              #
#    Updated: 2025/04/19 08:35:46 by jfernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the project
NAME=libftprintf.a

# Object files
CFILES= ./ft_printf.c         \
		./ft_print_char.c     \
		./ft_print_hex.c      \
		./ft_print_int.c      \
		./ft_print_pointer.c  \
		./ft_print_str.c      \
		./ft_print_unsigned.c \

# .h files
HFILES= ./libft.h

# .c bonus files
BFILES= 

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

# Command used to archive target
AR= @ar -rcs

# Command used to clean target
RM = rm -rf

#
# Compilation and linking
#
all: $(NAME)

$(NAME): $(OFILES) 
	@ echo 'Building binary: $@'
	$(AR) $@ $^
	@ echo 'Finished building binary: $@'

#bonus: $(OFILES) $(BOFILES)
#	@ echo 'Building Bonus binary: $(NAME)'
#	$(AR) $(NAME) $(OFILES) $(BOFILES)
#	@ echo 'Finished building Bonus binary: $(NAME)'

$(OFILES): %.o:%.c
	@ echo 'Building target: $@'
	@ $(CC) $(CCFLAGS) -c $< -o $@

clean:
	@ $(RM) $(OFILES) $(BOFILES)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

.PHONY= all clean fclean re bonus




