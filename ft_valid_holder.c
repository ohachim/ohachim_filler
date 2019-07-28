/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_holder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 01:36:18 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/27 10:51:34 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillerh.h"

static	int	ft_iscrash(char c, int *crashes, t_data data)
{
	if (c == data.eput)
		return (0);
	if (c == data.put)
		(*crashes)++;
	return (1);
}

static int	ft_valid_loop(int xboard, int yboard, t_data data, int *crashes)
{
	int		xtoken;
	int		ytoken;
	int		dyboard;

	xtoken = data.xskulpt;
	dyboard = yboard;
	while (xtoken < data.xtoken)
	{
		ytoken = data.yskulpt;
		yboard = dyboard;
		while (ytoken < data.ytoken)
		{
			if (data.token[xtoken][ytoken] != '.')
				if (!(ft_iscrash(data.board[xboard][yboard], crashes, data)))
					return (0);
			if (*crashes > 1)
				return (0);
			yboard++;
			ytoken++;
		}
		xboard++;
		xtoken++;
	}
	return (1);
}

int			ft_valid_holder(int xboard, int yboard, t_data data)
{
	int		crashes;
	int		ret;

	crashes = 0;
	if (xboard + data.xtoken - data.xskulpt > data.xboard ||
		yboard + data.ytoken - data.yskulpt > data.yboard)
		return (0);
	ret = ft_valid_loop(xboard, yboard, data, &crashes);
	if (!ret)
		return (0);
	if (crashes != 1)
		return (0);
	return (1);
}
