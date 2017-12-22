/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihestin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:15:05 by ihestin           #+#    #+#             */
/*   Updated: 2017/12/21 17:49:16 by ihestin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		resolve(t_gril g, t_deftet	*d, t_tet *t, int *nb)
{
	nb[2] == 0;
	nb[3] == 0;
/* on cherche a placer chaque piece */
	while (0 <= nb[2] && nb[2] < nb[0])
	{
		if(!find(g,d,t,nb))
		{
/* je place la piece */
		  placement(g,d,t,nb);
/* je passe a la suivante */
		 nb[2]++;
		 nb[3] == 0;
		}
		else
		{
			if (--(nb[2]) < 0)
				return(1);
			enleve (g,d,t,nb);
		}
	}		


	g[0][0] ='A';
	g[0][1] ='\n';
	g[1][0] = 'B';
	g[1][1] = 'B';
	g[1][2] ='\n';
	if  (d || t||nb)
		;
	return (0);
}
