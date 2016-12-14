/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:33:00 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/14 11:36:35 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

int		ascii_init(void);
int		ascii(char *path);

void	mlx_start(t_data *d, t_dmlx *m);
void	ft_music_start(t_data *d, int off);

int		mouseo_hook(int x, int y, t_data *d);
int		keyr_hook(int key, t_data *d);
int		keyp_hook(int key, t_data *d);
int		mousep_hook(int btn, int x, int y, t_data *d);
int		mouser_hook(int btn, int x, int y, t_data *d);

int		loop_hook(t_data *d);
int		loop(char etat);

void	scene(t_data *d, t_dmlx *m);
void	scene_img(t_data *d, t_dmlx *m);

int		itow(void *img, int x, int y, char *name);
void	*mlx_xpmtostruct(t_dmlx *m, t_img *img, char *file);

#endif
