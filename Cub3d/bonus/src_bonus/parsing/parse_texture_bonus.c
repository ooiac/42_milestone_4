/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:50:27 by caida-si          #+#    #+#             */
/*   Updated: 2026/03/27 14:37:41 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	parse_texture(t_cub3d *cub, char *line, int tex_index)
{
	char	*path;

	if (cub->parse.tex_paths[tex_index])
		err_exit(cub, ERR_DUP_ELEMENT);
	path = trim_spaces(line);
	if (!path || *path == '\0')
		err_exit(cub, ERR_TEX_PATH);
	cub->parse.tex_paths[tex_index] = ft_strdup(path);
	if (!cub->parse.tex_paths[tex_index])
		err_exit(cub, ERR_MALLOC);
}
