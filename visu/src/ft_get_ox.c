/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 02:30:39 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/25 15:28:32 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

void	ft_get_ox(t_sdl *visual, char *print, int x, int y)
{
	if (visual->tmessage != NULL)
		SDL_DestroyTexture(visual->tmessage);
	if (visual->message != NULL)
		SDL_FreeSurface(visual->message);
	visual->colors.r = 255;
	visual->colors.g = 255;
	visual->colors.b = 255;
	visual->message = TTF_RenderText_Solid(visual->font, print, visual->colors);
	visual->tmessage = SDL_CreateTextureFromSurface(visual->renderer
													, visual->message);
	visual->message_rect.x = x;
	visual->message_rect.y = y;
	visual->message_rect.h = 80;
	visual->message_rect.w = 800;
	SDL_RenderCopy(visual->renderer, visual->tmessage, NULL
					, &visual->message_rect);
}
