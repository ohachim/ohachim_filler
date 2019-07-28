/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sculpt_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 01:35:34 by ohachim           #+#    #+#             */
/*   Updated: 2019/06/30 01:58:23 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillerh.h"

int	ft_sculpt_y(t_data *data)
{
	int		y;
	int		x;
	int		delete;
	int		ymax;

	x = 0;
	while (x < data->xtoken)
	{
		y = 0;
		delete = 0;
		while (y < data->ytoken)
		{
			if (data->token[x][y] == '.')
				delete++;
			if (data->token[x][y] == '*')
				break ;
			y++;
		}
		if (delete < ymax || x == 0)
			ymax = delete;
		x++;
	}
	return (ymax);
}
