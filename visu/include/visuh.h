/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:31:52 by ohachim           #+#    #+#             */
/*   Updated: 2019/08/01 11:03:31 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUH_H
# define VISUH_H

# define HEIGHT 1205
# define WIDTH 1000

# include "fillerh.h"
# include "libft.h"
# include <SDL.h>
# include <SDL_timer.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <stdlib.h>

typedef	struct		s_board
{
	int				startx;
	int				starty;
	int				steps;
}					t_board;

typedef struct		s_dsl
{
	SDL_Window		*window;
	SDL_Event		e;
	SDL_Renderer	*renderer;
	SDL_Surface		*message;
	SDL_Texture		*tmessage;
	SDL_Rect		message_rect;
	SDL_Surface		*solidp;
	TTF_Font		*font;
	SDL_Color		colors;
	char			*o_vs_x;
	char			*score;
	t_board			board;
	int				quit;
	int				speed;
}					t_sdl;

int					ft_sdlclose_ws(SDL_Surface **surface
		, SDL_Window **window, SDL_Renderer **renderer, SDL_Texture **texture);
int					ft_init_sdlri(SDL_Window **window
		, SDL_Renderer **renderer, char *name);
void				ft_draw_board(t_sdl *visual, int y, int x, char **board);
int					ft_get_players(t_sdl *visual, char **line);
void				ft_get_event(t_sdl *visu, int *pause);
void				ft_get_ox(t_sdl *visual, char *print, int x, int y);
char				*ft_get_scores(t_sdl *visu, char **board);
int					ft_visu_score(t_sdl *visu, char **board);
int					ft_skip_line(char **line, int fd);
void				ft_dsculpt_token(t_data *data);
int					ft_free_datav(t_data *data, t_sdl *visual);
int					ft_visualization(t_sdl *vis, t_data *data);

#endif
