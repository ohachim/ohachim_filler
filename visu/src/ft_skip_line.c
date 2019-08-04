/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 06:51:22 by ohachim           #+#    #+#             */
/*   Updated: 2019/08/01 10:28:58 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillerh.h"

static int	ft_get_nline(char **line, int fd)
{
	char	buf[2];
	char	*temp;
	int		ret;
	int		retadd;

	retadd = 0;
	temp = NULL;
	if (!(*line = ft_strnew(1)))
		return (0);
	while ((ret = read(fd, buf, 1)))
	{
		retadd = ret + retadd;
		buf[ret] = '\0';
		temp = *line;
		if (!(ft_isascii(buf[0])) || !(*line = ft_strjoin(*line, buf)))
		{
			ft_strdel(&temp);
			return (0);
		}
		ft_strdel(&temp);
		if ((ft_strchr(buf, '\n')))
			break ;
	}
	line[0][retadd - 1] = '\0';
	return (retadd);
}

int			ft_skip_line(char **line, int fd)
{
	char	*temp;
	int		t;

	temp = *line;
	t = ft_get_nline(line, fd);
	ft_strdel(&temp);
	return (t);
}
