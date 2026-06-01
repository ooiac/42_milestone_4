/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:14:31 by smetz             #+#    #+#             */
/*   Updated: 2026/03/27 11:18:51 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	draw_weapon_row(t_cub3d *cub, t_tex *tex, int *pos, int y)
{
	int	x;
	int	color;

	x = 0;
	while (x < tex->width)
	{
		color = get_texture_color(tex, x, y);
		if (!is_transparent(color))
			put_pixel(&cub->img, pos[0] + x, pos[1] + y, color);
		x++;
	}
}

void	draw_weapon(t_cub3d *cub)
{
	int		y;
	int		pos[2];
	t_tex	*current;

	current = &cub->weapon.sprites[cub->weapon.current_frame];
	if (!current->img)
		return ;
	pos[0] = (WIN_WIDTH - current->width) / 2 + cub->weapon.bob_x;
	pos[1] = WIN_HEIGHT - current->height + cub->weapon.bob_y;
	y = 0;
	while (y < current->height)
	{
		draw_weapon_row(cub, current, pos, y);
		y++;
	}
}
