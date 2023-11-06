/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:28:46 by mvalerio          #+#    #+#             */
/*   Updated: 2023/11/06 11:50:59 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

size_t	ft_find_player_x(char **map)
{
	size_t	i[2];

	i[0] = 0;
	while ((map)[i[0]])
	{
		i[1] = 0;
		while ((map)[i[0]][i[1]])
		{
			if ((map)[i[0]][i[1]] == 'P')
				return (i[1]);
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}

size_t	ft_find_player_y(char **map)
{
	size_t	i[2];

	i[0] = 0;
	while ((map)[i[0]])
	{
		i[1] = 0;
		while ((map)[i[0]][i[1]])
		{
			if ((map)[i[0]][i[1]] == 'P')
				return (i[0]);
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}

void	ft_print_moves(params *pms)
{
	static int	moves = 0;
	char		*move_count;

	mlx_put_image_to_window(pms->game, pms->win, \
	(pms->all)->moves->img, 15, 15);
	moves++;
	move_count = ft_itoa(moves);
	mlx_string_put(pms->game, pms->win, 35, 45, 0xffffff, move_count);
	free (move_count);
}
