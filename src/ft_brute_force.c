/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brute_force.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 01:33:56 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/11 21:03:40 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillerh.h"

void	ft_brute_force(t_data data)
{
	int		x;
	int		y;

	x = 0;
	while (x < data.xboard)
	{
		y = 0;
		while (y < data.yboard)
		{
			if (ft_valid_holder(x, y, data))
			{
				ft_printf("%d %d\n", x - data.xskulpt, y - data.yskulpt);
				return ;
			}
			y++;
		}
		x++;
	}
	ft_printf("0 0\n");
}
