/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 14:59:23 by ohachim           #+#    #+#             */
/*   Updated: 2019/08/04 14:59:31 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillerh.h"

static int	ft_init_position(t_data *data, char **board)
{
	int		checks;

	checks = 0;
	while (data->xstart < data->xboard)
	{
		data->ystart = 0;
		while (data->ystart < data->yboard)
		{
			if (board[data->xstart][data->ystart] != '.')
			{
				data->p = ((board[data->xstart][data->ystart] == data->put \
							&& !checks) ? 'u' : 'l');
				checks = 1;
				if (board[data->xstart][data->ystart] == data->put)
					return (0);
			}
			data->ystart++;
		}
		data->xstart++;
	}
	return (-1);
}

static int	ft_make_heatint(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	if (!(data->heatint = (int**)malloc(sizeof(int*) * data->xboard)))
		return (0);
	while (y < data->xboard)
	{
		if (!(data->heatint[y++] = (int*)malloc(sizeof(int) * data->yboard)))
			return (0);
	}
	while (x < data->xboard)
	{
		y = 0;
		while (y < data->yboard)
		{
			data->heatint[x][y] = data->board[x][y];
			y++;
		}
		x++;
	}
	return (1);
}

static int	ft_init_data(t_data *data)
{
	char	*line;
	int		x;

	x = 0;
	data->xstart = 0;
	data->xskulpt = 0;
	data->yskulpt = 0;
	data->board = NULL;
	data->heatint = NULL;
	data->token = NULL;
	if (!(line = ft_strnew(1)))
		return (0);
	while (line[0] != '$')
		if (!(ft_skip_line(&line, 0)))
			return (0);
	ft_player_put(data, &line);
	while (line[0] != 'P')
		if (!(ft_skip_line(&line, 0)))
			return (0);
	if (!(ft_make_board(data, &line, 0, 0)) ||
			!(ft_make_token(data, &line, 0)) || !(ft_make_heatint(data)))
		return (0);
	ft_strdel(&line);
	ft_init_position(data, data->board);
	return (1);
}

static int	ft_free_data(char **line, t_data *data)
{
	int		x;

	x = 0;
	if (!(*line = ft_strnew(1)))
		return (0);
	ft_strdel_imp(&data->board);
	ft_strdel_imp(&data->token);
	while (x < data->xboard)
		ft_memdel((void**)&data->heatint[x++]);
	free(data->heatint);
	data->heatint = 0;
	if (!(ft_skip_line(line, 0)))
		return (0);
	if (!(ft_make_board(data, line, 1, 0)) ||
			!(ft_make_token(data, line, 0)) || !(ft_make_heatint(data)))
		return (0);
	ft_strdel(line);
	return (1);
}

int			main(void)
{
	t_data	data;
	char	*line;
	int		x;
	int		stop;

	stop = 1;
	x = 0;
	if (!(ft_init_data(&data)))
		return (ft_out_data(&data));
	while (stop)
	{
		data.xskulpt = 0;
		data.yskulpt = 0;
		if (x)
			if (!(ft_free_data(&line, &data)))
				return (ft_out_data(&data));
		while (!(ft_strchr(data.token[data.xskulpt], '*')))
			data.xskulpt++;
		ft_heatmap(&data);
		data.yskulpt = ft_sculpt_y(&data);
		ft_play(data);
		x++;
	}
	return (0);
}
