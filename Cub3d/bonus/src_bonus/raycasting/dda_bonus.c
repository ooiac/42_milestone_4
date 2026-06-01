/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:11:27 by smetz             #+#    #+#             */
/*   Updated: 2026/03/27 11:11:29 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	calculate_step_and_side_dist(t_cub3d *cub, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (cub->player.pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - cub->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (cub->player.pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - cub->player.pos_y)
			* ray->delta_dist_y;
	}
}

static int	check_hit(t_cub3d *cub, t_ray *ray, int check_door)
{
	char	tile;

	if (ray->map_y < 0 || ray->map_y >= cub->map.height)
		return (1);
	if (ray->map_x < 0
		|| ray->map_x >= (int)ft_strlen(cub->map.grid[ray->map_y]))
		return (1);
	tile = cub->map.grid[ray->map_y][ray->map_x];
	if (tile == '1')
		return (1);
	if (check_door && tile == 'D')
		return (handle_door_hit(cub, ray));
	return (0);
}

static void	step_ray(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

static void	continue_through_door(t_cub3d *cub, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		step_ray(ray);
		if (check_hit(cub, ray, 0))
		{
			save_wall_behind_info(cub, ray);
			ray->hit = 1;
		}
	}
}

void	perform_dda(t_cub3d *cub, t_ray *ray)
{
	ray->has_wall_behind = 0;
	while (ray->hit == 0)
	{
		step_ray(ray);
		if (check_hit(cub, ray, 1))
		{
			if (ray->hit_door)
				continue_through_door(cub, ray);
			else
				ray->hit = 1;
		}
	}
}
