/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 09:03:25 by ohachim           #+#    #+#             */
/*   Updated: 2019/08/01 10:12:48 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillerh.h"

int	ft_make_board(t_data *data, char **line, int op, int cntr)
{
	if (op == 0)
	{
		data->xboard = ft_atoi(&line[0][8]);
		data->yboard = ft_atoi(&line[0][11]);
	}
	if ((data->board = (char**)malloc(sizeof(char*) * (data->xboard + 1))))
	{
		data->board[data->xboard] = 0;
		if (!(ft_skip_line(line, 0)))
			return (0);
		while (cntr < data->xboard)
		{
			if (!(ft_skip_line(line, 0)))
				return (0);
			if (!(data->board[cntr] = ft_strdup(&line[0][4])))
				return (0);
			cntr++;
		}
	}
	else
		return (0);
	if (!(ft_skip_line(line, 0)))
		return (0);
	return (1);
}
