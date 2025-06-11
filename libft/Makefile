# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 19:45:19 by jfernand          #+#    #+#              #
#    Updated: 2025/04/26 10:35:18 by jfernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the project
NAME=libft.a

# Object files
CFILES= ./ft_atoi.c        \
        ./ft_bzero.c      \
		./ft_calloc.c      \
		./ft_isalnum.c     \
		./ft_isalpha.c     \
		./ft_isascii.c     \
		./ft_isdigit.c     \
		./ft_isprint.c     \
		./ft_itoa.c        \
		./ft_memchr.c      \
		./ft_memcmp.c      \
		./ft_memcpy.c      \
		./ft_memmove.c     \
		./ft_memset.c      \
		./ft_putchar_fd.c  \
		./ft_putendl_fd.c  \
		./ft_putnbr_fd.c   \
		./ft_putstr_fd.c   \
		./ft_split.c       \
		./ft_strchr.c      \
		./ft_strdup.c      \
		./ft_striteri.c    \
		./ft_strjoin.c     \
		./ft_strlcat.c     \
		./ft_strlcpy.c     \
		./ft_strlen.c      \
		./ft_strmapi.c     \
		./ft_strncmp.c     \
		./ft_strnstr.c     \
		./ft_strrchr.c     \
		./ft_strtrim.c     \
		./ft_substr.c      \
		./ft_tolower.c     \
		./ft_toupper.c     \
		./ft_printf/ft_printf.c         \
		./ft_printf/ft_print_char.c     \
		./ft_printf/ft_print_str.c      \
		./ft_printf/ft_print_int.c      \
		./ft_printf/ft_print_unsigned.c \
		./ft_printf/ft_print_pointer.c  \
		./ft_printf/ft_print_hex.c      \
		./get_next_line/get_next_line_bonus.c       \
		./get_next_line/get_next_line_utils_bonus.c \
		./ft_lstadd_back_bonus.c  \
        ./ft_lstadd_front_bonus.c \
		./ft_lstclear_bonus.c     \
		./ft_lstdelone_bonus.c    \
		./ft_lstiter_bonus.c      \
		./ft_lstnew_bonus.c       \
		./ft_lstsize_bonus.c      \
		./ft_lstlast_bonus.c      \
		./ft_lstmap_bonus.c       \
		

# .h files
HFILES= ./libft.h \
		./ft_printf/ft_printf.h \
		./get_next_line/get_next_line_bonus.h \

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

$(OFILES):%.o:%.c
	@ echo 'Building target: $@'
	@ $(CC) $(CCFLAGS) -c $< -o $@

clean:
	@ $(RM) $(OFILES) $(BOFILES)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

.PHONY= all clean fclean re bonus




