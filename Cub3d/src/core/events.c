/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:48:41 by caida-si          #+#    #+#             */
/*   Updated: 2026/03/27 14:38:09 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_window(t_cub3d *cub)
{
	cleanup(cub);
	exit(0);
	return (0);
}

void	setup_hooks(t_cub3d *cub)
{
	if (!cub || !cub->win)
		return ;
	mlx_hook(cub->win, X_EVENT_KEY_PRESS, 1L << 0, key_press, cub);
	mlx_hook(cub->win, X_EVENT_KEY_RELEASE, 1L << 1, key_release, cub);
	mlx_hook(cub->win, X_EVENT_DESTROY, 0, close_window, cub);
	mlx_loop_hook(cub->mlx, game_loop, cub);
}
