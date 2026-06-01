/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:50:09 by caida-si          #+#    #+#             */
/*   Updated: 2026/03/27 14:37:41 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	parse_floor_color(t_cub3d *cub, char *line)
{
	if (cub->parse.floor_set)
		err_exit(cub, ERR_DUP_ELEMENT);
	line++;
	cub->floor_color = parse_rgb(cub, line);
	cub->parse.floor_set = 1;
}

void	parse_ceiling_color(t_cub3d *cub, char *line)
{
	if (cub->parse.ceiling_set)
		err_exit(cub, ERR_DUP_ELEMENT);
	line++;
	cub->ceiling_color = parse_rgb(cub, line);
	cub->parse.ceiling_set = 1;
}
