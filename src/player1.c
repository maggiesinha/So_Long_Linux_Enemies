/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:28:46 by mvalerio          #+#    #+#             */
/*   Updated: 2023/11/06 11:49:46 by mvalerio         ###   ########.fr       */
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

void	ft_eat_collectible(params *pms)
{
	pms->collectibles--;
	pms->map[pms->p_next_y][pms->p_next_x] = '0';
	pms->map[pms->p_y][pms->p_x] = '0';
	pms->map[pms->p_next_y][pms->p_next_x] = 'P';
}

void	ft_set_player_frames(params *pms)
{
	ft_key_up(pms);
	ft_key_down(pms);
	ft_key_left(pms);
	ft_key_right(pms);

	if (pms->map[pms->p_next_y][pms->p_next_x] == 'E' && pms->collectibles == 0)
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->bckg->img, pms->p_x * S, pms->p_y * S);
		ft_win(pms, pms->p_next_x, pms->p_next_y);
	}
	else if (pms->map[pms->p_next_y][pms->p_next_x] == 'C')
		ft_eat_collectible(pms);
	else if (pms->map[pms->p_next_y][pms->p_next_x] == 'E' || pms->map[pms->p_next_y][pms->p_next_x] == 'B' || pms->map[pms->p_next_y][pms->p_next_x] == '1')
	{
		pms->p_next_x = pms->p_x;
		pms->p_next_y = pms->p_y;
		pms->p_i_xsignal = 0;
		pms->p_i_ysignal = 0;
	}
	else
	{
		pms->map[pms->p_y][pms->p_x] = '0';
		pms->map[pms->p_next_y][pms->p_next_x] = 'P';
	}
}
