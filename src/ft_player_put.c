/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 06:57:10 by ohachim           #+#    #+#             */
/*   Updated: 2019/06/25 09:10:46 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillerh.h"

void	ft_player_put(t_data *data, char **line)
{
	if (ft_strstr(*line, "ohachim"))
		data->put = ((ft_atoi(&line[0][10]) == 1) ? 'O' : 'X');
	else
		data->put = ((ft_atoi(&line[0][10]) == 1) ? 'X' : 'O');
	data->eput = ((data->put == 'X') ? 'O' : 'X');
}
