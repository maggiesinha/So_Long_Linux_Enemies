/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:25:18 by mvalerio          #+#    #+#             */
/*   Updated: 2023/11/06 12:23:08 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int		ft_rendering (params *pms)
{
	int		i;
	enemy	*current;

	i = S;
	if (pms->key_press == 0)
		return (0);
	pms->p_x = ft_find_player_x(pms->map);
	pms->p_y = ft_find_player_y(pms->map);
	ft_set_player_frames(pms);
	ft_set_enemy_frames(pms);
	ft_render_pixel(pms, i);
	if (pms->enemies_n > 0)
	{
		current = pms->enemy_list->head;
		while (current)
		{
			current->x = current->e_next_x;
			current->y = current->e_next_y;
			if (current->kill)
				ft_death(pms, current);
			current = current->next;
		}
	}
	if (pms->moved)
		ft_print_moves(pms);
	return (0);
}

void	ft_render_p_left(params *pms)
{
	int	i;

	i = S;
	while (i>=0)
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->bckg->img, pms->p_x * S, pms->p_y * S);

		if (i >= S / 7 * 3 && i <= S / 7 * 4)
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->btfly_pl4->img, ((pms->p_x - 1) * S) + i, pms->p_y * S);
		else if ((i >= S / 7 * 4 && i <= S / 7 * 5) || (i >= S / 7 * 2 && i <= S / 7 * 3))
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->btfly_pl3->img, ((pms->p_x - 1) * S) + i, pms->p_y * S);
		else if ((i >= S / 7 * 5 && i <= S / 7 * 6) || (i >= S / 7 && i <= S / 7 * 2))
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->btfly_pl2->img, ((pms->p_x - 1) * S) + i, pms->p_y * S);
		else
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->btfly_pl->img, ((pms->p_x - 1) * S) + i, pms->p_y * S);
		i--;
		mlx_do_sync(pms->game);
		usleep(RENDERING);
	}
}

void	ft_render_p_right(params *pms)
{
	int	i;

	i = S;
	while (i>=0)
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->bckg->img, pms->p_x * S, pms->p_y * S);

		if (i >= S / 7 * 3 && i <= S / 7 * 4)
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->btfly_pr4->img, ((pms->p_x + 1) * S) - i, pms->p_y * S);
		else if ((i >= S / 7 * 4 && i <= S / 7 * 5) || (i >= S / 7 * 2 && i <= S / 7 * 3))
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->btfly_pr3->img, ((pms->p_x + 1) * S) - i, pms->p_y * S);
		else if ((i >= S / 7 * 5 && i <= S / 7 * 6) || (i >= S / 7 && i <= S / 7 * 2))
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->btfly_pr2->img, ((pms->p_x + 1) * S) - i, pms->p_y * S);
		else
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->btfly_pr->img, ((pms->p_x + 1) * S) - i, pms->p_y * S);
		i--;
		mlx_do_sync(pms->game);
		usleep(RENDERING);
	}
}

void	ft_render_p_up(params *pms)
{
	int	i;

	i = S;
	while (i>=0)
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->bckg->img, pms->p_x * S, pms->p_y * S);

		if (i >= S / 7 * 3 && i <= S / 7 * 4)
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->btfly_pu4->img, ((pms->p_x) * S), (pms->p_y - 1) * S + i);
		else if ((i >= S / 7 * 4 && i <= S / 7 * 5) || (i >= S / 7 * 2 && i <= S / 7 * 3))
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->btfly_pu3->img, ((pms->p_x) * S), (pms->p_y - 1) * S + i);
		else if ((i >= S / 7 * 5 && i <= S / 7 * 6) || (i >= S / 7 && i <= S / 7 * 2))
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->btfly_pu2->img, ((pms->p_x) * S), (pms->p_y - 1) * S + i);
		else
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->btfly_pu->img, ((pms->p_x) * S), (pms->p_y - 1) * S + i);
		i--;
		mlx_do_sync(pms->game);
		usleep(RENDERING);
	}
}
void	ft_render_p_down(params *pms)
{
	int	i;

	i = S;
	while (i>=0)
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->bckg->img, pms->p_x * S, pms->p_y * S);

		if (i >= S / 7 * 3 && i <= S / 7 * 4)
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->btfly_pd4->img, ((pms->p_x) * S), (pms->p_y + 1) * S - i);
		else if ((i >= S / 7 * 4 && i <= S / 7 * 5) || (i >= S / 7 * 2 && i <= S / 7 * 3))
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->btfly_pd3->img, ((pms->p_x) * S), (pms->p_y + 1) * S - i);
		else if ((i >= S / 7 * 5 && i <= S / 7 * 6) || (i >= S / 7 && i <= S / 7 * 2))
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->btfly_pd2->img, ((pms->p_x) * S), (pms->p_y + 1) * S - i);
		else
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->btfly_pd->img, ((pms->p_x) * S), (pms->p_y + 1) * S - i);
		i--;
		mlx_do_sync(pms->game);
		usleep(RENDERING);
	}
}
