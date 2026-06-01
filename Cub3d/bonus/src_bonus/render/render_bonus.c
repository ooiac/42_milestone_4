/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:52:14 by caida-si          #+#    #+#             */
/*   Updated: 2026/03/27 14:38:09 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	game_loop(t_cub3d *cub)
{
	process_input(cub);
	update_doors(cub);
	update_weapon(cub);
	draw_floor_ceiling(cub);
	raycast(cub);
	render_sprites(cub, cub->z_buffer);
	draw_minimap(cub);
	draw_weapon(cub);
	draw_crosshair(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	draw_score(cub);
	return (0);
}
