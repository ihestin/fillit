/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihestin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:24:50 by ihestin           #+#    #+#             */
/*   Updated: 2017/12/15 14:39:58 by ihestin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	err_msg(int i)
{
	if (i == 0)
	{
		printf ("\n");
		exit(1);
	}
	if (i == 1)
	{
		printf ("usage : ./fillit source_file\n");
		exit(1);
	}
	printf ("error\n");
	exit (2);
}

int		main(int argc, char *argv[])
{
	t_gril		grille;
	t_deftet	deftet[19];
	t_tet		tet[27];
	int			nbr[4];
	int			ret;

	if (argc != 2)
		err_msg (1);
/* on initialise le tableau contenant les 19 formes de tetriminos possible */
	ft_init(deftet);
/* On lit le fichier et on remplit tet, nbr est le nombre de tetriminos trouve*/
	nbr[0] = read_fic(argv[1], deftet, tet);
	if (nbr[0] <= 0)
		err_msg (-nbr[0]);
/* On calcul la taille du carre minimal, le carre pourra etre augmente a cause de la forme de certaine piece*/
	cal_si(nbr, tet, deftet);
/* On cheche une solution pour le minimum et on recommece avec +1 tant que lon ne trouve pas*/
	ret = 1;
	while (ret == 1)
	{
/* on initalise la grille */
		g_init(grille,nbr);
/* on essaie de resoudre */
		ret = resolve(grille,deftet,tet,nbr);
		if (ret == 1)
			(nbr[1])++;
	}
	if (ret != 0)
		err_msg (7);
/* On affiche la grille*/
	affiche(grille, nbr);
	return(0);
}
