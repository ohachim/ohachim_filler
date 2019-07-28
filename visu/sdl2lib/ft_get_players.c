/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 02:37:49 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/24 09:08:52 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visuh.h"

void	ft_trim_player(char **player)
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
	*player = ft_strdup(&player[0][x + 1]);
	free(temp);
}

void	ft_get_players(t_sdl *visual, char **line)
{
	char	*o;
	char	*x;
	char	*temp;

	o = ft_strdup(&line[0][14]);
	ft_skip_line(line, 0);
	ft_skip_line(line, 0);
	x = ft_strdup(&line[0][14]);
	ft_trim_player(&o);
	ft_trim_player(&x);
	visual->o_vs_x = ft_strjoin("", o);
	temp = visual->o_vs_x;
	visual->o_vs_x = ft_strjoin(visual->o_vs_x, " --VS-- ");
	free(temp);
	temp = visual->o_vs_x;
	visual->o_vs_x = ft_strjoin(visual->o_vs_x, x);
	free(temp);
}
