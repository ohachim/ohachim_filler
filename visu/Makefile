# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 02:54:22 by ohachim           #+#    #+#              #
#    Updated: 2020/02/17 22:45:02 by ohachim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src

SRC_NAME = ft_sdlclose_ws.c \
	   ft_init_sdlri.c \
	   ft_draw_board.c \
	   ft_get_players.c \
	   ft_get_event.c \
	   ft_get_ox.c \
	   ft_get_scores.c \
	   ft_visu_score.c \
	   ft_visu.c \
	   ft_skip_line.c \
	   ft_make_board.c \
	   ft_make_token.c \
	   ft_strdel_imp.c \
	   ft_dsculpt_token.c \
	   ft_free_datav.c \
	   ft_visualization.c

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

LDFLIBS = -L sdl2/2.0.10/lib -lSDL2-2.0.0 -lSDL2 \
	  -L sdl2_image/2.0.5/lib -lSDL2_image \
	  -lSDL2_image-2.0.0 \
	  -L sdl2_ttf/2.0.15/lib -lSDL2_ttf \
	  -lSDL2_ttf-2.0.0 \
	  -L libft -lft


CPPFLAGS = -I sdl2_image/2.0.5/include/SDL2 \
	   -I sdl2/2.0.10/include/SDL2 \
	   -I sdl2_ttf/2.0.15/include/SDL2 \
	   -I include \
	   -I libft/include \

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = visu_filler

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft ; make
	$(CC) $(LDFLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@make -C libft clean
	@rm -vf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make -C libft fclean
	@rm -vf $(NAME)

re: fclean all
