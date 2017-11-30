/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emassou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:56:45 by emassou           #+#    #+#             */
/*   Updated: 2017/11/28 11:56:47 by emassou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_width(char *s)
{
	int i;
	int width;
	int line;

	i = 0;
	width = 0;
	line = 0;
	while (i < 4)
	{
		if (s[i] == '#' || s[i + 5] == '#' || s[i + 10] == '#' ||
			s[i + 15] == '#')
		{
			width++;
			if (line > 0)
				return (0);
		}
		else if (width > 0)
			line++;
		i++;
	}
	return (width);
}

int	ft_height(char *s)
{
	int i;
	int height;
	int line;

	i = 0;
	height = 0;
	line = 0;
	while (i < 19)
	{
		if (s[i] == '#' || s[i + 1] == '#' || s[i + 2] == '#' ||
			s[i + 3] == '#')
		{
			height++;
			if (line > 0)
				return (0);
		}
		else if (height > 0)
			line++;
		i += 5;
	}
	return (height);
}

int	ft_check_void(char *s)
{
	int i;
	int j;
	int k;

	while (s[i] != '\0')
	{
		if (s[i] == '#')
			j++;
		if (j == 2 && s[i] == '#')
		{
			while (s[i + 1 + k] == '#' && s[i + k] != '\0')
				k++;
			if (k > 5)
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_is_alone(char *s)
{
	int i;
	int yep;

	i = 0;
	yep = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (s[i + 1] == '#' || s[i - 1] == '#' || s[i + 5] == '#' ||
				s[i - 5] == '#')
				yep++;
			if (yep == 4)
				return (1);
		}
		i++;
	}
	return (0);
}
