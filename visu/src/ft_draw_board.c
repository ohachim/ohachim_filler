/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 00:08:30 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/24 10:00:12 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

static void	ft_drawsquare(int dsx, int dsy, SDL_Renderer **renderer, int steps)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y++ < steps)
		SDL_RenderDrawPoint(*renderer, dsy++, dsx);
	while (x++ < steps)
		SDL_RenderDrawPoint(*renderer, dsy, dsx++);
	while (y-- > 0)
		SDL_RenderDrawPoint(*renderer, dsy--, dsx);
	while (x-- > 0)
		SDL_RenderDrawPoint(*renderer, dsy, dsx--);
}

static void	ft_colorsquare(int dsx, int dsy, SDL_Renderer **renderer, int steps)
{
	int		x;
	int		y;
	int		ddy;

	x = 0;
	y = 0;
	ddy = dsy;
	while (x < steps - 1)
	{
		dsy = ddy;
		y = 0;
		while (y < steps - 1)
		{
			SDL_RenderDrawPoint(*renderer, dsy, dsx);
			dsy++;
			y++;
		}
		dsx++;
		x++;
	}
}

static void	ft_checkndraw(int startx, int starty, t_sdl *visual, char c)
{
	SDL_SetRenderDrawColor(visual->renderer, 240, 239, 239, 0);
	ft_drawsquare(startx, starty
			, &visual->renderer, visual->board.steps);
	if (c == 'X' || c == 'x' || c == 'O' || c == 'o')
	{
		if (c == 'X')
			SDL_SetRenderDrawColor(visual->renderer, 255, 102, 102, 0);
		if (c == 'x')
			SDL_SetRenderDrawColor(visual->renderer, 255, 204, 204, 0);
		if (c == 'O')
			SDL_SetRenderDrawColor(visual->renderer, 102, 178, 255, 0);
		if (c == 'o')
			SDL_SetRenderDrawColor(visual->renderer, 204, 229, 255, 0);
		ft_colorsquare(startx + 1, starty + 1
				, &visual->renderer, visual->board.steps);
	}
}

void		ft_draw_board(t_sdl *visual, int x, int y, char **board)
{
	int		dx;
	int		dy;
	int		startx;
	int		starty;

	startx = visual->board.startx;
	dx = 0;
	while (dx < x)
	{
		dy = 0;
		starty = visual->board.starty;
		while (dy < y)
		{
			ft_checkndraw(startx, starty, visual, board[dx][dy]);
			dy++;
			starty += visual->board.steps;
		}
		startx += visual->board.steps;
		dx++;
	}
}
