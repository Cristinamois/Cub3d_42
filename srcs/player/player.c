/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:39:58 by gchopin           #+#    #+#             */
/*   Updated: 2022/04/11 09:56:23 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	init_player(t_map *map)
{
	t_control	control;

	control.forward = 0;
	control.backward = 0;
	control.ss_left = 0;
	control.ss_right = 0;
	control.t_left = 0;
	control.t_right = 0;
	map->control = control;
	map->player.fill_x = 0;
	map->player.fill_y = 0;
	map->player.pos_x = 0;
	map->player.pos_y = 0;
	map->player.degree = 0.000000;
	map->player.degree_raycast = 0.000000;
	map->player.ray_horizontal.length_case_x = 0;
	map->player.ray_horizontal.length_case_y = 0;
	map->player.ray_horizontal.is_wall = 0;
	map->player.ray_vertical.is_wall = 0;
	map->player.bottom_wall = 0;
	map->player.height_wall = 0;
}

int	close_program_key(int keycode, void *param, char *message, int msg_number)
{
	int		i;
	t_map	*map;

	i = 0;
	map = (t_map *)param;
	if ((keycode == 65307) && message)
	{
		close_program_ok(map, message, msg_number);
		exit(0);
		return (0);
	}
	return (0);
}

int	search_player(t_map *map, char **lines, int i)
{
	int		j;

	if (lines && *lines)
	{
		while (lines[i])
		{
			j = -1;
			while (lines[i][++j] != '\0')
			{
				if (lines[i][j] == 'N' || lines[i][j] == 'S'
					|| lines[i][j] == 'E' || lines[i][j] == 'W')
				{
					map->player_exist++;
					map->player.pos_y = (double)i + 0.500000;
					map->player.pos_x = (double)j + 0.500000;
					map->player.fill_y = i;
					map->player.fill_x = j;
				}
			}
			i++;
		}
	}
	if (map->player_exist != 1)
		close_program_gnl(map, "No player in the map, or too much.\n", 2);
	return (1);
}

int	control_press(int keycode, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keycode == 'w')
		map->control.forward = 1;
	if (keycode == 115)
		map->control.backward = 1;
	if (keycode == 97)
		map->control.ss_left = 1;
	if (keycode == 100)
		map->control.ss_right = 1;
	if (keycode == 65361)
		map->control.t_left = 1;
	if (keycode == 65363)
		map->control.t_right = 1;
	if (keycode == 65307)
		close_program_key(keycode, map, "Closed OK.\n", 1);
	return (0);
}

int	control_release(int keycode, void *param)
{
	t_map		*map;
	t_control	*control;

	map = (t_map *)param;
	control = &map->control;
	if (keycode == 'w')
		control->forward = 0;
	if (keycode == 115)
		control->backward = 0;
	if (keycode == 97)
		control->ss_left = 0;
	if (keycode == 100)
		control->ss_right = 0;
	if (keycode == 65361)
		control->t_left = 0;
	if (keycode == 65363)
		control->t_right = 0;
	return (0);
}
