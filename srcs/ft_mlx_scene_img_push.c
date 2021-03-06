/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_scene_img_push.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 04:11:31 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 21:00:30 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void			anim_eval(t_img *img)
{
	if (img->anim_id == FADE_IN && img->fade > 0)
	{
		img->fade -= img->anim_tempo;
		if (img->fade < 0)
			img->fade = 0;
	}
	if (img->anim_id == FADE_OUT && img->fade < 255)
	{
		img->fade += img->anim_tempo;
		if (img->fade > 255)
			img->fade = 255;
	}
}

void			layer_add(t_img *l, t_img *i)
{
	int		*layer;
	int		*img;
	int		x;
	int		y;

	layer = (int *)l->str;
	img = (int *)i->str;
	l->i = (data()->mlx.winx * i->pos[1] + i->pos[0]) - 1;
	y = -1;
	anim_eval(i);
	while (++y < i->heigh)
	{
		x = -1;
		while (++x < i->width)
		{
			i->str[(y * i->width + x) * 4 + 3] = i->fade;
			layer[++(l->i)] = img[y * i->width + x];
		}
		l->i = l->i - i->width + data()->mlx.winx;
	}
}

void			scene_img_push(t_data *d, t_dmlx *m, int i, t_img *img)
{
	img = layer(1, 1);
	while (m->scene_img[m->scene][++i].img)
		if (m->scene_img[m->scene][i].status == 0)
			layer_add(img, &m->scene_img[m->scene][i]);
	(void)d;
}
