/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:55:22 by ohachim           #+#    #+#             */
/*   Updated: 2019/08/01 10:26:03 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillerh.h"

int	ft_out_data(t_data *data)
{
	int	x;

	x = 0;
	if (data->board != NULL)
		ft_strdel_imp(&data->board);
	if (data->token != NULL)
		ft_strdel_imp(&data->token);
	if (data->heatint != NULL)
	{
		while (x < data->xboard)
			ft_memdel((void**)&data->heatint[x++]);
		free(data->heatint);
		data->heatint = 0;
	}
	ft_printf("0 0\n");
	return (-1);
}
