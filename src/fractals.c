/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void	mandeloop(t_env *e, int x, int y)
{
	int iter;

	iter = 0;
	e->re.c = (double)x / (WIN_L / (e->re.max - e->re.min)) + e->re.min;
	e->im.c = (double)y / (WIN_H / (e->im.max - e->im.min)) + e->im.min;
	e->re.z = 0;
	e->im.z = 0;
	iter = 0;
	while (e->re.z * e->re.z + e->im.z * e->im.z < 4 && iter < e->maxiter)
	{
		e->re.sqz = e->re.z * e->re.z;
		e->im.sqz = e->im.z * e->im.z;
		if (e->type == MANDELBRAT)
			e->im.z *= -1;
		e->im.z = 2 * e->im.z * e->re.z + e->im.c;
		e->re.z = e->re.sqz - e->im.sqz + e->re.c;
		iter++;
	}
	put_color(e, x, y, iter);
}

static void	julialoop(t_env *e, int x, int y)
{
	int iter;

	e->re.z = (double)x / (WIN_L / (e->re.max - e->re.min)) + e->re.min;
	e->im.z = (double)y / (WIN_H / (e->im.max - e->im.min)) + e->im.min;
	iter = 0;
	while (e->re.z * e->re.z + e->im.z * e->im.z < 4 && iter < e->maxiter)
	{
		e->re.sqz = e->re.z * e->re.z;
		e->im.sqz = e->im.z * e->im.z;
		if (e->type == JULIABRAT)
			e->im.z *= -1;
		e->im.z = 2 * e->im.z * e->re.z + e->im.c;
		e->re.z = e->re.sqz - e->im.sqz + e->re.c;
		iter++;
	}
	put_color(e, x, y, iter);
}

static void	shiploop(t_env *e, int x, int y)
{
	int iter;

	e->re.c = (double)x / (WIN_L / (e->re.max - e->re.min)) + e->re.min;
	e->im.c = (double)y / (WIN_H / (e->im.max - e->im.min)) + e->im.min;
	e->re.z = 0;
	e->im.z = 0;
	iter = 0;
	while (e->re.z * e->re.z + e->im.z * e->im.z <= 10 && iter < e->maxiter)
	{
		e->re.sqz = e->re.z * e->re.z;
		e->im.sqz = e->im.z * e->im.z;
		e->im.z = 2 * fabs(e->re.z * e->im.z) - e->im.c;
		e->re.z = e->re.sqz - e->im.sqz - e->re.c;
		iter++;
	}
	put_color(e, x, y, iter);
}

static void	bjulialoop(t_env *e, int x, int y)
{
	int iter;

	e->re.z = (double)x / (WIN_L / (e->re.max - e->re.min)) + e->re.min;
	e->im.z = (double)y / (WIN_H / (e->im.max - e->im.min)) + e->im.min;
	iter = 0;
	while (e->re.z * e->re.z + e->im.z * e->im.z <= 10 && iter < e->maxiter)
	{
		e->re.sqz = e->re.z * e->re.z;
		e->im.sqz = e->im.z * e->im.z;
		e->im.z = 2 * fabs(e->re.z * e->im.z) - e->im.c;
		e->re.z = e->re.sqz - e->im.sqz - e->re.c;
		iter++;
	}
	put_color(e, x, y, iter);
}

void		fractal(t_env *e)
{
	int x;
	int y;

	y = 0;
	makepalette(e);
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_L)
		{
			if (e->type == MANDELBROT || e->type == MANDELBRAT)
				mandeloop(e, x, y);
			else if (e->type == JULIA || e->type == JULIABRAT)
				julialoop(e, x, y);
			else if (e->type == BURNINGSHIP)
				shiploop(e, x, y);
			else if (e->type == BURNINGJULIA)
				bjulialoop(e, x, y);
			x++;
		}
		y++;
	}
}
