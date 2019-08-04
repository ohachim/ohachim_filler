/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:00:59 by ohachim           #+#    #+#             */
/*   Updated: 2019/08/01 11:05:37 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

int	ft_visualization(t_sdl *vis, t_data *data)
{
	SDL_SetRenderDrawColor(vis->renderer, 64, 64, 64, 0);
	SDL_RenderClear(vis->renderer);
	if (!(ft_visu_score(vis, data->board)))
		return (0);
	ft_draw_board(vis, data->xboard, data->yboard, data->board);
	SDL_RenderPresent(vis->renderer);
	if (vis->speed > 0)
		SDL_Delay(vis->speed);
	return (1);
}
