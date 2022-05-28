# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 15:42:20 by nguiard           #+#    #+#              #
#    Updated: 2022/05/28 19:50:59 by nguiard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	srcs/main.c		\

SHELL := /bin/zsh

OBJ		= ${SRC:.c=.o}

CC		= gcc

INCLUDE = -Iinclude/

CFLAGS	= -Wall -Werror -Wextra ${INCLUDE}

NAME	= cub3d

LIBFT	= libft/libft.a

MLX		= mlx/libmlx_Linux.a

MAKE	= --silent --jobs

MY_MAKE	= make --silent --jobs

total	:= $(shell echo ${SRC} | wc -w)

percent	:= 0

current	:= 1

save_percent ?= 0

len := $(shell echo ${NAME} | wc -c)

all: ${NAME}

.c.o:
	@printf "\033[10;2H                                                  \033[10;3H%s" $< ${<:.c=⠀⠀}
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@$(eval percent=$(shell expr ${current} "*" 100 / ${total}))
	@echo -ne "\033[11;3H"
	@printf "%d/%d:   \t\t%d%%" ${current} ${total} ${percent}
	$(call loading,${percent})
	@$(eval current=$(shell expr ${current} + 1))

${NAME}: setup libft_rule mlx_rule ${OBJ}
	@if [[ -f ${NAME} ]] ;	\
	then;	\
		printf "\033[14;%dH\033[1;31m${NAME} existe deja!" "3";	\
	else;	\
		${CC} ${OBJ} ${CFLAGS} ${LIBFT} ${MLX} -lm -o ${NAME}; \
		printf "\033[14;%dH\033[1mCompilation de ${NAME} \033[32mterminee\033[1;37m!" "$(shell expr 15 - \( ${len} / 2 \))"; \
	fi
	@${MY_MAKE} end_make

libft_rule:
	@if [[ -f ${NAME} ]];\
	then;	\
		printf "\033[14;%dH\033[1;31m${NAME} existe deja!"	\
		"3";	\
	else; \
		if [[ -f ${LIBFT} ]] ;	\
			then;	\
				echo -ne "\033[4;3H\033[1;32m              Libft deja compilee!\033[m";	\
			else; \
				echo -ne "\033[4;3HCompilation de la libft: \033[33mEn cours...\033[m"; \
				${MY_MAKE} -C libft >/dev/null; \
				if [[ $$? -eq 0 ]] ; \
				then; \
					echo "\033[11D\033[1;32mOK!        \033[m"; \
			fi; \
		fi;	\
	fi;

mlx_rule:
	@if [[ -f ${NAME} ]];\
	then;	\
		printf "\033[14;%dH\033[1;31m${NAME} existe deja!"	\
		"3";	\
	else; \
		if [[ -f ${MLX} ]] ;	\
			then;	\
				echo -ne "\033[7;3H\033[1;32m              Mlx deja compilee!\033[m";	\
			else; \
				echo -ne "\033[7;3HCompilation de la Mlx: \033[33mEn cours...\033[m"; \
				${MY_MAKE} -C mlx >/dev/null 2>/dev/null; \
				if [[ $$? -eq 0 ]] ; \
				then; \
					echo "\033[11D\033[1;32mOK!        \033[m"; \
			fi; \
		fi;	\
	fi;	

setup:
	@echo -ne "\033[0;0H\033[J\033[?25l"
	@echo -ne "\033[1;38;5;57m"
	@echo "╔══════════════════════════════════════════════════╗"
	@echo "╟────────────────┤ \033[3mTRUBO MAKEFILE ├────────────────╢"
	@echo "║ Libft:                                           ║"
	@echo "║                                                  ║"
	@echo "║                                                  ║"
	@echo "║ MinilibX:                                        ║"
	@echo "║                                                  ║"
	@echo "║                                                  ║"
	@echo "║ Objets:                                          ║"
	@echo "║                                                  ║"
	@echo "║                                                  ║"
	@echo "║                                                  ║"
	@echo "║ Executable:                                      ║"
	@echo "║                                                  ║"
	@echo "╚══════════════════════════════════════════════════╝"
	@echo -ne "\033[m"

define loading
	@$(eval save_percent=$(shell expr ${percent}))
	@echo -ne "\033[12;13H"
	@save_percent=$(shell expr ${save_percent} "*" 2); \
	while (( $${save_percent} > 7)) ; do \
		echo -ne "\033[47;32m█"; \
		((save_percent-=7)); \
	done;	\
	echo "\u`printf '%x' $(expr 9608 + $$save_percent)`"		
	@echo -ne "\033[0m"
	@true
endef

end_make:
	echo -ne "\033[16;H\033[?25h"

re: fclean all

fclean:
	@make fclean -C libft 1>/dev/null
	@make clean -C mlx 1>/dev/null
	@rm -rf ${NAME} ${OBJ}

clean:
	@rm -rf ${OBJ}

.PHONY: clean fclean re end_make all setup libft_rule