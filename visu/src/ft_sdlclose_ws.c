/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdlclose_ws.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:51:16 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/25 15:28:47 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

int	ft_sdlclose_ws(SDL_Surface **surface, SDL_Window **window
		, SDL_Renderer **renderer, SDL_Texture **texture)
{
	if (*surface != NULL)
	{
		SDL_FreeSurface(*surface);
		*surface = NULL;
	}
	if (*window != NULL)
	{
		SDL_DestroyWindow(*window);
		*window = NULL;
	}
	if (*renderer != NULL)
	{
		SDL_DestroyRenderer(*renderer);
		renderer = NULL;
	}
	if (*texture != NULL)
	{
		SDL_DestroyTexture(*texture);
		*texture = NULL;
	}
	SDL_Quit();
	return (1);
}
