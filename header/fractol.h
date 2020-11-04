/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 05:18:52 by ahakanen          #+#    #+#             */
/*   Updated: 2020/11/04 12:04:28 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define CPUCORES 4
# define WIN_X 1000
# define WIN_Y 1000
# define MARG 20
# define END 0

# if __APPLE__
#  define LEFT 123
#  define RIGHT 124
#  define UP 126
#  define DOWN 125
#  define PLUS 69
#  define MINUS 78
#  define ESC 53
#  define PSYCH 35
#  define MANDELBROT 18
#  define JULIA 19
#  define MOOSE 20
#  define REDUP 40
#  define REDDOWN 43
#  define GREENUP 37
#  define GREENDOWN 47
#  define BLUEUP 41
#  define BLUEDOWN 44
#  define RESET 15
# endif

# if __linux__
#  define LEFT 65361
#  define RIGHT 65363
#  define UP 65362
#  define DOWN 65364
#  define PLUS 65451
#  define MINUS 65453
#  define ESC 65307
#  define PSYCH 112
#  define MANDELBROT 49
#  define JULIA 50
#  define MOOSE 51
#  define REDUP 107
#  define REDDOWN 44
#  define GREENUP 108
#  define GREENDOWN 46
#  define BLUEUP 59
#  define BLUEDOWN 47
#  define RESET 114
# endif

# include <math.h>
# include <stdlib.h>
# include <pthread.h>
# include "mlx.h"
# include "../libft/includes/libft.h"

typedef struct	s_c
{
	double			r;
	double			i;
}				t_c;

typedef struct	s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
}				t_window;

typedef struct	s_color
{
	int				r;
	int				g;
	int				b;
}				t_color;

typedef struct	s_params
{
	t_window		win;
	int				fractal;
	void			*img;
	char			*img_ptr;
	int				bpp;
	int				size;
	int				endian;
	int				check;
	int				maxiter;
	double			xoff;
	double			yoff;
	t_color			color;
	double			zoom;
	int				active;
	int				mousex;
	int				mousey;
	double			x;
	double			y;
	double			xx;
	double			yy;
	int				i;
	int				j;
	int				fullscreen;
	int				splitsize;
	pthread_mutex_t	mutex;
}				t_params;

typedef struct	s_tparams
{
	t_params		*params;
	int				num;
}				t_tparams;

typedef struct	s_cparams
{
	double			x;
	double			y;
	double			xx;
	double			yy;
	double			tmp;
	t_c				jc;
}				t_cparams;

void			openwindow(int fractal);
void			choosefractal(t_params params);
int				deal_key(int key, void *param);
int				deal_mouse(int button, int x, int y, void *param);
int				deal_mousemove(int x, int y, void *param);
void			psych(t_params *params);
void			psychtoggle(t_params *params);
void			changecolor(int key, t_params *params);
void			resetcolor(t_params *params);
t_c				screentocomplex(int x, int y, t_params params);
void			mandelbrot(t_params params);
void			julia(t_params params);
void			moose(t_params params);

#endif
