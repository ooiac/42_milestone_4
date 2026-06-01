/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_cleared_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:13:24 by smetz             #+#    #+#             */
/*   Updated: 2026/03/27 11:13:28 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	all_targets_cleared(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (i < cub->target_count)
	{
		if (cub->targets[i].state == TARGET_ACTIVE)
			return (0);
		i++;
	}
	return (1);
}
