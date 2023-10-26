/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:28:46 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/26 11:50:43 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	ft_put_player(params *pms, size_t x, size_t y)
{
	if (pms->player_state == UP)
		mlx_put_image_to_window(pms->game, \
			pms->win, pms->all->btfly_pu->img, x * S, y * S);
	if (pms->player_state == DOWN)
		mlx_put_image_to_window(pms->game, \
			pms->win, pms->all->btfly_pd->img, x * S, y * S);
	if (pms->player_state == LEFT)
		mlx_put_image_to_window(pms->game, \
			pms->win, pms->all->btfly_pl->img, x * S, y * S);
	if (pms->player_state == RIGHT)
		mlx_put_image_to_window(pms->game, \
			pms->win, pms->all->btfly_pr->img, x * S, y * S);
}

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
