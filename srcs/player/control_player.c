/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:39:51 by cmois             #+#    #+#             */
/*   Updated: 2022/04/12 13:39:52 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	move_forward(t_map *map, double sin_degree, double cos_degree)
{
	double	check_pos_y;
	double	check_pos_x;

	check_pos_y = map->player.pos_y;
	check_pos_x = map->player.pos_x;
	if (map->control.forward == 1)
	{
		if (map->lines)
		{
			map->player.pos_y -= sin_degree * 0.050000;
			map->player.pos_x += cos_degree * 0.050000;
		}
	}
}

void	move_backward(t_map *map, double sin_degree, double cos_degree)
{
	double	check_pos_y;
	double	check_pos_x;

	check_pos_y = map->player.pos_y;
	check_pos_x = map->player.pos_x;
	if (map->control.backward == 1)
	{
		if (map->lines)
		{
			map->player.pos_y += sin_degree * 0.050000;
			map->player.pos_x -= cos_degree * 0.050000;
		}
	}
}

void	move_sidestep_left(t_map *map, double sin_degree, double cos_degree)
{
	double	check_pos_y;
	double	check_pos_x;

	check_pos_y = map->player.pos_y;
	check_pos_x = map->player.pos_x;
	if (map->control.ss_left == 1)
	{
		if (map->lines)
		{
			map->player.pos_x -= sin_degree * 0.050000;
			map->player.pos_y -= cos_degree * 0.050000;
		}
	}
}

void	move_sidestep_right(t_map *map, double sin_degree, double cos_degree)
{
	double	check_pos_y;
	double	check_pos_x;

	check_pos_y = map->player.pos_y;
	check_pos_x = map->player.pos_x;
	if (map->control.ss_right == 1)
	{
		if (map->lines)
		{
			map->player.pos_x += sin_degree * 0.050000;
			map->player.pos_y += cos_degree * 0.050000;
		}
	}
}

int	control_player(void *param)
{
	t_map	*map;
	double	sin_degree;
	double	cos_degree;

	map = (t_map *)param;
	sin_degree
		= sin(degree_to_radian(correct_distance(map->player.degree_raycast)));
	cos_degree
		= cos(degree_to_radian(correct_distance(map->player.degree_raycast)));
	move_forward(map, sin_degree, cos_degree);
	move_backward(map, sin_degree, cos_degree);
	move_sidestep_left(map, sin_degree, cos_degree);
	move_sidestep_right(map, sin_degree, cos_degree);
	if (map->control.t_left == 1)
		map->player.degree_raycast
			= correct_distance(map->player.degree_raycast) + 3.000000;
	else if (map->control.t_right == 1)
		map->player.degree_raycast
			= correct_distance(map->player.degree_raycast) - 3.000000;
	return (0);
}
