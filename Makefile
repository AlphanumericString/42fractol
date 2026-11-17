# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 09:04:05 by bgoulard          #+#    #+#              #
#    Updated: 2024/05/17 12:01:54 by bgoulard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GRAY		= "\\e[90m"
GREEN		= "\\e[42m"
RED			= "\\e[41m"
RESET		= "\\e[0m"
BOLD		= "\\e[1m"

PRINTF		=	$(shell which printf)
CC			=	clang
ECHO		=	$(shell which echo) -e

NAME		=	./fractol
SRC_DIR		=	src
BUILD_DIR	=	build
INC_DIR		=	include

DEBUG_LEVEL	=	2
DEBUG		=	-DDEBUG_LVL=$(DEBUG_LEVEL) -g2 
STD			=       --std=c99
CPPFLAGS	=\
				-I$(INC_DIR) -I./libs/ft/include -I./libs/mlx/
WFLAGS		=\
				-Wall -Wextra -Wno-unused-parameter				\
				-Werror											\
				-Wno-unused-variable -Wno-unused-function		\
				-Wno-unused-value								\
				-Wno-unused-label -Wno-unused-local-typedefs	\
				-Wno-unused-const-variable -Wno-unused-macros

FFLAGS	   =\
			-fsanitize=address			\
			-fno-omit-frame-pointer		\
			-fsanitize=undefined		\
			-fsanitize=leak				\
			-fsanitize=pointer-subtract	\
			-fsanitize=pointer-compare	\
			-fsanitize=pointer-overflow	\

CFLAGS	   =\
			$(WFLAGS) $(CPPFLAGS) $(STD)	\
			-MMD -MP -Werror -O2

LDFLAGS		=\
			-L./libs/ft -lft_personal -lm -lmlx_Linux -L./libs/mlx -lX11	\
			-lXext

SRC_FILES	=\
			$(SRC_DIR)/checks.c			\
			$(SRC_DIR)/context.c		\
			$(SRC_DIR)/display_opt.c	\
			$(SRC_DIR)/draw_fern.c		\
			$(SRC_DIR)/fract_ol_main.c	\
			$(SRC_DIR)/ft_atof.c		\
			$(SRC_DIR)/ft_complex.c		\
			$(SRC_DIR)/ft_intrange.c	\
			$(SRC_DIR)/ft_mlx.c			\
			$(SRC_DIR)/ft_put_pixel.c	\
			$(SRC_DIR)/ft_strisnum.c	\
			$(SRC_DIR)/ft_clamp.c		\
			$(SRC_DIR)/hooks_keys.c		\
			$(SRC_DIR)/loop_hooks.c		\
			$(SRC_DIR)/main.c			\
			$(SRC_DIR)/options.c		\
			$(SRC_DIR)/other_hooks.c	\
			$(SRC_DIR)/pixel_fractals.c	\
			$(SRC_DIR)/set_kbs.c		\

OBJ			=	$(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/,$(SRC_FILES)))

MAX_FLEN	=\
			 $(shell $(PRINTF) "%s\n" $(OBJ) | \
			 awk '{print length}' | sort -n | tail -1)

CLOG_FILE	=	./compilation.log

$(BUILD_DIR)/%.o: %.c
	@$(ECHO) -n	$(GRAY)	"building from " 
	@$(PRINTF) "%*s ..."$(RESET) $(MAX_FLEN) $<
	@mkdir -p $(dir $@)
	@( $(CC) $(CFLAGS) -c $< -o $@ 2>> $(CLOG_FILE) && \
	$(ECHO) $(GREEN) "Success" $(RESET) ) || \
	$(ECHO) $(RED) "Failed" $(RESET) "see:" $(CLOG_FILE)

all:	$(NAME)

libs/ft/libft_personal.a:
	@make -C ./libs/ft
libs/mlx/libmlx.a:
	@make -C ./libs/mlx

$(NAME):	$(OBJ) libs/ft/libft_personal.a	libs/mlx/libmlx.a
	@$(ECHO) -n $(GRAY) "Making ... " $(RESET) $(BOLD) "$(NAME)" \
	$(RESET)	$(GRAY) " ... " $(RESET)
	@( $(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS) 2>> $(CLOG_FILE) && \
	$(ECHO) $(GREEN) "Success" $(RESET) && $(RM) $(CLOG_FILE)) || \
	$(ECHO) $(RED) "Failed" $(RESET) "see:" $(CLOG_FILE)

debug:
	@make -C ./ re CFLAGS="$(CFLAGS) $(DEBUG)"

clean:
	@$(ECHO) -n $(GRAY) "Clean ... " $(RESET)
	@( $(RM) -rf $(BUILD_DIR) $(CLOG_FILE) 2> /dev/null && \
	make -C ./libs/ft clean	2> /dev/null &&		\
	make -C ./libs/mlx clean 2> /dev/null && 	\
	$(ECHO) $(GREEN) "Success" $(RESET) ) || \
	$(ECHO) $(RED) "Failed" $(RESET)

fclean: clean
	@$(ECHO) -n $(GRAY) "FClean ... " $(RESET)
	@( $(RM) $(NAME) 2> /dev/null && \
	make -C ./libs/ft fclean 2> /dev/null &&	\
	$(ECHO) $(GREEN) "Success" $(RESET) ) || \
	$(ECHO) $(RED) "Failed" $(RESET)

-include $(OBJ:.o=.d)

re:	fclean all

.PHONY: re fclean clean
