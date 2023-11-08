##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Make library
##

CC=gcc

CFLAGS=-Werror -Wall -Wextra

C_FILES = my_strupcase.c \
 			my_getnbr.c \
 			my_str_islower.c \
 			my_str_to_word_array.c \
 			my_str_isnum.c \
 			my_strcpy.c \
 			my_put_nbr.c \
 			my_strcmp.c \
 			my_find_prime_sup.c \
 			my_isneg.c \
 			convert_base.c \
 			my_strlowcase.c \
 			my_show_word_array.c \
 			my_swap.c \
 			my_showstr.c \
 			my_compute_square_root.c \
 			my_strncmp.c \
 			my_str_isprintable.c \
 			my_showmem.c \
 			my_is_prime.c \
 			my_putstr.c \
 			my_strcat.c \
 			my_strncpy.c \
 			my_sort_int_array.c \
 			my_strdup.c \
 			my_strlen.c \
 			my_putchar.c \
 			my_strcapitalize.c \
 			my_getnbr_base.c \
 			my_strncat.c \
 			my_revstr.c \
 			my_strstr.c \
 			my_str_isalpha.c \
 			my_str_isupper.c \
 			my_putnbr_base.c \
 			my_compute_power_rec.c\
			my_memcmp.c \
			my_memset.c \
			my_strchr.c \
			my_strrchr.c \
			my_memcpy.c

O_FILES = $(C_FILES:.c=.o)

NAME=libmy.a

$(NAME): $(O_FILES)
	ar -rsc $(NAME) $(O_FILES)
	cp $(NAME) ../
	mkdir -p ../../include
	cp my.h ../../include

all: $(NAME)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
