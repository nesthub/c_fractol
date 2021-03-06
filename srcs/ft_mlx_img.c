/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 20:58:02 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 20:58:14 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	*mlx_new_img(t_dmlx *m, t_img *img, int width, int heigh)
{
	img->width = width;
	img->heigh = heigh;
	if (!(img->img)
	&& !(img->img = mlx_new_image(m->mlx, img->width, img->heigh)))
		exit1(1, data(), "Cant load new image file");
	if (!(img->str))
	{
		img->str = mlx_get_data_addr(img->img, &img->bpp, &img->sl, &img->end);
		img->ptr = (int *)img->str;
	}
	return (img->img);
}

void	*mlx_xpmtostruct(t_dmlx *m, t_img *img, char *file)
{
	if (!(img->img) && LOG_XTOI == 1)
		l1(8, "GET XPM IMG", file);
	if (!(img->img)
	&& !(img->img = mlx_xpm_file_to_image(m->mlx, file
												, &img->width, &img->heigh)))
		exit1(1, data(), "Cant load xpm file");
	if (!(img->str) && LOG_XTOI == 1)
		l1(8, "GET XPM STR", file);
	if (!(img->str))
	{
		img->str = mlx_get_data_addr(img->img, &img->bpp, &img->sl, &img->end);
		img->ptr = (int *)img->str;
	}
	return (img->img);
}

int		itow(void *img, int x, int y, char *name)
{
	t_data	*d;

	d = data();
	if (LOG_ITOW == 1)
		l1(3, "IMG TO WINDOW", name);
	if (!mlx_put_image_to_window(d->mlx.mlx, d->mlx.win, img, x, y))
		exit1(1, d, "Cant put image to windows");
	return (1);
}
