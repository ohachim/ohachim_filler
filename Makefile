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

INCS = ft_player_put.c \
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
		ft_brute_forcel.c
OBJ = ft_player_put.o \
		ft_make_board.o \
		ft_skip_line.o \
		ft_make_token.o \
		ft_play.o \
		ft_strdel_imp.o \
		ft_dsculpt_token.o \
		ft_sculpt_y.o \
		ft_valid_holder.o \
		ft_brute_force.o \
		ft_heatmap.o \
		ft_brute_forceu.o \
		ft_brute_forcel.o
FLAGS = -Wall -Werror -Wextra
LNAME = libfit.a
NAME = ohachim.filler
all: $(NAME)
$(NAME):
	@make -C libft
	@gcc -c $(FLAGS) $(INCS)
	@ar rc $(LNAME) $(OBJ)
	@ranlib $(LNAME)
	@gcc $(FLAGS) ft_filler.c $(LNAME) -o $(NAME) -L libft -lft
clean :
	@rm -f $(OBJ) $(LNAME)
	@make -C libft clean
fclean : clean
	@rm -f $(NAME)
	@make -C libft fclean
re : fclean all
	@make -C libft re
