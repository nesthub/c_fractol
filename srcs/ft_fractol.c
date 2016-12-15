/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:33:11 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/14 10:56:42 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int			main(int argc, char **argv)
{
	t_data	*d;

	(void)argc;
	(void)argv;

	d = data();
	d->sound = 1;
	d->console = 1;
	if (d->console)
	{
		ascii(ASC_LOGO);
		ascii(ASC_INIT);
		ascii_init();
		ascii(ASC_LOG);
	}
	mlx_start(d, &d->mlx);
	return (0);
}