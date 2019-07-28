/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_scores.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 04:14:16 by ohachim           #+#    #+#             */
/*   Updated: 2019/07/25 15:23:05 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visuh.h"

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

char	*ft_get_scores(t_sdl *visu, char **board)
{
	char	*o;
	char	*x;
	char	*temp;

	o = ft_count(board, 'O', 'o');
	x = ft_count(board, 'X', 'x');
	visu->score = ft_strjoin(o, "-- VS --");
	temp = visu->score;
	visu->score = ft_strjoin(visu->score, x);
	free(temp);
	free(o);
	free(x);
	return (visu->score);
}
