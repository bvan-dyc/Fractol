/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void	arrow_keys(int keycode, t_env *e)
{
	double range;

	range = e->im.max - e->im.min;
	if (keycode == KEY_UP)
	{
		e->im.min += range / 10;
		e->im.max -= range / 10;
	}
	if (keycode == KEY_DOWN)
	{
		e->im.min -= range / 10;
		e->im.max += range / 10;
	}
	range = e->re.max - e->re.min;
	if (keycode == KEY_LEFT)
	{
		e->re.min += range / 10;
		e->re.max -= range / 10;
	}
	if (keycode == KEY_RIGHT)
	{
		e->re.min -= range / 10;
		e->re.max += range / 10;
	}
}

static void	camera_keys(int keycode, t_env *e)
{
	double range;

	range = e->im.max - e->im.min;
	if (keycode == KEY_W)
	{
		e->im.min -= range / 10;
		e->im.max -= range / 10;
	}
	if (keycode == KEY_S)
	{
		e->im.min += range / 10;
		e->im.max += range / 10;
	}
	range = e->re.max - e->re.min;
	if (keycode == KEY_A)
	{
		e->re.min -= range / 10;
		e->re.max -= range / 10;
	}
	if (keycode == KEY_D)
	{
		e->re.min += range / 10;
		e->re.max += range / 10;
	}
}

static void	letter_keys(int keycode, t_env *e)
{
	if (keycode == KEY_P)
		e->palette = (e->palette == 2 ? 0 : e->palette + 1);
	if (keycode == KEY_PLUS)
		e->zoomfactor = 1 + (e->zoomfactor - 1) * 10;
	if (keycode == KEY_MINUS && e->zoomfactor > 1)
		e->zoomfactor = 1 + (e->zoomfactor - 1) / 10;
	if (keycode == KEY_I)
		e->maxiter += 10;
	if (keycode == KEY_U && e->maxiter >= 10)
		e->maxiter -= 10;
	if (keycode == KEY_H)
		e->hidemenu = (e->hidemenu == 0 ? 1 : 0);
	if (keycode == KEY_M)
		e->stopmoving = (e->stopmoving == 0 ? 1 : 0);
	if (keycode == KEY_R)
	{
		e->re.min *= -1;
		e->re.max *= -1;
	}
}

static void	special_keys(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	if (keycode == KEY_DELETE)
	{
		e->maxiter = MAXITER;
		e->re.min = REMIN;
		e->re.max = REMAX;
		e->im.min = IMMIN;
		e->im.max = IMMAX;
		if (e->type == BURNINGSHIP || e->type == BURNINGJULIA)
		{
			e->re.min = REMAX;
			e->re.max = REMIN;
			e->im.min = IMMAX;
			e->im.max = IMMIN;
		}
		e->re.c = REC;
		e->im.c = IMC;
		e->zoomfactor = ZOOMFACTOR;
	}
}

int			key_hook(int keycode, t_env *e)
{
	camera_keys(keycode, e);
	letter_keys(keycode, e);
	special_keys(keycode, e);
	arrow_keys(keycode, e);
	expose_hook(e);
	return (0);
}
