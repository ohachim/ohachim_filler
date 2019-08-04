/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 02:37:49 by ohachim           #+#    #+#             */
/*   Updated: 2019/08/01 10:40:47 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

static int	ft_trim_player(char **player)
{
	int		x;
	char	*temp;

	x = 0;
	while (player[0][x])
		x++;
	while (player[0][x] != '.')
		player[0][x--] = '\0';
	player[0][x] = '\0';
	while (player[0][x] != '/')
		x--;
	temp = *player;
	if (!(*player = ft_strdup(&player[0][x + 1])))
	{
		ft_strdel(&temp);
		return (0);
	}
	ft_strdel(&temp);
	return (1);
}

static	int	ft_get_each(char **o, char **x, char **line)
{
	if (!(*o = ft_strdup(&line[0][14])))
		return (0);
	if (!(ft_skip_line(line, 0)) || line[0][0] == 'e'
		|| !(ft_skip_line(line, 0) || line[0][0] == 'e'))
		return (0);
	if (!(*x = ft_strdup(&line[0][14])))
		return (0);
	if (!(ft_trim_player(o)) || !(ft_trim_player(x)))
		return (0);
	return (1);
}

int			ft_get_players(t_sdl *visual, char **line)
{
	char	*o;
	char	*x;
	char	*temp;

	if (!(ft_get_each(&o, &x, line)))
		return (0);
	if (!(visual->o_vs_x = ft_strjoin("", o)))
		return (0);
	temp = visual->o_vs_x;
	if (!(visual->o_vs_x = ft_strjoin(visual->o_vs_x, " --VS-- ")))
	{
		ft_strdel(&temp);
		return (0);
	}
	ft_strdel(&temp);
	temp = visual->o_vs_x;
	if (!(visual->o_vs_x = ft_strjoin(visual->o_vs_x, x)))
	{
		ft_strdel(&temp);
		return (0);
	}
	ft_strdel(&temp);
	return (1);
}
