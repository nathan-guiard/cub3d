# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 15:42:20 by nguiard           #+#    #+#              #
#    Updated: 2022/08/16 09:40:38 by nguiard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	$(addsuffix .c, 	\
		$(addprefix srcs/,	\
		main 				\
		check_errors		\
		list				\
		parse_utils			\
		check_els			\
		errors				\
		parse_map			\
		parse_map_utils		\
		parse_map_utils2	\
		fc_colors			\
		let_it_go			\
		launch_cub3d		\
		keys				\
		draw_mini_map		\
		bres				\
		raycasting			\
		player				\
		ray_utils			\
		project_wall		\
		cast_rays			\
		cast_cols			\
		minimap				\
		movements			\
		))

BONUSSRC =	$(addsuffix .c, \
		$(addprefix 		\
		bonus_srcs/,		\
		$(addprefix font/,  \
		a_to_e				\
		f_to_j				\
		k_to_o				\
		p_to_t				\
		u_to_w				\
		x_to_z				\
		one_to_four			\
		five_to_nine		\
		zero_dot_slash		\
		mlx_putstr			\
		)					\
		$(addprefix menu/,	\
		menu_bg_animation	\
		menu_bg_line		\
		menu_math			\
		menu_thread			\
		draw_first_menu		\
		draw_releif			\
		draw_menu_button	\
		start_handling		\
		menu_hooks			\
		)					\
		$(addprefix play/,	\
		draw_play			\
		play_handling		\
		map_list			\
		roulette			\
		exec_map			\
		)					\
		$(addprefix			\
		editor/,			\
		editor_handling		\
		draw_ask_name		\
		ask_name_handling	\
		init_editor			\
		draw_editor			\
		charmap_utils		\
		build_handling		\
		draw_player			\
		create_map_editor	\
		)					\
		draw_box			\
		main				\
		init_menu			\
		quit				\
		key					\
		my_pixel_put 		\
		straight_line		\
		get_elapsedtime		\
		utils				\
		)					\
		)

SHELL := /bin/zsh

OBJ		= ${SRC:srcs/%.c=obj/%.o}

BONUSOBJ = ${BONUSSRC:bonus_srcs/%.c=bonus_obj/%.o}

CC		= gcc

INCLUDE = -Iinclude/

CFLAGS	= -Wall -Werror -Wextra ${INCLUDE} -g #-fsanitize=address

NAME	= cub3d

BONUS	= cub_tron_d

LIBFT	= libft/libft.a

MLX		= mlx/libmlx_Linux.a

MAKE	= --silent --jobs

MY_MAKE	= make --silent --jobs

total	:= $(shell echo ${SRC} | wc -w)

totalbonus	:= $(shell echo ${BONUSSRC} | wc -w)

percent	:= 0

current	:= 1

save_percent ?= 0

len := $(shell echo ${NAME} | wc -c)

all:
	@${MY_MAKE} setup
	@${MY_MAKE} libft_rule
	@${MY_MAKE} mlx_rule
	@echo -ne "\033[10;3H\033[1;32mObjets deja compilés!\033[m";
	@make --silent ${OBJ}
	@echo -ne "\033[14;3H\033[1;32m${NAME} deja compilé!\033[m";
	@echo -ne "\033[16;H"
	@make --silent ${NAME}
	@${MY_MAKE} end_make

both:	all bonus

obj/%.o: srcs/%.c
	@printf "\033[10;2H                                                  \033[10;3H%s" $< ${<:.c=⠀⠀}
	@echo -ne "\033[16;H"
	@${CC} ${CFLAGS} -c $< -o ${<:srcs/%.c=obj/%.o}	
	@$(eval percent=$(shell expr ${current} "*" 100 / ${total}))
	@echo -ne "\033[11;3H"
	@printf "%d/%d:   \t\t%d%%" ${current} ${total} ${percent}
	$(call loading,${percent})
	@$(eval current=$(shell expr ${current} + 1))

bonus_obj/%.o: bonus_srcs/%.c
	@printf "\033[10;2H                                                  \033[10;3H%s" $< ${<:.c=⠀⠀}
	@echo -ne "\033[16;H"
	@${CC} ${CFLAGS} -c $< -o ${<:bonus_srcs/%.c=bonus_obj/%.o}	
	@$(eval percent=$(shell expr ${current} "*" 100 / ${totalbonus}))
	@echo -ne "\033[11;3H"
	@printf "%d/%d:   \t\t%d%%" ${current} ${totalbonus} ${percent}
	$(call loading,${percent})
	@$(eval current=$(shell expr ${current} + 1))

${NAME}: ${OBJ}
	@${CC} ${OBJ} ${CFLAGS} ${LIBFT} ${MLX} -lXext -lX11 -lm -o ${NAME};
	@printf "\033[14;3H\033[1mCompilation de ${NAME} \033[32mterminee\033[1;37m!";
	@${MY_MAKE} end_make

bonus: Makefile
	@${MY_MAKE} setup
	@${MY_MAKE} libft_rule
	@${MY_MAKE} mlx_rule
	@echo -ne "\033[10;3H\033[1;32mObjets deja compilés!\033[m";
	@make --silent ${BONUSOBJ}
	@echo -ne "\033[14;3H\033[1;32m${BONUS} deja compilé!\033[m";
	@echo -ne "\033[16;H"
	@make --silent ${BONUS}
	@${MY_MAKE} end_make

${BONUS}: ${BONUSOBJ}
	@${CC} ${BONUSOBJ} ${CFLAGS} ${LIBFT} ${MLX} -lXext -lX11 -lm -lpthread -o ${BONUS};
	@printf "\033[14;3H\033[1mCompilation de ${BONUS} \033[32mterminee\033[1;37m!";
	@${MY_MAKE} end_make

libft_rule:
	@if [[ -f ${LIBFT} ]] ;	\
			then;	\
				echo -ne "\033[4;3H\033[1;32mLibft deja compilée!\033[m";	\
			else; \
				echo -ne "\033[4;3HCompilation de la libft: \033[33mEn cours...\033[m"; \
				${MY_MAKE} -C libft >/dev/null; \
				if [[ $$? -eq 0 ]] ; \
				then; \
					echo "\033[11D\033[1;32mOK!        \033[m"; \
			fi; \
		fi;

mlx_rule:
	@if [[ -f ${MLX} ]] ;	\
			then;	\
				echo -ne "\033[7;3H\033[1;32mMlx deja compilée!\033[m";	\
			else; \
				echo -ne "\033[7;3HCompilation de la Mlx: \033[33mEn cours...\033[m"; \
				${MY_MAKE} -C mlx >/dev/null 2>/dev/null; \
				if [[ $$? -eq 0 ]] ; \
				then; \
					echo "\033[11D\033[1;32mOK!        \033[m"; \
			fi; \
		fi;

setup:
	@echo -ne "\033[0;0H\033[J\033[?25l"
	@echo -ne "\033[1;38;5;57m"
	@echo "╔══════════════════════════════════════════════════╗"
	@echo "╟────────────────┤ \033[3mTURBO MAKEFILE ├────────────────╢"
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
	@rm -rf ${NAME} ${BONUS} ${OBJ} ${BONUSOBJ}

clean:
	@rm -rf ${OBJ} ${BONUSOBJ}

.PHONY: clean fclean re end_make all setup libft_rule bonus
