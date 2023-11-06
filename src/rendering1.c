/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:24:00 by mvalerio          #+#    #+#             */
/*   Updated: 2023/11/06 12:23:49 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	ft_render1(params *pms, int i)
{
	enemy *current;

	mlx_put_image_to_window(pms->game, pms->win, \
	pms->p4_img, (pms->p_next_x * S) + i * pms->p_i_xsignal, pms->p_next_y * S + i * pms->p_i_ysignal);
		if (pms->enemies_n > 0)
		{
			current = pms->enemy_list->head;
			while (current)
			{
				mlx_put_image_to_window(pms->game, pms->win, \
				(pms->all)->bckg->img, current->x * S, current->y * S);
				mlx_put_image_to_window(pms->game, pms->win, \
				current->e2_img, current->e_next_x * S + i * current->i_xsignal, current->e_next_y * S + i * current->i_ysignal);
				current = current->next;
			}
		}
	if (pms->p_i_xsignal != 0 || pms->p_i_ysignal != 0)
		pms->moved = 1;
}

void	ft_render2(params *pms, int i)
{
	enemy *current;

	mlx_put_image_to_window(pms->game, pms->win, \
	pms->p3_img, (pms->p_next_x * S) + i * pms->p_i_xsignal, \
	pms->p_next_y * S + i * pms->p_i_ysignal);
	if (pms->enemies_n > 0)
	{
		current = pms->enemy_list->head;
		while (current)
		{
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->bckg->img, current->x * S, current->y * S);
			mlx_put_image_to_window(pms->game, pms->win, \
			current->e2_img, current->e_next_x * S + i * current->i_xsignal,\
			current->e_next_y * S + i * current->i_ysignal);
			current = current->next;
		}
	}
	if (pms->p_i_xsignal != 0 || pms->p_i_ysignal != 0)
		pms->moved = 1;
}
void	ft_render3(params *pms, int i)
{
	enemy *current;

	mlx_put_image_to_window(pms->game, pms->win, \
	pms->p2_img, (pms->p_next_x * S) + i * pms->p_i_xsignal, \
	pms->p_next_y * S + i * pms->p_i_ysignal);
	if (pms->enemies_n > 0)
	{
		current = pms->enemy_list->head;
		while (current)
		{
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->bckg->img, current->x * S, current->y * S);
			mlx_put_image_to_window(pms->game, pms->win, \
			current->e2_img, current->e_next_x * S + i * current->i_xsignal, \
			current->e_next_y * S + i * current->i_ysignal);
			current = current->next;
		}
	}
	if (pms->p_i_xsignal != 0 || pms->p_i_ysignal != 0)
		pms->moved = 1;
}

void	ft_render4(params *pms, int i)
{
	enemy *current;

	mlx_put_image_to_window(pms->game, pms->win, \
	pms->p1_img, (pms->p_next_x * S) + i * pms->p_i_xsignal, \
	pms->p_next_y * S + i * pms->p_i_ysignal);
	if (pms->enemies_n > 0)
	{
		current = pms->enemy_list->head;
		while (current)
		{
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->bckg->img, current->x * S, current->y * S);
			mlx_put_image_to_window(pms->game, pms->win, \
			current->e1_img, current->e_next_x * S + i * current->i_xsignal, \
			current->e_next_y * S + i * current->i_ysignal);
			current = current->next;
		}
	}
	if (pms->p_i_xsignal != 0 || pms->p_i_ysignal != 0)
		pms->moved = 1;
}
void	ft_render_pixel(params *pms, int i)
{
	pms->moved = 0;
	while (i>=0)
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		pms->all->bckg->img, pms->p_x * S, pms->p_y * S);
		if (i >= S / 7 * 3 && i <= S / 7 * 4)
			ft_render1(pms, i);
		else if ((i >= S / 7 * 4 && i <= S / 7 * 5) || (i >= S / 7 * 2 && i <= S / 7 * 3))
			ft_render2(pms, i);
		else if ((i >= S / 7 * 5 && i <= S / 7 * 6) || (i >= S / 7 && i <= S / 7 * 2))
			ft_render3(pms, i);
		else
			ft_render4(pms, i);
		i--;
		mlx_do_sync(pms->game);
		usleep(RENDERING);
	}
}
