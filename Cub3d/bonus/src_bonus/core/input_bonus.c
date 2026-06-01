/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:49:49 by caida-si          #+#    #+#             */
/*   Updated: 2026/03/27 14:38:09 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	is_moving(t_cub3d *cub)
{
	return (cub->keys[KEY_W] || cub->keys[KEY_S]
		|| cub->keys[KEY_A] || cub->keys[KEY_D]);
}

static void	process_movement(t_cub3d *cub)
{
	if (cub->keys[KEY_W])
		move_forward(cub);
	if (cub->keys[KEY_S])
		move_backward(cub);
	if (cub->keys[KEY_A])
		strafe_left(cub);
	if (cub->keys[KEY_D])
		strafe_right(cub);
}

static void	process_rotation(t_cub3d *cub)
{
	if (cub->key_left)
		rotate_left(cub);
	if (cub->key_right)
		rotate_right(cub);
}

void	process_input(t_cub3d *cub)
{
	cub->weapon.is_walking = is_moving(cub);
	process_movement(cub);
	process_rotation(cub);
}
