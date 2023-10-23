/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:28:46 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/23 13:21:16 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"



void	ft_map_characters(params *pms, pictures *all, char character, size_t *i)
{
	if (character == '0')
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		all->bckg->img, i[1] * S, i[0] * S);
		(pms->bckg_n)++;
	}
	if (character == '1')
		mlx_put_image_to_window(pms->game, \
			pms->win, all->walls->img, \
		i[1] * S, i[0] * S);
	if (character == 'C')
		mlx_put_image_to_window(pms->game, \
			pms->win, all->mush->img, i[1] * S, i[0] * S);
	if (character == 'P')
		mlx_put_image_to_window(pms->game, \
			pms->win, all->btfly_pr->img, i[1] * S, i[0] * S);
	if (character == 'E')
		mlx_put_image_to_window(pms->game, \
			pms->win, all->exit->img, i[1] * S, i[0] * S);
}

int	ft_map_to_screen(char **map, params *pms)
{
	size_t	*i;

	pms->bckg_n = 0;
	pms->all = ft_build_all_images(pms);
	i = malloc(sizeof(size_t) * 2);
	if (!i)
		return (1);
	i[0] = 0;
	while (map[i[0]])
	{
		i[1] = 0;
		while (map[i[0]][i[1]])
		{
			ft_map_characters(pms, pms->all, map[i[0]][i[1]], i);
			i[1]++;
		}
		i[0]++;
	}
	free (i);
	pms->m_width = ft_strlen(map[0]);
	pms->m_height = ft_arraylen(map);
	return (0);
}
