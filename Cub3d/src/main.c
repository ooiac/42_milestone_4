/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:08:02 by smetz             #+#    #+#             */
/*   Updated: 2026/03/27 11:08:04 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	init_mlx(&cub);
	load_textures(&cub);
	setup_hooks(&cub);
	mlx_loop(cub.mlx);
	cleanup(&cub);
	return (0);
}
