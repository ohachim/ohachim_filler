/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:48:03 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/27 18:02:51 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillerh.h"

void		ft_play(t_data data)
{
	int		fill;

	fill = 130;
	if (data.p == 'l')
		while (fill <= data.maxheat - 1 && !ft_brute_forceu(data, fill))
			fill++;
	else
		while (fill <= data.maxheat - 1 && !ft_brute_forcel(data, fill))
			fill++;
	if (fill > data.maxheat - 1)
		ft_brute_force(data);
}
