/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:49:19 by caida-si          #+#    #+#             */
/*   Updated: 2026/03/27 14:40:42 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	cleanup_textures(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (i < TEX_COUNT)
	{
		if (cub->tex[i].img && cub->mlx)
			mlx_destroy_image(cub->mlx, cub->tex[i].img);
		cub->tex[i].img = NULL;
		if (cub->parse.tex_paths[i])
			free(cub->parse.tex_paths[i]);
		cub->parse.tex_paths[i] = NULL;
		i++;
	}
}

static void	cleanup_mlx(t_cub3d *cub)
{
	if (cub->img.img && cub->mlx)
		mlx_destroy_image(cub->mlx, cub->img.img);
	cub->img.img = NULL;
	if (cub->win && cub->mlx)
		mlx_destroy_window(cub->mlx, cub->win);
	cub->win = NULL;
	if (cub->mlx)
	{
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
	cub->mlx = NULL;
}

void	cleanup(t_cub3d *cub)
{
	if (!cub)
		return ;
	cleanup_game_objects(cub);
	cleanup_target_textures(cub);
	cleanup_weapon(cub);
	cleanup_textures(cub);
	free_array(cub->map.grid);
	cub->map.grid = NULL;
	cleanup_mlx(cub);
}
