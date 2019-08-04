/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 04:57:07 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/27 18:21:18 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillerh.h"

static void	ft_fillit(t_data *dt, int xb, int yb, int fill)
{
	if (yb - 1 >= 0 && (dt->heatint[xb][yb - 1] == '.'
		|| dt->heatint[xb][yb - 1] == dt->put))
		dt->heatint[xb][yb - 1] = fill;
	if (yb + 1 < dt->yboard && (dt->heatint[xb][yb + 1] == '.'
		|| dt->heatint[xb][yb + 1] == dt->put))
		dt->heatint[xb][yb + 1] = fill;
	if (xb - 1 >= 0 && yb - 1 >= 0 && (dt->heatint[xb - 1][yb - 1] == '.'
		|| dt->heatint[xb - 1][yb - 1] == dt->put))
		dt->heatint[xb - 1][yb - 1] = fill;
	if (xb - 1 >= 0 && (dt->heatint[xb - 1][yb] == '.'
		|| dt->heatint[xb - 1][yb] == dt->put))
		dt->heatint[xb - 1][yb] = fill;
	if (xb - 1 >= 0 && yb + 1 < dt->yboard && (dt->heatint[xb - 1][yb + 1]\
		== '.' || dt->heatint[xb - 1][yb + 1] == dt->put))
		dt->heatint[xb - 1][yb + 1] = fill;
	if (xb + 1 < dt->xboard && yb - 1 >= 0 && (dt->heatint[xb + 1][yb - 1]\
		== '.' || dt->heatint[xb + 1][yb - 1] == dt->put))
		dt->heatint[xb + 1][yb - 1] = fill;
	if (xb + 1 < dt->xboard && (dt->heatint[xb + 1][yb] == '.'
		|| dt->heatint[xb + 1][yb] == dt->put))
		dt->heatint[xb + 1][yb] = fill;
	if (xb + 1 < dt->xboard && yb + 1 < dt->yboard && (dt->heatint[xb + 1]\
		[yb + 1] == '.' || dt->heatint[xb + 1][yb + 1] == dt->put))
		dt->heatint[xb + 1][yb + 1] = fill;
}

static int	ft_fill(t_data *data, int c, int fill)
{
	int		xboard;
	int		yboard;
	int		filled;

	filled = 0;
	xboard = 0;
	while (xboard < data->xboard)
	{
		yboard = 0;
		while (yboard < data->yboard)
		{
			if (data->heatint[xboard][yboard] == c)
			{
				ft_fillit(data, xboard, yboard, fill);
				filled++;
			}
			yboard++;
		}
		xboard++;
	}
	return (filled);
}

static int	ft_heatpoint(t_data *data, int fill)
{
	if (fill == 130)
		return (ft_fill(data, data->eput, fill));
	else
		return (ft_fill(data, fill - 1, fill));
}

void		ft_heatmap(t_data *data)
{
	int		fill;

	fill = 130;
	while ((ft_heatpoint(data, fill)))
		fill++;
	data->maxheat = fill;
}
