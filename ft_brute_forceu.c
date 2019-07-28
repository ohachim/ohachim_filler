/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brute_forceu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:15:21 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/27 17:57:44 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillerh.h"

int			ft_brute_forceu(t_data data, int fill)
{
	int		x;
	int		y;

	x = 0;
	while (x < data.xboard)
	{
		y = 0;
		while (y < data.yboard)
		{
			if (data.heatint[x][y] == fill && ft_valid_holder(x, y, data))
			{
				ft_printf("%d %d\n", x - data.xskulpt, y - data.yskulpt);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
