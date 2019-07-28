/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:17:47 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/27 18:36:19 by ohachim          ###   ########.fr       */
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

static void	ft_make_heatint(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	if (!(data->heatint = (int**)malloc(sizeof(int*) * data->xboard)))
		return ;
	while (y < data->xboard)
	{
		if (!(data->heatint[y++] = (int*)malloc(sizeof(int) * data->yboard)))
			return ;
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
}

static void	ft_init_data(t_data *data)
{
	char	*line;
	int		x;

	x = 0;
	data->counter = 0;
	data->xstart = 0;
	data->xskulpt = 0;
	data->yskulpt = 0;
	line = ft_strnew(1);
	while (line[0] != '$')
		ft_skip_line(&line, 0);
	ft_player_put(data, &line);
	while (line[0] != 'P')
		ft_skip_line(&line, 0);
	ft_make_board(data, &line, 0);
	ft_make_token(data, &line, 0);
	ft_make_heatint(data);
	free(line);
	ft_init_position(data, data->board);
}

static void	ft_free_data(char **line, t_data *data, int *stop)
{
	int		x;

	x = 0;
	*line = ft_strnew(1);
	ft_strdel_imp(&data->board);
	ft_strdel_imp(&data->token);
	while (x < data->xboard)
		free(data->heatint[x++]);
	free(data->heatint);
	if (!(ft_skip_line(line, 0)))
	{
		*stop = 0;
		ft_printf("0 0\n");
	}
	ft_make_board(data, line, 1);
	ft_make_token(data, line, 0);
	ft_make_heatint(data);
	free(*line);
}

int			main(void)
{
	t_data	data;
	char	*line;
	int		x;
	int		stop;

	stop = 1;
	x = 0;
	ft_init_data(&data);
	while (stop)
	{
		data.xskulpt = 0;
		data.yskulpt = 0;
		if (x)
			ft_free_data(&line, &data, &stop);
		while (!(ft_strchr(data.token[data.xskulpt], '*')))
			data.xskulpt++;
		ft_heatmap(&data);
		data.yskulpt = ft_sculpt_y(&data);
		ft_play(data);
		x++;
	}
	return (0);
}
