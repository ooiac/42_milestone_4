/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:48:52 by caida-si          #+#    #+#             */
/*   Updated: 2026/03/27 14:38:09 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press(int keycode, t_cub3d *cub)
{
	if (keycode == KEY_ESC)
		close_window(cub);
	if (keycode == KEY_LEFT)
		cub->key_left = 1;
	else if (keycode == KEY_RIGHT)
		cub->key_right = 1;
	else if (keycode >= 0 && keycode < 256)
		cub->keys[keycode] = 1;
	return (0);
}

int	key_release(int keycode, t_cub3d *cub)
{
	if (keycode == KEY_LEFT)
		cub->key_left = 0;
	else if (keycode == KEY_RIGHT)
		cub->key_right = 0;
	else if (keycode >= 0 && keycode < 256)
		cub->keys[keycode] = 0;
	return (0);
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
	process_movement(cub);
	process_rotation(cub);
}
