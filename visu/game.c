/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 23:44:19 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/25 17:19:14 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillerh.h"
#include "visuh.h"

static void	ft_init_datav(t_data *data, t_sdl *visual)
{
	char	*line;

	line = ft_strnew(1);
	while (line[0] != '$')
		ft_skip_line(&line, 0);
	ft_get_players(visual, &line);
	while (line[0] != 'P')
		ft_skip_line(&line, 0);
	ft_make_board(data, &line, 0);
	ft_make_token(data, &line, 0);
	free(line);
}

static void	ft_init_visu(t_sdl *visual, t_data data)
{
	visual->window = NULL;
	visual->renderer = NULL;
	visual->speed = 150;
	visual->quit = 0;
	visual->message = NULL;
	visual->tmessage = NULL;
	if (data.xboard == 100)
	{
		visual->board.startx = 200;
		visual->board.starty = 5;
		visual->board.steps = 10;
	}
	if (data.xboard == 15)
	{
		visual->board.startx = 335;
		visual->board.starty = 16;
		visual->board.steps = 57;
	}
	if (data.xboard == 24)
	{
		visual->board.startx = 600;
		visual->board.starty = 20;
		visual->board.steps = 24;
	}
}

static int	ft_free_data(char **line, t_data *data)
{
	int		x;

	x = 0;
	*line = ft_strnew(1);
	while (line[0][0] != 'P' || line[0][1] != 'l')
		if (!ft_skip_line(line, 0))
			return (0);
	ft_strdel_imp(&data->board);
	ft_strdel_imp(&data->token);
	ft_make_board(data, line, 1);
	ft_make_token(data, line, 0);
	free(*line);
	return (1);
}

static void	ft_main_loop(t_sdl *visu, t_data *data, int test, int pause)
{
	char	*line;

	line = ft_strnew(1);
	while (!visu->quit)
	{
		while (SDL_PollEvent(&(visu->e)) != 0)
			ft_get_event(visu, &pause);
		if (pause == 0)
		{
			SDL_SetRenderDrawColor(visu->renderer, 64, 64, 64, 0);
			SDL_RenderClear(visu->renderer);
			ft_visu_score(visu, data->board);
			ft_draw_board(visu, data->xboard, data->yboard, data->board);
			SDL_RenderPresent(visu->renderer);
			if (visu->speed > 0)
				SDL_Delay(visu->speed);
			if (test == 0 && !ft_free_data(&line, data))
				test = 1;
		}
	}
}

int			main(int argc, char **argv)
{
	t_sdl		visual;
	t_data		data;

	(void)argv;
	(void)argc;
	ft_init_datav(&data, &visual);
	ft_init_visu(&visual, data);
	ft_init_sdlri(&(visual.window), &(visual.renderer), "ohachim_visu");
	TTF_Init();
	if (!(visual.font = TTF_OpenFont("media/orange.ttf", 40)))
		ft_printf("Error Getting TTF-->[%s]\n", TTF_GetError());
	ft_main_loop(&visual, &data, 0, 0);
	ft_strdel_imp(&data.board);
	ft_strdel_imp(&data.token);
	SDL_DestroyTexture(visual.tmessage);
	ft_sdlclose_ws(&(visual.message), &(visual.window), &(visual.renderer));
	free(visual.o_vs_x);
	free(visual.score);
	return (0);
}
