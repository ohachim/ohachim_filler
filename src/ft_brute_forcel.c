/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brute_forcel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:26:02 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/27 17:58:20 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillerh.h"

int	ft_brute_forcel(t_data data, int fill)
{
	int		x;
	int		y;

	x = data.xboard - 1;
	while (x >= 0)
	{
		y = data.yboard - 1;
		while (y >= 0)
		{
			if (data.heatint[x][y] == fill && ft_valid_holder(x, y, data))
			{
				ft_printf("%d %d\n", x - data.xskulpt, y - data.yskulpt);
				return (1);
			}
			y--;
		}
		x--;
	}
	return (0);
}
