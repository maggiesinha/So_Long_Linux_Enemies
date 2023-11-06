/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:28:46 by mvalerio          #+#    #+#             */
/*   Updated: 2023/11/06 11:47:35 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"


void	ft_map_characters(params *pms, size_t x, size_t y)
{
	if (pms->map[y][x] == '0')
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		pms->all->bckg->img, x * S, y * S);
		(pms->bckg_n)++;
	}
	if (pms->map[y][x] == '1')
		mlx_put_image_to_window(pms->game, \
			pms->win, pms->all->walls->img, \
		x * S, y * S);
	if (pms->map[y][x] == 'C')
		mlx_put_image_to_window(pms->game, \
			pms->win, pms->all->mush->img, x * S, y * S);
	if (pms->map[y][x] == 'P')
		ft_put_player(pms, x, y);
	if (pms->map[y][x] == 'E')
		mlx_put_image_to_window(pms->game, \
			pms->win, pms->all->exit->img, x * S, y * S);
	if (pms->map[y][x] == 'B')
		mlx_put_image_to_window(pms->game, \
			pms->win, pms->all->enemyr1->img, x * S, y * S);
}

int	ft_map_to_screen(char **map, params *pms)
{
	size_t	x;
	size_t	y;

	pms->bckg_n = 0;
	y = 0;
	pms->all = ft_build_all_images(pms);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_map_characters(pms, x, y);
			x++;
		}
		y++;
	}
	pms->m_width = ft_strlen(map[0]);
	pms->m_height = ft_arraylen(map);
	return (0);
}
int	ft_check_walls_around(char **map)
{
	int i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[ft_arraylen(map) - 1][i])
	{
		if (map[ft_arraylen(map) - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if ((map[i][0] != '1') || (map[i][ft_strlen(map[0]) - 1] != '1'))
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_map_height(char	*map[])
{
	size_t	i;
	size_t	compare;

	i = 0;
	compare = ft_strlen(map[i]);
	while (map[i])
	{
		if	(ft_strlen(map[i]) != compare)
			return (0);
		i++;
	}
	return (i);
}
