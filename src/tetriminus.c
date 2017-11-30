#include "fillit.h"

/*
** Gives the number of tetriminos in the given input
*/

int			get_nb_tetrimino(char *s)
{
	int i;
	int nb_tetri;

	i = 0;
	nb_tetri = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && (s[i + 1] == '\n' || s[i + 1] == '\0'))
			nb_tetri++;
		i++;
	}
	return (nb_tetri);
}

/*
** Return a new tetriminos shape with its letter for the linked list
** Tetrimino is a tab of it lines
*/

t_tetrimino	*newtetri(char **tetrimino, int num)
{
	t_tetrimino *new;

	new = NULL;
	new = (t_tetrimino*)malloc(sizeof(t_tetrimino));
	if (new == NULL)
		return (NULL);
	new->tetrimino = tetrimino;
	new->letter = 'A' + num;
	new->x = 0;
	new->y = 0;
	new->next = NULL;
	return (new);
}

/*
** Alloc enough memory for the returned solution of fillit (char**)
*/

char		**create_tab(char **tab, int square_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	tab = ft_memalloc(sizeof(char *) * square_size + 1);
	while (i < square_size)
	{
		tab[i] = ft_memalloc(sizeof(char) * square_size + 1);
		i++;
	}
	i = 0;
	while (j < square_size)
	{
		while (i < square_size)
		{
			tab[j][i++] = '.';
		}
		tab[j][i] = '\0';
		i = 0;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}