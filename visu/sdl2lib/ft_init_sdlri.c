/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sdlri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:42:03 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/23 05:44:37 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visuh.h"

static int	ft_init_img(void)
{
	int		imgflag;

	imgflag = IMG_INIT_PNG;
	if (!(IMG_Init(imgflag) & IMG_INIT_PNG))
	{
		printf("HELLO\n");
		ft_putendl_fd(IMG_GetError(), 2);
		return (-1);
	}
	return (1);
}

static int	ft_init_renderer(SDL_Window **window, SDL_Renderer **renderer)
{
	if (!(*renderer = SDL_CreateRenderer(*window, -1
					, SDL_RENDERER_ACCELERATED)))
	{
		ft_putendl_fd("Couldn't create renderer -->", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (0);
	}
	SDL_SetRenderDrawColor(*renderer, 127, 127, 127, 127);
	return (1);
}

int			ft_init_sdlri(SDL_Window **window
			, SDL_Renderer **renderer, char *name)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_putendl_fd("Couldn't init video --> ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (-1);
	}
	if (!(*window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED
			, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
	{
		ft_putendl_fd("Couldn't create window --> ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (-2);
	}
	if (!(ft_init_renderer(window, renderer)))
		return (-3);
	if (ft_init_img() < 0)
		return (-4);
	return (1);
}
