/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_set_directions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:29:13 by mvalerio          #+#    #+#             */
/*   Updated: 2023/11/07 10:45:10 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	ft_set_frames(t_params *pms)
{
	ft_set_player_frames(pms);
	ft_set_enemy_frames(pms);
}

void	ft_set_enemy_up(t_params *pms, t_enemy *current, size_t x, size_t y)
{
	current->e1_img = pms->all->enemyu1->img;
	current->e2_img = pms->all->enemyu2->img;
	current->e_next_x = current->x;
	current->e_next_y = current->y - 1;
	current->i_xsignal = 0;
	current->i_ysignal = 1;
	current->dir = UP;
	pms->map[y][x] = '0';
	if (pms->map[y - 1][x] == 'P')
		current->kill = 1;
	pms->map[y - 1][x] = 'B';
	ft_map_characters(pms, x, y);
}

void	ft_set_enemy_down(t_params *pms, t_enemy *current, size_t x, size_t y)
{
	current->e1_img = pms->all->enemyd1->img;
	current->e2_img = pms->all->enemyd2->img;
	current->e_next_x = current->x;
	current->e_next_y = current->y + 1;
	current->i_xsignal = 0;
	current->i_ysignal = -1;
	current->dir = DOWN;
	pms->map[y][x] = '0';
	if (pms->map[y + 1][x] == 'P')
		current->kill = 1;
	pms->map[y + 1][x] = 'B';
	ft_map_characters(pms, x, y);
}

void	ft_set_enemy_left(t_params *pms, t_enemy *current, size_t x, size_t y)
{
	current->e1_img = pms->all->enemyl1->img;
	current->e2_img = pms->all->enemyl2->img;
	current->e_next_x = current->x - 1;
	current->e_next_y = current->y;
	current->i_xsignal = 1;
	current->i_ysignal = 0;
	current->dir = LEFT;
	pms->map[y][x] = '0';
	if (pms->map[y][x - 1] == 'P')
		current->kill = 1;
	pms->map[y][x - 1] = 'B';
	ft_map_characters(pms, x, y);
}

void	ft_set_enemy_right(t_params *pms, t_enemy *current, size_t x, size_t y)
{
	current->e1_img = pms->all->enemyr1->img;
	current->e2_img = pms->all->enemyr2->img;
	current->e_next_x = current->x + 1;
	current->e_next_y = current->y;
	current->i_xsignal = -1;
	current->i_ysignal = 0;
	current->dir = RIGHT;
	pms->map[y][x] = '0';
	if (pms->map[y][x + 1] == 'P')
		current->kill = 1;
	pms->map[y][x + 1] = 'B';
	ft_map_characters(pms, x, y);
}
