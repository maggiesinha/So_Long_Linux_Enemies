/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:37:13 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/26 12:10:53 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

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
	ft_print_moves(pms);
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
	ft_print_moves(pms);
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
	ft_print_moves(pms);
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
	ft_print_moves(pms);
}
