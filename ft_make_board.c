/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 09:03:25 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/13 19:32:38 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillerh.h"

void	ft_make_board(t_data *data, char **line, int op)
{
	int		cntr;

	cntr = 0;
	if (op == 0)
	{
		data->xboard = ft_atoi(&line[0][8]);
		data->yboard = ft_atoi(&line[0][11]);
	}
	if ((data->board = (char**)malloc(sizeof(char*) * (data->xboard + 1))))
	{
		data->board[data->xboard] = 0;
		ft_skip_line(line, 0);
		while (cntr < data->xboard)
		{
			ft_skip_line(line, 0);
			data->board[cntr] = ft_strdup(&line[0][4]);
			cntr++;
		}
	}
	ft_skip_line(line, 0);
}
