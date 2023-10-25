/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:41:40 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/25 12:28:31 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	ft_win(params *pms, size_t x, size_t y)
{
	mlx_put_image_to_window(pms->game, pms->win, \
	(pms->all)->dying1->img, x * S, y * S);
	mlx_do_sync(pms->game);
	usleep(100000);
	mlx_put_image_to_window(pms->game, pms->win, \
	(pms->all)->dying2->img, x * S, y * S);
	mlx_do_sync(pms->game);
	usleep(100000);
	mlx_put_image_to_window(pms->game, pms->win, \
	(pms->all)->dying3->img, x * S, y * S);
	mlx_do_sync(pms->game);
	usleep(100000);
	mlx_put_image_to_window(pms->game, pms->win, \
	(pms->all)->dying4->img, x * S, y * S);
	mlx_do_sync(pms->game);
	mlx_put_image_to_window(pms->game, pms->win, \
	(pms->all)->dying5->img, x * S, y * S);
	mlx_do_sync(pms->game);
	usleep(100000);
	mlx_put_image_to_window(pms->game, pms->win, \
	(pms->all)->dying6->img, x * S, y * S);
	mlx_do_sync(pms->game);
	usleep(100000);
	mlx_put_image_to_window(pms->game, pms->win, \
	(pms->all)->dying7->img, x * S, y * S);
	mlx_do_sync(pms->game);
	usleep(100000);
	mlx_put_image_to_window(pms->game, pms->win, \
	(pms->all)->dying8->img, x * S, y * S);
	mlx_do_sync(pms->game);
		mlx_put_image_to_window(pms->game, pms->win, \
	(pms->all)->dying9->img, x * S, y * S);
	mlx_do_sync(pms->game);
	usleep(100000);
	mlx_put_image_to_window(pms->game, pms->win, \
	(pms->all)->dying10->img, x * S, y * S);
	mlx_do_sync(pms->game);
	usleep(100000);
}

void	ft_rendering_left(params *pms)
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
		usleep(4000);
	}
	ft_print_moves(pms);
}

void	ft_rendering_right(params *pms)
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
		usleep(4000);
	}
	ft_print_moves(pms);
}

void	ft_move_left(params *pms)
{
	char	*player;
	char	*next;

	pms->p_x = ft_find_player_x(pms->map);
	pms->p_y = ft_find_player_y(pms->map);
	player = &(pms->map)[pms->p_y][pms->p_x];
	next = &((pms->map)[pms->p_y][(pms->p_x) - 1]);
	if (*next == 'E' && pms->collectibles == 0)
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->bckg->img, pms->p_x * S, pms->p_y * S);
		ft_win(pms, pms->p_x - 1, pms->p_y);
		ft_close_window(pms);
	}
	else if (*next == 'C')
		pms->collectibles--;
	if (*next != 'E' && *next != '1')
	{
		*player = '0';
		*next = 'P';
		ft_rendering_left(pms);
	}
	else
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->btfly_pl->img, pms->p_x * S, pms->p_y * S);
	pms->player_state = LEFT;
}

void	ft_move_right(params *pms)
{
	char	*player;
	char	*next;

	pms->p_x = ft_find_player_x(pms->map);
	pms->p_y = ft_find_player_y(pms->map);
	player = &(pms->map)[pms->p_y][pms->p_x];
	next = &((pms->map)[pms->p_y][(pms->p_x) + 1]);
	if (*next == 'E' && pms->collectibles == 0)
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->bckg->img, pms->p_x * S, pms->p_y * S);
		ft_win(pms, pms->p_x + 1, pms->p_y);
		ft_close_window(pms);
	}
	else if (*next == 'C')
		pms->collectibles--;
	if (*next != 'E' && *next != '1')
	{
		*player = '0';
		*next = 'P';
		ft_rendering_right(pms);
	}
	else
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->btfly_pr->img, pms->p_x * S, pms->p_y * S);
	pms->player_state = RIGHT;
}

void	ft_rendering_up(params *pms)
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
		usleep(4000);
	}
	ft_print_moves(pms);
	pms->player_state = UP;
}

void	ft_move_up(params *pms)
{
	char	*player;
	char	*next;

	pms->p_x = ft_find_player_x(pms->map);
	pms->p_y = ft_find_player_y(pms->map);
	player = &(pms->map)[pms->p_y][pms->p_x];
	next = &((pms->map)[pms->p_y - 1][(pms->p_x)]);
	if (*next == 'E' && pms->collectibles == 0)
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->bckg->img, pms->p_x * S, pms->p_y * S);
		ft_win(pms, pms->p_x, pms->p_y - 1);
		ft_close_window(pms);
	}
	else if (*next == 'C')
		pms->collectibles--;
	if (*next != 'E' && *next != '1')
	{
		*player = '0';
		*next = 'P';
		ft_rendering_up(pms);
	}
	else
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->btfly_pu->img, pms->p_x * S, pms->p_y * S);
	pms->player_state = DOWN;
}

void	ft_rendering_down(params *pms)
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
		usleep(4000);
	}
	ft_print_moves(pms);
}

void	ft_move_down(params *pms)
{
	char	*player;
	char	*next;

	pms->p_x = ft_find_player_x(pms->map);
	pms->p_y = ft_find_player_y(pms->map);
	player = &(pms->map)[pms->p_y][pms->p_x];
	next = &((pms->map)[pms->p_y + 1][(pms->p_x)]);
	if (*next == 'B')
		return ;
	if (*next == 'E' && pms->collectibles == 0)
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->bckg->img, pms->p_x * S, pms->p_y * S);
		ft_win(pms, pms->p_x, pms->p_y + 1);
		ft_close_window(pms);
	}
	else if (*next == 'C')
		pms->collectibles--;
	if (*next != 'E' && *next != '1')
	{
		*player = '0';
		*next = 'P';
		ft_rendering_down(pms);
	}
	else
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->btfly_pd->img, pms->p_x * S, pms->p_y * S);
	pms->player_state = DOWN;
}
