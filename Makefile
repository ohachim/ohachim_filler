# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 02:54:22 by ohachim           #+#    #+#              #
#    Updated: 2019/07/27 18:21:12 by ohachim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src

SRC_NAME = ft_player_put.c \
		ft_make_board.c \
		ft_skip_line.c \
		ft_make_token.c \
		ft_play.c \
		ft_strdel_imp.c \
		ft_dsculpt_token.c \
		ft_sculpt_y.c \
		ft_valid_holder.c \
		ft_brute_force.c \
		ft_heatmap.c \
		ft_brute_forceu.c \
		ft_brute_forcel.c \
		ft_filler.c \
		ft_out_data.c \
		ft_bad_char.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CPPFLAGS =-Iinclude -Ilibft/include

LDFLAGS = -Llibft

LDLIBS = -lft

NAME = ohachim.filler

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

all: $(NAME)

visua:
	@make -C visu

visuc:
	@cd visu ; make clean

visufc:
	@cd visu ; make fclean

visur:
	@cd visu ; make re

both: all visua

bothc: clean visuc

bothfc: fclean visufc

bothr: re visur

$(NAME): $(OBJ)
	@cd libft ; make
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

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
