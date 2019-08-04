/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillerh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:18:49 by ohachim           #+#    #+#             */
/*   Updated: 2019/08/01 10:31:42 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLERH_H
# define FILLERH_H

# include "libft.h"

typedef struct	s_data
{
	char		put;
	char		eput;
	char		**board;
	int			**heatint;
	char		**token;
	int			xboard;
	int			yboard;
	int			xtoken;
	int			xskulpt;
	int			ytoken;
	int			yskulpt;
	int			xstart;
	int			ystart;
	char		p;
	long int	counter;
	int			maxheat;
}				t_data;

void			ft_player_put(t_data *data, char **line);
int				ft_make_board(t_data *data, char **line, int op, int cntr);
int				ft_skip_line(char **line, int fd);
int				ft_make_token(t_data *data, char **line, int op);
void			ft_play(t_data data);
void			ft_strdel_imp(char ***as);
void			ft_dsculpt_token(t_data *data);
void			ft_brute_force(t_data data);
int				ft_valid_holder(int xboard, int yboard, t_data data);
int				ft_sculpt_y(t_data *data);
void			ft_heatmap(t_data *data);
int				ft_brute_forceu(t_data data, int fill);
int				ft_brute_forcel(t_data data, int fill);
int				ft_out_data(t_data *data);

#endif
