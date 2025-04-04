# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: akasiota <akasiota@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/08 20:26:47 by akasiota      #+#    #+#                  #
#    Updated: 2025/04/04 17:01:56 by akasiota      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := gcc
AR := ar
HDRFILES := libft.h \
			get_next_line.h \
			ft_printf.h
CFLAGS := -Wall -Wextra -Werror -I./
LFLAGS := -crs
# OBJDIR := ./obj_dir
SRCFILES := ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_split.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_printf.c \
			print_type.c \
			ft_printf_putchar.c \
			ft_printf_putstr.c \
			ft_printf_putptr.c \
			ft_printf_putint.c \
			ft_printf_putuns.c \
			ft_printf_puthex_low.c \
			ft_printf_puthex_upp.c \
			ft_printf_putpercent.c \

OBJFILES := $(SRCFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJFILES)
	$(AR) $(LFLAGS) $@ $? && printf "Building $(notdir $@)\n"

# $(OBJDIR):
# 	mkdir obj_dir

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $? && printf "Compiling $(notdir $<)\n"

clean:
	rm -f $(OBJFILES) $(BONOBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus all