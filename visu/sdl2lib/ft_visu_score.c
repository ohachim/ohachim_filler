/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu_score.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 07:32:35 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/25 15:30:37 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visuh.h"

void	ft_get_x(t_sdl *visual, char *print, int x, int y)
{
	if (visual->tmessage != NULL)
		SDL_DestroyTexture(visual->tmessage);
	if (visual->message != NULL)
		SDL_FreeSurface(visual->message);
	visual->colors.r = 255;
	visual->colors.g = 102;
	visual->colors.b = 102;
	visual->message = TTF_RenderText_Solid(visual->font, print, visual->colors);
	visual->tmessage = SDL_CreateTextureFromSurface(visual->renderer
			, visual->message);
	visual->message_rect.x = x;
	visual->message_rect.y = y;
	visual->message_rect.h = 70;
	visual->message_rect.w = 100;
	SDL_RenderCopy(visual->renderer, visual->tmessage, NULL
			, &visual->message_rect);
}

void	ft_get_o(t_sdl *visual, char *print, int x, int y)
{
	if (visual->tmessage != NULL)
		SDL_DestroyTexture(visual->tmessage);
	if (visual->message != NULL)
		SDL_FreeSurface(visual->message);
	visual->colors.r = 102;
	visual->colors.g = 178;
	visual->colors.b = 255;
	visual->message = TTF_RenderText_Solid(visual->font, print, visual->colors);
	visual->tmessage = SDL_CreateTextureFromSurface(visual->renderer
			, visual->message);
	visual->message_rect.x = x;
	visual->message_rect.y = y;
	visual->message_rect.h = 70;
	visual->message_rect.w = 100;
	SDL_RenderCopy(visual->renderer, visual->tmessage, NULL
			, &visual->message_rect);
}

char	*ft_count(char **board, char c1, char c2)
{
	int		x;
	int		y;
	int		count;

	count = 0;
	x = 0;
	while (board[x])
	{
		y = 0;
		while (board[x][y])
		{
			if (board[x][y] == c1 || board[x][y] == c2)
				count++;
			y++;
		}
		x++;
	}
	return (ft_itoa(count));
}

void	ft_visu_score(t_sdl *visu, char **board)
{
	char	*o;
	char	*x;

	ft_get_ox(visu, visu->o_vs_x, 95, 30);
	o = ft_count(board, 'O', 'o');
	x = ft_count(board, 'X', 'x');
	ft_get_o(visu, o, 180, 120);
	ft_get_x(visu, x, 680, 120);
	free(o);
	free(x);
}
