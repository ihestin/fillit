/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihestin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:05:14 by ihestin           #+#    #+#             */
/*   Updated: 2017/12/21 17:29:17 by ihestin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#define NB_SIZE 4

typedef	char	t_gril[20][20];
typedef	int		t_tet;
typedef struct	s_deftet
{
	unsigned int		pos;
	int					nb[26];
}				t_deftet;

void				ft_init(t_deftet *dtet);
int					read_fic(char *str, t_deftet *def, t_tet *tet);
void				cal_si(int *nb, t_deftet *dtet, t_tet *tet);
void				g_init(t_gril grille, int *nb);
int					resolve(t_gril grille, t_deftet *deft, t_tet *tet, int *nb);
void				affiche(t_gril grille, int *nb);
int					calint(int	**coord);

#endif
