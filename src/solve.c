#include "fillit.h"

/*
** Test if position is okay and not out of range or on already existing element
*/

static int		test_pos(t_tetrimino *start, char **tab, int square_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (start->tetrimino[i][j] == '#' && (start->x + j >= square_size \
						|| start->y + i >= square_size))
				return (0);
			if (start->tetrimino[i][j] == '#' && \
					ft_isalpha(tab[start->y + i][start->x + j]) == 1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

/*
** Place the tetriminos element from start to tab if test_pos was ok
*/

static char		**placement(t_tetrimino *start, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (start->tetrimino[i][j] == '#')
				tab[start->y + i][start->x + j] = start->letter;
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

/*
** In tab** replace letter of given tetriminos at *start pos, with a '.'
*/

static char		**delete(t_tetrimino *start, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == start->letter)
				tab[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

/*
** Recursive search for the best place while *start reading isn't finished
** Test position to place it on tab, or delete element if next place is wrong
** Return 0 if wrong return 1 if place is right
*/

int				place(t_tetrimino *start, int square_size, char **tab)
{
	if (start != NULL)
	{
		while (start->y * start->x < square_size * square_size)
		{
			if ((test_pos(start, tab, square_size)) == 1)
			{
				tab = placement(start, tab);
				ft_putstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				puttab(tab);
				sleep(1);
				if (place(start->next, square_size, tab) == 1)
					return (1);
				tab = delete(start, tab);
				ft_putstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				puttab(tab);
				sleep(1);
			}
			if (start->x < square_size)
				start->x++;
			else
			{
				start->x = 0;
				start->y++;
			}
		}
		start->x = 0;
		start->y = 0;
		return (0);
	}
	return (1);
}


/*
** Solve fillit and return the solution (char **)
** Square_size is the space needed for tab_solved that is the solution
** Return tab_solved
*/

char			**solve(t_tetrimino *start, int square_size, char **tab_solved)
{
	arrange(start);
	tab_solved = create_tab(tab_solved, square_size);
	while (place(start, square_size, tab_solved) == 0)
	{
		square_size++;
		start->x = 0;
		start->y = 0;
		free_tab(tab_solved, square_size);
		tab_solved = create_tab(tab_solved, square_size);
	}
	ft_putstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	return (tab_solved);
}