/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihestin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:36:08 by ihestin           #+#    #+#             */
/*   Updated: 2017/12/20 18:30:16 by ihestin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			calint(int  **coord)
{
	int		i;
	int		i0;
	int		i1;
	int		ret;

	i = 0;
	i0 = coord[0][0];
	i1 = coord[0][1];
	while (++i < 4)
	{
		i0 = (i0 > coord[i][0]) ? coord[i][0] : i0;
		i1 = (i1 > coord[i][1]) ? coord[i][1] : i1;
	}
	ret = 0;
	i = -1;
	while (++i < 4)
		ret = ret*16 + (coord[i][0] - i0) * 4 + (coord[i][1] - i1);
	return (ret);
}

