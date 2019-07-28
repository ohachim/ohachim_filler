/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 08:56:14 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/11 15:55:06 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillerh.h"

void	ft_make_token(t_data *data, char **line, int op)
{
	int		cntr;

	cntr = 0;
	if (op == 0)
	{
		data->xtoken = ft_atoi(&line[0][6]);
		data->ytoken = ft_atoi(&line[0][8]);
	}
	if ((data->token = (char**)malloc(sizeof(char*) * (data->xtoken + 1))))
	{
		data->token[data->xtoken] = 0;
		while (cntr < data->xtoken)
		{
			ft_skip_line(line, 0);
			data->token[cntr] = ft_strdup(*line);
			cntr++;
		}
	}
	ft_dsculpt_token(data);
}
