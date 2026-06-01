/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:12:01 by smetz             #+#    #+#             */
/*   Updated: 2026/03/27 11:12:04 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static t_tex	*get_door_texture(t_cub3d *cub, t_ray *ray)
{
	int	i;
	int	door_tex_idx;

	i = 0;
	while (i < cub->door_count)
	{
		if (cub->doors[i].x == ray->door_map_x
			&& cub->doors[i].y == ray->door_map_y)
		{
			door_tex_idx = TEX_DOOR_START + cub->doors[i].anim_frame;
			if (cub->tex[door_tex_idx].img)
				return (&cub->tex[door_tex_idx]);
			break ;
		}
		i++;
	}
	return (NULL);
}

t_tex	*get_texture(t_cub3d *cub, t_ray *ray)
{
	t_tex	*tex;

	if (ray->hit_door && ray->map_x == ray->door_map_x
		&& ray->map_y == ray->door_map_y)
	{
		tex = get_door_texture(cub, ray);
		if (tex)
			return (tex);
	}
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (&cub->tex[TEX_EAST]);
		return (&cub->tex[TEX_WEST]);
	}
	if (ray->dir_y > 0)
		return (&cub->tex[TEX_SOUTH]);
	return (&cub->tex[TEX_NORTH]);
}
