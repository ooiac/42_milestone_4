/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:09:54 by smetz             #+#    #+#             */
/*   Updated: 2026/03/27 11:09:56 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	main(int argc, char **argv)
{
	t_cub3d	cub;

	if (argc != 2)
	{
		err_msg(ERR_ARGS);
		return (1);
	}
	init_cub(&cub);
	parse_file(&cub, argv[1]);
	validate_elements(&cub);
	validate_map(&cub);
	extract_player(&cub);
	init_mlx(&cub);
	load_textures(&cub);
	load_target_textures(&cub);
	load_weapon_sprite(&cub);
	init_player(&cub);
	init_doors(&cub);
	init_targets(&cub);
	setup_hooks(&cub);
	mlx_loop(cub.mlx);
	cleanup(&cub);
	return (0);
}
