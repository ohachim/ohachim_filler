# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 02:54:22 by ohachim           #+#    #+#              #
#    Updated: 2019/07/25 17:26:35 by ohachim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = sdl2lib/ft_sdlclose_ws.c \
		sdl2lib/ft_init_sdlri.c \
		sdl2lib/ft_draw_board.c \
		sdl2lib/ft_get_players.c \
		sdl2lib/ft_get_event.c \
		sdl2lib/ft_get_ox.c \
		sdl2lib/ft_get_scores.c \
		sdl2lib/ft_visu_score.c
OBJ = ft_sdlclose_ws.o \
	  ft_init_sdlri.o \
	  ft_draw_board.o \
	  ft_get_players.o \
	  ft_get_event.o \
	  ft_get_ox.o \
	  ft_get_scores.o \
	  ft_visu_score.o
LIB = -L /Users/ohachim/.brew/Cellar/sdl2/2.0.9_1/lib -lSDL2-2.0.0 -lSDL2 \
		-L /Users/ohachim/.brew/Cellar/sdl2_image/2.0.5/lib -lSDL2_image \
		-lSDL2_image-2.0.0 \
		-L lib -lft -lfit \
		-L /Users/ohachim/.brew/Cellar/sdl2_ttf/2.0.15/lib -lSDL2_ttf \
	   	-lSDL2_ttf-2.0.0
INC = -I/Users/ohachim/.brew/Cellar/sdl2_image/2.0.5/include/SDL2 \
	  -I/Users/ohachim/.brew/Cellar/sdl2/2.0.9_1/include/SDL2 \
	  -I/Users/ohachim/.brew/Cellar/sdl2_ttf/2.0.15/include/SDL2
FLAGS = -Wall -Werror -Wextra
LNAME = libsd.a
NAME = visu_filler
all: $(NAME)
$(NAME):
	@gcc -c $(FLAGS) $(SRC) $(INC)
	@ar rc $(LNAME) $(OBJ)
	@ranlib $(LNAME)
	@gcc $(FLAGS) game.c $(LNAME) -o $(NAME) $(LIB) $(INC)
clean :
	@rm -f $(OBJ) $(LNAME)
fclean : clean
	@rm -f $(NAME)
re : fclean all
