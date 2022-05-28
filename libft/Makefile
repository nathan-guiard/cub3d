# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 03:13:28 by nguiard           #+#    #+#              #
#    Updated: 2022/05/05 13:13:29 by nguiard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  srcs/ft_isalpha.c 		\
	srcs/ft_itoa.c				\
	srcs/ft_calloc.c			\
	srcs/ft_putendl_fd.c		\
	srcs/ft_putchar_fd.c		\
	srcs/ft_putnbr_fd.c			\
	srcs/ft_putstr_fd.c			\
	srcs/ft_isascii.c			\
	srcs/ft_atoi.c				\
	srcs/ft_strmapi.c			\
	srcs/ft_striteri.c			\
	srcs/ft_isalnum.c			\
	srcs/ft_strlen.c			\
	srcs/ft_strjoin.c			\
	srcs/ft_strncmp.c			\
	srcs/ft_strdup.c			\
	srcs/ft_toupper.c			\
	srcs/ft_tolower.c			\
	srcs/ft_strrchr.c			\
	srcs/ft_strchr.c			\
	srcs/ft_substr.c			\
	srcs/ft_strnstr.c			\
	srcs/ft_strlcat.c			\
	srcs/ft_memset.c			\
	srcs/ft_isdigit.c			\
	srcs/ft_split.c				\
	srcs/ft_isprint.c			\
	srcs/ft_strlcpy.c			\
	srcs/ft_bzero.c				\
	srcs/ft_memcpy.c			\
	srcs/ft_memmove.c			\
	srcs/ft_memchr.c			\
	srcs/ft_strtrim.c			\
	srcs/ft_memcmp.c			\
	srcs/ft_lstnew.c			\
	srcs/ft_lstadd_front.c		\
	srcs/ft_lstsize.c			\
	srcs/ft_lstlast.c			\
	srcs/ft_lstadd_back.c		\
	srcs/ft_lstdelone.c			\
	srcs/ft_lstclear.c			\
	srcs/ft_lstiter.c			\
	srcs/ft_lstmap.c			\
	srcs/ft_lstpop.c			\
	srcs/get_next_line.c		\
	srcs/get_next_line_utils.c	\
	srcs/ft_printf.c			\
	srcs/count_putchar.c		\
	srcs/count_puthex_maj.c		\
	srcs/count_puthex_min.c		\
	srcs/count_putnbr.c			\
	srcs/count_putprct.c		\
	srcs/count_putptr.c			\
	srcs/count_putstr.c			\
	srcs/count_putbin.c			\
	srcs/count_putlong.c		\
	srcs/count_putunsigned.c	\
	srcs/parsing_printf.c		\
	srcs/set_layout.c			\
	srcs/set_layout_printf.c	\
	srcs/loading_bar.c			\
	srcs/get_whole_file.c		\
	srcs/ft_xtoi.c				\
	srcs/ft_strcmp.c			\
	srcs/ft_strrm_index.c		\
	srcs/ft_abs.c				\
	srcs/ft_free.c				\
	srcs/join.c					\

CFLAGS = -Wall -Werror -Wextra -Iinclude

OBJ = ${SRC:.c=.o}

NAME = libft.a

CC = gcc

nb:=1

n:=0

a:=0

all: ${NAME}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	$(eval n=$(shell echo $$(($(nb)/15 * 35))))
	$(eval a=$(shell echo $$((202 - $(n)))))
	@printf "\033[0;38;5;%dm" "${a}"
	@echo -n "\rCompilation de l'objet" ${nb} "terminee\033[0m"
	$(eval nb=$(shell echo $$(($(nb)+1))))

${NAME}: ${OBJ}
	@echo "\033[1;38;5;10m\nCompilation de libft.a\033[0m            "
	@ar rc ${NAME} ${OBJ}
	@ranlib ${NAME}
	@echo "\033[1;38;5;2mCompilation terminee 👍\033[0m"

clean:
	@rm -f ${OBJ}
	@echo "clean termine!"

fclean:
	@rm -f ${OBJ} ${NAME}
	@echo "fclean termine!"

re: fclean all

.PHONY: all clean fclean re