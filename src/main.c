/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	errors(int error)
{
	if (error == NOTFRACTAL)
	{
		ft_putstr_fd("Inputed fractal is not available yet, \
currently available:\n-mandelbrot     -mandelbrat\n-julia    \
	-juliabrat\n-burningship    -burningjulia\n", 2);
		exit(2);
	}
	if (error == 1)
	{
		ft_putstr_fd("Please input one Fractal among:\n-mandelbrot\
	-mandelbrat\n-julia       \
	-juliabrat\n-burningship    -burningjulia\n", 2);
		exit(2);
	}
	if (error == 2)
	{
		ft_putstr_fd("At the moment, Fractol can only process \
one fractal among:\n-mandelbrot     -mandelbrat\n-julia          \
-juliabrat\n-burningship    -burningjulia\n", 2);
		exit(2);
	}
}

int		expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	fill_image(e, BLACK);
	fractal(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	if (e->hidemenu == 0)
	{
		display_menu(e);
		display_data(e);
	}
	return (0);
}

void	env_init(t_env *e)
{
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
	e->maxiter = MAXITER;
	e->re.c = REC;
	e->im.c = IMC;
	e->zoomfactor = ZOOMFACTOR;
	e->hidemenu = 0;
	e->palette = MOEBIUS;
	e->autozoom = 0;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_L, WIN_H, "FRACTOL");
	e->img_ptr = mlx_new_image(e->mlx, WIN_L, WIN_H);
	e->img = mlx_get_data_addr(e->img_ptr, &e->bits_per_pixel, \
	&e->size_line, &e->endian);
}

void	checktype(char *av, t_env *e)
{
	e->stopmoving = 1;
	e->type = NOTFRACTAL;
	if (ft_strcmp(av, "mandelbrot") == 0)
		e->type = MANDELBROT;
	if (ft_strcmp(av, "mandelbrat") == 0)
		e->type = MANDELBRAT;
	if (ft_strcmp(av, "julia") == 0)
		e->type = JULIA;
	if (ft_strcmp(av, "juliabrat") == 0)
		e->type = JULIABRAT;
	if (ft_strcmp(av, "burningship") == 0)
		e->type = BURNINGSHIP;
	if (ft_strcmp(av, "burningjulia") == 0)
		e->type = BURNINGJULIA;
	if (e->type == NOTFRACTAL)
		errors(NOTFRACTAL);
	if (e->type > 3)
		e->stopmoving = 0;
}

int		main(int ac, char **av)
{
	t_env e;

	if (ac == 2 && av[1])
	{
		checktype(av[1], &e);
		env_init(&e);
		mlx_key_hook(e.win, key_hook, &e);
		mlx_mouse_hook(e.win, mouse_hook, &e);
		mlx_hook(e.win, 6, 64, &mouse_move, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop(e.mlx);
	}
	else if (ac == 1)
		errors(NOARG);
	else
		errors(TOOMANYARG);
	return (0);
}
