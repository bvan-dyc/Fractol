/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:15:22 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/20 19:42:04 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

# define WIN_L			1280
# define WIN_H			720

# define UNICOLOR		0
# define MOEBIUS		1
# define FLASH			2

# define BLACK			0x000000
# define LBLACK			0x1B2631
# define WHITE			0xFFFFFF
# define RED			0xFF5733
# define GREEN			0x28B463
# define PBLUE			0x0000FF
# define BLUE			0x2E86C1
# define YELLOW			0xF1C40F
# define PURPLE			0x7D3C98
# define ORANGE			0xF39C12
# define PINK			0xEC7063

# define WBROWN3		0x421E0F
# define MDVIOLET		0x444877
# define WDBLUE			0x09012F
# define WBLUE5			0x040449
# define WBLUE4			0x000764
# define WBLUE3			0x0C4D8A
# define WBLUE2			0x1852B1
# define WBLUE1			0x397DD1
# define WBLUE0			0x86B5E5
# define WLLBLUE		0xD3ECF8
# define WLYELLOW		0xF8C95F
# define WLLYELLOW		0xF1E9BF
# define WBYELLOW		0xFFAA00
# define WBROWN0		0xCC8000
# define WBROWN1		0x995700
# define WBROWN2		0x6A3403

# define MDDPINK		0x6A5E67
# define WDVIOLET		0x19071A
# define MDDBLUE		0x353C4A
# define MDBLUE			0x42536D
# define MBLUE			0x546896
# define MLBLUE			0x879EBF
# define MLLBLUE		0x8A9EB2
# define MDGREY			0x4B8DB6
# define MGREY			0x7E8B8A
# define MLGREY			0xC0D8D9
# define MLYELLOW		0xEFEB1B
# define MLLYELLOW		0xA7C474
# define MRED			0xC54E1B
# define MLPINK			0xDDCBD0
# define MPINK			0x8D7787
# define MDPINK			0x8A797B

# define PPINK			0xFF00FF
# define PRED			0xFF0000
# define PBLUE			0x0000FF
# define PGREEN			0x00FF00
# define PYELLOW		0xFFFF00
# define PCYAN			0x00FFFF
# define PORANGE		0xFFA500

# define MOUSE_LEFT		1
# define MOUSE_RIGHT	2
# define SCROLL_UP		5
# define SCROLL_DOWN	4

# define KEY_ESC		53
# define KEY_DELETE		51
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_A			0
# define KEY_B			11
# define KEY_D			2
# define KEY_F			3
# define KEY_G			5
# define KEY_H			4
# define KEY_M			46
# define KEY_N			45
# define KEY_I			34
# define KEY_P			35
# define KEY_R			15
# define KEY_S			1
# define KEY_T			17
# define KEY_U			32
# define KEY_W			13
# define KEY_Y			16
# define KEY_PLUS		69
# define KEY_MINUS		78

# define NOTFRACTAL		0
# define TOOMANYARG		1
# define NOARG			2

# define MANDELBROT		1
# define MANDELBRAT		2
# define BURNINGSHIP	3
# define JULIA			4
# define JULIABRAT		5
# define BURNINGJULIA	6

# define MAXITER		100
# define REMIN			-2.2
# define REMAX			2.2
# define IMMIN			-1.1
# define IMMAX			1.1
# define REC			0.286
# define IMC			0.01
# define ZOOMFACTOR		1.5

typedef struct	s_mndl
{
	double		max;
	double		min;
	double		c;
	double		z;
	double		sqz;
}				t_mndl;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			maxiter;
	double		length;
	double		height;
	double		zoomfactor;
	t_mndl		re;
	t_mndl		im;
	int			inc;
	int			type;
	int			autozoom;
	int			hidemenu;
	int			stopmoving;
	int			palette;
	int			palet[16];
	void		*img_ptr;
	char		*img;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_env;

void			pixel_put(t_env *e, int x, int y, int color);
int				key_hook(int keycode, t_env *e);
void			fill_image(t_env *e, int color);
void			pixel_put(t_env *e, int x, int y, int color);
int				expose_hook(t_env *e);
unsigned long	convert_rgb(int red, int green, int blue);
void			bresenham_line(t_env *e, int x0, int y0, int x1, int y1);
void			display_data(t_env *e);
void			display_menu(t_env *e);
void			mandelbrot(t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
void			fractal(t_env *e);
int				mouse_move(int x, int y, t_env *e);
void			put_color(t_env *e, int x, int y, int iter);
void			makepalette(t_env *e);

#endif
