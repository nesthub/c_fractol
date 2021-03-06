/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_1_fractol_draw.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 00:40:00 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/28 02:51:10 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void		fractal_move(t_fract *param)
{
	t_data	*d;

	d = data();
	if (d->mlx.input.left)
	{
		param->top.r += MOVE_VALUE;
		param->bot.r += MOVE_VALUE;
	}
	if (d->mlx.input.right)
	{
		param->top.r -= MOVE_VALUE;
		param->bot.r -= MOVE_VALUE;
	}
	if (d->mlx.input.up)
	{
		param->top.i += MOVE_VALUE;
		param->bot.i += MOVE_VALUE;
	}
	if (d->mlx.input.down)
	{
		param->top.i -= MOVE_VALUE;
		param->bot.i -= MOVE_VALUE;
	}
}

static void	put_pixel(t_img *lay, t_fract *param, t_fract *f)
{
	if (f->ite >= param->itemin && f->ite <= param->itemax)
		lay->ptr[f->i] = 0x00000000 + (f->ite * 1000);
	else
		lay->ptr[f->i] = 0x00000000 + (f->ite * 10);
}

void		scene_1_draw_mandelbrot(t_img *lay, t_fract *param, t_fract *f)
{
	f->pos.r = f->i % data()->mlx.winx;
	f->pos.i = f->i / data()->mlx.winx;
	f->c.r = (f->pos.r / data()->mlx.winx) * param->delta.r * param->zoom
	+ param->top.r * param->zoom;
	f->c.i = (f->pos.i / data()->mlx.winy) * param->delta.i * param->zoom
	+ param->top.i * param->zoom;
	f->z.r = 0;
	f->z.i = 0;
	f->ite = 0;
	while (f->z.r * f->z.r + f->z.i * f->z.i < 4 && f->ite < param->itemax)
	{
		f->z = comp_add(comp_sqr(f->z), f->c);
		f->ite++;
	}
	put_pixel(lay, param, f);
}

void		scene_1_draw_julia(t_img *lay, t_fract *param, t_fract *f)
{
	f->pos.r = f->i % data()->mlx.winx;
	f->pos.i = f->i / data()->mlx.winx;
	f->z.r = (f->pos.r / data()->mlx.winx) * param->delta.r * param->zoom
	+ param->top.r * param->zoom;
	f->z.i = (f->pos.i / data()->mlx.winy) * param->delta.i * param->zoom
	+ param->top.i * param->zoom;
	f->ite = 0;
	while (f->z.r * f->z.r + f->z.i * f->z.i < 4 && f->ite < param->itemax
	&& f->dist.r < 1e10 && f->dist.i < 1e10)
	{
		f->z = comp_add(comp_sqr(f->z), f->c);
		f->old_z.r = 2.0 * (f->z.r * f->old_z.r - f->z.i * f->old_z.i);
		f->old_z.i = 2.0 * (f->z.i * f->old_z.r - f->z.r * f->old_z.i);
		f->dist.r = f->z.r * f->z.r * f->z.i * f->z.i;
		f->dist.i = f->old_z.r * f->old_z.r * f->old_z.i * f->old_z.i;
		f->ite++;
	}
	put_pixel(lay, param, f);
}

void		scene_1_draw_third(t_img *lay, t_fract *param, t_fract *f)
{
	f->pos.r = f->i % data()->mlx.winx;
	f->pos.i = f->i / data()->mlx.winx;
	f->c.r = (f->pos.r / data()->mlx.winx) * param->delta.r * param->zoom
	+ param->top.r * param->zoom;
	f->c.i = (f->pos.i / data()->mlx.winy) * param->delta.i * param->zoom
	+ param->top.i * param->zoom;
	f->z.r = 0;
	f->z.i = 0;
	f->ite = 0;
	while (f->z.r * f->z.r + f->z.i * f->z.i < 4 && f->ite < param->itemax)
	{
		f->z.r = FABS(f->z.r);
		f->z.i = FABS(f->z.i);
		f->z = comp_add(comp_sqr(f->z), f->c);
		f->ite++;
	}
	put_pixel(lay, param, f);
}
