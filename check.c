/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emassou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:56:54 by emassou           #+#    #+#             */
/*   Updated: 2017/11/28 11:56:56 by emassou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_checkchar(char *s)
{
	int i;
	int hash;
	int point;
	int end;

	i = 0;
	hash = 0;
	point = 0;
	end = 0;
	while (s[i] != "\0")
	{
		if (s[i] == '#')
			hash++;
		if (s[i] == '.')
			point++;
		if (s[i] == '\n')
			end++;
		i++;
	}
	if (hash != 4 || point != 12 || end != 4)
		return (0);
	return (1);
}

int	ft_checkline(char *s)
{
	int x;
	int y;

	while (s[x] != '\0')
	{
		if (s[x] == '.' || s[x] == '#')
			y++;
		if (y > 4)
			return (0);
		if (s[x] == '\n')
		{
			y = 0;
		}
		x++;
	}
	return (1);
}

int	ft_checkshape(char *s)
{
	int i;
	int width;
	int height;

	i = 0;
	width = ft_width(s);
	height = ft_height(s);
	if (ft_is_alone(s) == 0)
		return (0);
	if (ft_check_void(s) == 0 || height == 0 || width == 0)
		return (0);
	if (height == 2 && width == 2)
		return (1);
	else if (height == 3 && width == 2)
		return (1);
	else if (height == 2 && width == 3)
		return (1);
	else if (height == 1 && width == 4)
		return (1);
	else if (height == 4 && width == 1)
		return (1);
	else
		return (0);
}

int	ft_checktab(char **tab)
{
	int i;

	if (!tab)
		return (NULL);
	i = 0;
	while (i < ft_nb_tetri(s))
	{
		if (ft_checkchar(tab[i]) != 1)
			return (0);
		if (ft_checkline(tab[i]) != 1)
			return (0);
		if (ft_checkshape(tab[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_ftest(char *buf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[x] != '\0')
	{
		if (buf[x] == '\n')
			y++;
		if (y == 4)
		{
			if (buf[x + 1] != '\n' || buf[x + 1] != '\0')
				return (0);
			if (buf[x + 1] == '\n')
				x++;
			y = 0;
		}
		x++;
	}
	return (1);
}
