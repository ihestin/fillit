/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihestin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:05:14 by ihestin           #+#    #+#             */
/*   Updated: 2017/12/15 14:39:52 by ihestin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef	char	t_gril[20][20];
typedef	int		t_tet;
typedef struct	s_deftet
{
	int					pos;
	int					form[2];
	unsigned char		pos1;
	unsigned char		pos2;
	char				l1[5];
	char				l2[5];
	char				l3[5];
	char				l4[5];
}				t_deftet;

void				ft_init(t_deftet dtet);
int					read_fic(char *str, t_deftet *def, t_tet *tet);
void				cal_si(int *nb, t_tet *tet, t_deftet *dtet);
void				g_init(tgril grille, int *nb);
int					resolve(tgril grille, tdeftet deft, t_tet *tet, int *nb);
void				affiche(tgril grille, int *nb)

#endif
