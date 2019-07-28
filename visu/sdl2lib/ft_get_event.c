/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 01:05:06 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/25 15:23:37 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visuh.h"

void	ft_get_event(t_sdl *visu, int *pause)
{
	if (visu->e.type == SDL_QUIT || visu->e.key.keysym.sym == SDLK_q
								|| visu->e.key.keysym.sym == SDLK_ESCAPE)
		visu->quit = 1;
	if (visu->e.key.keysym.sym == SDLK_p)
		*pause = 1;
	if (visu->e.key.keysym.sym == SDLK_SPACE)
		*pause = 0;
	if (visu->e.key.keysym.sym == SDLK_UP && visu->speed > 0)
		visu->speed -= 50;
	if (visu->e.key.keysym.sym == SDLK_DOWN && visu->speed < 1000)
		visu->speed += 50;
}
