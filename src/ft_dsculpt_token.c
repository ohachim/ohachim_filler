/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dsculpt_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 23:06:10 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/11 16:17:25 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillerh.h"

static int	ft_get_xmax(t_data *data, char **token)
{
	int		y;
	int		x;
	int		xmax;
	int		delete;

	y = 0;
	xmax = 0;
	while (y < data->ytoken)
	{
		delete = 0;
		x = data->xtoken - 1;
		while (x >= 0 && token[x][y] != '*')
		{
			x--;
			delete++;
		}
		x++;
		if (delete < xmax || y == 0)
			xmax = delete;
		y++;
	}
	return (xmax);
}

static int	ft_get_ymax(t_data *data, char **token)
{
	int		x;
	int		y;
	int		ymax;
	int		delete;

	x = 0;
	while (x < data->xtoken)
	{
		delete = 0;
		y = data->ytoken - 1;
		while (y >= 0 && token[x][y] != '*')
		{
			y--;
			delete++;
		}
		if (delete < ymax || x == 0)
			ymax = delete;
		x++;
	}
	return (ymax);
}

static void	ft_sculpt_yo(int x, t_data *data, int y, int dy)
{
	int		ytoken;

	dy = y;
	while (x < data->xtoken)
	{
		y = dy;
		ytoken = data->ytoken - 1;
		while (y > 0)
		{
			data->token[x][ytoken] = '\0';
			ytoken--;
			y--;
		}
		x++;
	}
	data->ytoken -= dy;
}

void		ft_dsculpt_token(t_data *data)
{
	int		x;
	int		xtoken;
	int		y;
	int		dy;
	int		counter;

	counter = 0;
	x = ft_get_xmax(data, data->token);
	y = ft_get_ymax(data, data->token);
	dy = y;
	xtoken = data->xtoken - 1;
	data->xtoken -= x;
	while (x > 0)
	{
		ft_strdel(&data->token[xtoken]);
		xtoken--;
		x--;
	}
	ft_sculpt_yo(x, data, y, dy);
}
