/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void	moebiuspalette(t_env *e)
{
	e->palet[0] = WBROWN3;
	e->palet[1] = WDVIOLET;
	e->palet[2] = WDBLUE;
	e->palet[3] = WBLUE5;
	e->palet[4] = WBLUE4;
	e->palet[5] = WBLUE3;
	e->palet[6] = WBLUE2;
	e->palet[7] = WBLUE1;
	e->palet[8] = WBLUE0;
	e->palet[9] = WLLBLUE;
	e->palet[10] = WLLYELLOW;
	e->palet[11] = WLYELLOW;
	e->palet[12] = WBYELLOW;
	e->palet[13] = WBROWN0;
	e->palet[14] = WBROWN1;
	e->palet[15] = WBROWN2;
}

static void	flashpalette(t_env *e)
{
	e->palet[0] = PPINK;
	e->palet[1] = BLACK;
	e->palet[2] = PRED;
	e->palet[3] = PORANGE;
	e->palet[4] = PYELLOW;
	e->palet[5] = PGREEN;
	e->palet[6] = PCYAN;
	e->palet[7] = PBLUE;
}

void		put_color(t_env *e, int x, int y, int iter)
{
	if (iter > 0 && iter < e->maxiter)
	{
		if (e->palette == UNICOLOR)
			pixel_put(e, x, y, convert_rgb(255 * iter / e->maxiter, 255 * iter
	/ e->maxiter, 0 * iter / e->maxiter));
		if (e->palette == MOEBIUS)
			pixel_put(e, x, y, e->palet[iter % 16]);
		if (e->palette == FLASH)
			pixel_put(e, x, y, e->palet[iter % 8]);
	}
}

void		makepalette(t_env *e)
{
	if (e->palette == MOEBIUS)
		moebiuspalette(e);
	if (e->palette == FLASH)
		flashpalette(e);
}
