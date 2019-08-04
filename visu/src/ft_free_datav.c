/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_datav.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 13:14:29 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/31 13:14:32 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

int	ft_free_datav(t_data *data, t_sdl *visual)
{
	int	x;

	x = 0;
	ft_strdel(&visual->o_vs_x);
	ft_strdel(&visual->score);
	if (data->board != NULL)
		ft_strdel_imp(&data->board);
	if (data->token != NULL)
		ft_strdel_imp(&data->token);
	return (-1);
}
