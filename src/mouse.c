/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static double	interpolate(double start, double end, double interpolation)
{
	return ((1.0 - interpolation) * start) + (interpolation * end);
}

int				mouse_move(int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && x <= WIN_L && y <= WIN_H && e->stopmoving == 0)
	{
		e->re.c = (double)x / WIN_L * 4 - 2;
		e->im.c = (double)y / WIN_H * 4 - 2;
		expose_hook(e);
	}
	return (1);
}

int				mouse_hook(int button, int x, int y, t_env *e)
{
	double mousere;
	double mouseim;
	double interpolation;

	mousere = (double)x / (WIN_L / (e->re.max - e->re.min)) + e->re.min;
	mouseim = (double)y / (WIN_H / (e->im.max - e->im.min)) + e->im.min;
	if (x > 3 && y > 3 && (button == SCROLL_UP || button == MOUSE_LEFT))
	{
		interpolation = 1.0 / e->zoomfactor;
		e->re.min = interpolate(mousere, e->re.min, interpolation);
		e->im.min = interpolate(mouseim, e->im.min, interpolation);
		e->re.max = interpolate(mousere, e->re.max, interpolation);
		e->im.max = interpolate(mouseim, e->im.max, interpolation);
	}
	if (x > 3 && y > 3 && (button == SCROLL_DOWN || button == MOUSE_RIGHT))
	{
		interpolation = e->zoomfactor;
		e->re.min = interpolate(mousere, e->re.min, interpolation);
		e->im.min = interpolate(mouseim, e->im.min, interpolation);
		e->re.max = interpolate(mousere, e->re.max, interpolation);
		e->im.max = interpolate(mouseim, e->im.max, interpolation);
	}
	expose_hook(e);
	return (0);
}
