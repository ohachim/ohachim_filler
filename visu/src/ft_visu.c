/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 23:44:19 by ohachim           #+#    #+#             */
/*   Updated: 2019/12/28 11:11:22 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

static int	ft_init_datav(t_data *data, t_sdl *vis)
{
	char	*line;

	data->board = NULL;
	data->token = NULL;
	vis->o_vs_x = NULL;
	vis->score = NULL;
	vis->font = NULL;
	vis->solidp = NULL;
	if (!(line = ft_strnew(1)))
		return (0);
	while (line[0] != '$')
		if (!(ft_skip_line(&line, 0)) || line[0] == 'e')
			return (0);
	if (!(ft_get_players(vis, &line)))
		return (0);
	while (line[0] != 'P')
		if (!(ft_skip_line(&line, 0)) || line[0] == 'e')
			return (0);
	if (!(ft_make_board(data, &line, 0, 0)) || !(ft_make_token(data, &line, 0)))
	{
		ft_strdel(&line);
		return (0);
	}
	ft_strdel(&line);
	return (1);
}

static void	ft_init_vis(t_sdl *vis, t_data data)
{
	vis->window = NULL;
	vis->renderer = NULL;
	vis->speed = 150;
	vis->quit = 0;
	vis->message = NULL;
	vis->tmessage = NULL;
	if (data.xboard == 100)
	{
		vis->board.startx = 200;
		vis->board.starty = 5;
		vis->board.steps = 10;
	}
	if (data.xboard == 15)
	{
		vis->board.startx = 335;
		vis->board.starty = 16;
		vis->board.steps = 57;
	}
	if (data.xboard == 24)
	{
		vis->board.startx = 600;
		vis->board.starty = 20;
		vis->board.steps = 24;
	}
}

static int	ft_free_data(char **line, t_data *data)
{
	int		x;

	x = 0;
	if (!(*line = ft_strnew(1)))
		return (-5);
	while (line[0][0] != 'P' || line[0][1] != 'l')
		if (!ft_skip_line(line, 0))
			return (0);
	ft_strdel_imp(&data->board);
	ft_strdel_imp(&data->token);
	if (!(ft_make_board(data, line, 1, 0)) || !(ft_make_token(data, line, 0)))
	{
		ft_strdel(line);
		return (-5);
	}
	ft_strdel(line);
	return (1);
}

static int	ft_main_loop(t_sdl *vis, t_data *data, int test, int pause)
{
	char	*line;
	int		x;

	x = 0;
	if (!(line = ft_strnew(1)))
		return (0);
	while (!vis->quit)
	{
		while (SDL_PollEvent(&(vis->e)) != 0)
			ft_get_event(vis, &pause);
		if (pause == 0)
		{
			if (!(ft_visualization(vis, data)))
				return (0);
			if (test == 0 && !(x = ft_free_data(&line, data)))
				test = 1;
			if (x == -5)
			{
				ft_strdel(&line);
				return (0);
			}
		}
	}
	ft_strdel(&line);
	return (1);
}

int			main(int argc, char **argv)
{
	t_sdl		vis;
	t_data		data;

	(void)argv;
	(void)argc;
	if (!(ft_init_datav(&data, &vis)))
		return (ft_free_datav(&data, &vis));
	ft_init_vis(&vis, data);
	if (!(ft_init_sdlri(&(vis.window), &(vis.renderer),
		"ohachim_vis")) || TTF_Init() == -1)
	{
		ft_sdlclose_ws(&(vis.message), &(vis.window), &(vis.renderer)
						, &(vis.tmessage));
		return (ft_free_datav(&data, &vis));
	}
	if (!(vis.font = TTF_OpenFont("media/orange.ttf"
								, 200)))
		return (ft_free_datav(&data, &vis));
	ft_main_loop(&vis, &data, 0, 0);
	ft_free_datav(&data, &vis);
	ft_sdlclose_ws(&(vis.message), &(vis.window)
					, &(vis.renderer), &(vis.tmessage));
	return (0);
}
