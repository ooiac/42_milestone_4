/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:48:58 by caida-si          #+#    #+#             */
/*   Updated: 2026/03/27 14:38:09 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	load_single_texture(t_cub3d *cub, int index)
{
	if (!cub->parse.tex_paths[index])
		err_exit(cub, ERR_TEX_PATH);
	cub->tex[index].img = mlx_xpm_file_to_image(cub->mlx,
			cub->parse.tex_paths[index],
			&cub->tex[index].width, &cub->tex[index].height);
	if (!cub->tex[index].img)
		err_exit(cub, ERR_TEX_LOAD);
	cub->tex[index].addr = mlx_get_data_addr(cub->tex[index].img,
			&cub->tex[index].bpp, &cub->tex[index].line_len,
			&cub->tex[index].endian);
	if (!cub->tex[index].addr)
		err_exit(cub, ERR_TEX_LOAD);
}

void	load_textures(t_cub3d *cub)
{
	load_single_texture(cub, TEX_NORTH);
	load_single_texture(cub, TEX_SOUTH);
	load_single_texture(cub, TEX_EAST);
	load_single_texture(cub, TEX_WEST);
}
