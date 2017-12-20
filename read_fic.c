/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihestin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 08:48:27 by ihestin           #+#    #+#             */
/*   Updated: 2017/12/20 18:31:18 by ihestin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		verif(char *s)
{
	int	i;
	int j;

	if (s[20] != '\n')
		return(2);
	i = -1;
	j = 0;
	while (++i < 20)
	{
		if (i % 5 == 4 && s[i] != 'n')
			return (2);
		if (i % 5 != 4)
			if (s[i] == '#')
				j++;
			else  
			if (s[i] != '.')
				return (2);
	}
}

int		insere(char *s, int n, t_deftet *d, t_tet *t)
{
	int		t[4][2];
	int		i;
	int		j;

	i = -1;
	j = -1;

	while (j < 4 && ++i < 19)
		if (s[i] == '#')
		{
			t[++j][0] = i / 5;
			t[j][1] = i % 5;
		}
	j = calint(t);
	i = 0;
	while (i < 19 && d[i].pos != j)
		i++;
	if (i == 19)
		return(2);
	t[n] = i;
	(d[i].nb[0])++;
	d[i].nb[d[i].nb[0]] = n;
	return(0);
}

int		instet(char *s, int i, t_deftet *d, t_tet *t)
{
	char	*st;

	st = s + (i * 21);
	if (!verif(st))
		return (2);
	return (insere(st, i, d, t));
}


int		read_fic(char *nom, t_deftet *d, t_tet *t)
{
	char	*buffer[600];
	int		fd;
	int		nb;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return(-3);
	i = read(fd, buffer, 600);
	close (fd);
	if (i < 0 || i % 21 != 20 || i > 545)
		return (-2);
	buffer[i] = '\n';
	n = i / 21 + 1;
	fd = i;
	i = -1;
	while (++i < n)
 		if (instet(buffer, i, d, t) != 0)
			return(-2);
	return (n);
}
