/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:49:24 by caida-si          #+#    #+#             */
/*   Updated: 2026/03/27 14:38:09 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	cleanup_target_textures(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (cub->target_tex[i].img && cub->mlx)
			mlx_destroy_image(cub->mlx, cub->target_tex[i].img);
		cub->target_tex[i].img = NULL;
		i++;
	}
}

void	cleanup_weapon(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (i < WEAPON_TOTAL_FRAMES)
	{
		if (cub->weapon.sprites[i].img && cub->mlx)
			mlx_destroy_image(cub->mlx, cub->weapon.sprites[i].img);
		cub->weapon.sprites[i].img = NULL;
		i++;
	}
}

void	cleanup_game_objects(t_cub3d *cub)
{
	if (cub->doors)
		free(cub->doors);
	cub->doors = NULL;
	if (cub->targets)
		free(cub->targets);
	cub->targets = NULL;
	if (cub->sprites)
		free(cub->sprites);
	cub->sprites = NULL;
}
