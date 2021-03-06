/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 20:58:59 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 20:59:00 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void		scene(t_data *d, t_dmlx *m)
{
	if (m->scene == FRACTOL)
		scene_1_fractol(d, m, -1);
	else if (m->scene == INTRO)
		scene_0_intro(d, m);
	(void)d;
}
