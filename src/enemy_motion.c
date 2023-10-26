/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:33:14 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/26 13:21:36 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	ft_player_move(params *pms)
{
	if (pms->key_press == UP)
		ft_move_up(pms);
	else if (pms->key_press == DOWN)
		ft_move_down(pms);
	else if (pms->key_press == LEFT)
		ft_move_left(pms);
	else if (pms->key_press == RIGHT)
		ft_move_right(pms);
}

void	ft_death(params *pms, enemy* current)
{
	if (pms->map[current->y][current->x] == 'P')
	{
		if (current->dir == UP)
		{
			mlx_put_image_to_window(pms->game, pms->win, pms->all->enemydeath_u->img, current->x * S, current->y * S);
			usleep(250000);
			mlx_do_sync(pms->game);
			mlx_put_image_to_window(pms->game, pms->win, pms->all->enemyu1->img, current->x * S, current->y * S);
			usleep(250000);
			mlx_do_sync(pms->game);
			mlx_put_image_to_window(pms->game, pms->win, pms->all->enemydeath_u->img, current->x * S, current->y * S);
			usleep(250000);
			mlx_do_sync(pms->game);
			mlx_put_image_to_window(pms->game, pms->win, pms->all->enemyu1->img, current->x * S, current->y * S);
			usleep(250000);
			mlx_do_sync(pms->game);

		}
		if (current->dir == DOWN)
		{
			mlx_put_image_to_window(pms->game, pms->win, pms->all->enemydeath_d->img, current->x * S, current->y * S);
			usleep(250000);
			mlx_do_sync(pms->game);
			mlx_put_image_to_window(pms->game, pms->win, pms->all->enemyd1->img, current->x * S, current->y * S);
			usleep(250000);
			mlx_do_sync(pms->game);
			mlx_put_image_to_window(pms->game, pms->win, pms->all->enemydeath_d->img, current->x * S, current->y * S);
			usleep(250000);
			mlx_do_sync(pms->game);
			mlx_put_image_to_window(pms->game, pms->win, pms->all->enemyd1->img, current->x * S, current->y * S);
			usleep(250000);
			mlx_do_sync(pms->game);

		}
		if (current->dir == LEFT)
		{
			mlx_put_image_to_window(pms->game, pms->win, pms->all->enemydeath_l->img, current->x * S, current->y * S);
			usleep(250000);
			mlx_do_sync(pms->game);
			mlx_put_image_to_window(pms->game, pms->win, pms->all->enemyl1->img, current->x * S, current->y * S);
			usleep(250000);
			mlx_do_sync(pms->game);
			mlx_put_image_to_window(pms->game, pms->win, pms->all->enemydeath_l->img, current->x * S, current->y * S);
			usleep(250000);
			mlx_do_sync(pms->game);
			mlx_put_image_to_window(pms->game, pms->win, pms->all->enemyl1->img, current->x * S, current->y * S);
			usleep(250000);
			mlx_do_sync(pms->game);

		}
		if (current->dir == RIGHT)
		{
			mlx_put_image_to_window(pms->game, pms->win, pms->all->enemydeath_r->img, current->x * S, current->y * S);
			usleep(250000);
			mlx_do_sync(pms->game);
			mlx_put_image_to_window(pms->game, pms->win, pms->all->enemyr1->img, current->x * S, current->y * S);
			usleep(250000);
			mlx_do_sync(pms->game);
			mlx_put_image_to_window(pms->game, pms->win, pms->all->enemydeath_r->img, current->x * S, current->y * S);
			usleep(250000);
			mlx_do_sync(pms->game);
			mlx_put_image_to_window(pms->game, pms->win, pms->all->enemyr1->img, current->x * S, current->y * S);
			usleep(250000);
			mlx_do_sync(pms->game);

		}
		ft_close_window(pms);
	}
}

int		ft_motion(params *pms)
{
	enemy	*current;
	int		dir;
	size_t	x;
	size_t	y;

	// Enemy Moving
	if (pms->enemies_n > 0)
	{
		current = pms->enemy_list->head;
		while (current)
		{
			x = current->x;
			y = current->y;
			dir = rand() % 4 + 1;
			if (dir == UP && (pms->map[y - 1][x] == '0' || pms->map[y - 1][x] == 'P'))
			{
				current->dir = UP;
				ft_render_e_up(pms, x, y);
				current->y = y - 1;
				ft_death(pms, current);
				pms->map[y][x] = '0';
				pms->map[y - 1][x] = 'B';
				ft_map_characters(pms, x, y);
			}
			else if (dir == DOWN && (pms->map[y + 1][x] == '0' || pms->map[y + 1][x] == 'P'))
			{
				current->dir = DOWN;
				ft_render_e_down(pms, x, y);
				current->y = y + 1;
				ft_death(pms, current);
				pms->map[y][x] = '0';
				pms->map[y + 1][x] = 'B';
				ft_map_characters(pms, x, y);
			}
			else if (dir == LEFT && (pms->map[current->y][x - 1] == '0' || pms->map[current->y][x - 1] == 'P'))
			{
				current->dir = LEFT;
				ft_render_e_left(pms, x, y);
				current->x = x - 1;
				ft_death(pms, current);
				pms->map[y][x] = '0';
				pms->map[y][x - 1] = 'B';
				ft_map_characters(pms, x, y);
			}
			else if (dir == RIGHT && (pms->map[current->y][x + 1] == '0' || pms->map[current->y][x + 1] == 'P' ))
			{
				current->dir = RIGHT;
				ft_render_e_right(pms, x, y);
				current->x = x + 1;
				ft_death(pms, current);
				pms->map[y][x] = '0';
				pms->map[y][x + 1] = 'B';
				ft_map_characters(pms, x, y);
			}
			else
				usleep(RENDERING * S);
			current = current->next;
		}
	}
	ft_player_move(pms);
	mlx_do_sync(pms->game);
	return (0);
}

void	ft_render_e_left(params *pms, size_t x, size_t y)
{
	int	i;

	i = S;
	while (i>=0)
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->bckg->img, x * S, y * S);

		if (i >= S / 7 * 3 && i <= S / 7 * 4)
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->enemyl2->img, ((x - 1) * S) + i, y * S);
		else if ((i >= S / 7 * 4 && i <= S / 7 * 5) || (i >= S / 7 * 2 && i <= S / 7 * 3))
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->enemyl2->img, ((x - 1) * S) + i, y * S);
		else if ((i >= S / 7 * 5 && i <= S / 7 * 6) || (i >= S / 7 && i <= S / 7 * 2))
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->enemyl2->img, ((x - 1) * S) + i, y * S);
		else
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->enemyl1->img, ((x - 1) * S) + i, y * S);
		i--;
		mlx_do_sync(pms->game);
		usleep(RENDERING);
	}
}

void	ft_render_e_right(params *pms, size_t x, size_t y)
{
	int	i;

	i = S;
	while (i>=0)
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->bckg->img, x * S, y * S);

		if (i >= S / 7 * 3 && i <= S / 7 * 4)
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->enemyr2->img, ((x + 1) * S) - i, y * S);
		else if ((i >= S / 7 * 4 && i <= S / 7 * 5) || (i >= S / 7 * 2 && i <= S / 7 * 3))
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->enemyr2->img, ((x + 1) * S) - i, y * S);
		else if ((i >= S / 7 * 5 && i <= S / 7 * 6) || (i >= S / 7 && i <= S / 7 * 2))
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->enemyr2->img, ((x + 1) * S) - i, y * S);
		else
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->enemyr1->img, ((x + 1) * S) - i, y * S);
		i--;
		mlx_do_sync(pms->game);
		usleep(RENDERING);
	}
}

void	ft_render_e_up(params *pms, size_t x, size_t y)
{
	int	i;

	i = S;
	while (i>=0)
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->bckg->img, x * S, y * S);

		if (i >= S / 7 * 3 && i <= S / 7 * 4)
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->enemyu2->img, ((x) * S), (y - 1) * S + i);
		else if ((i >= S / 7 * 4 && i <= S / 7 * 5) || (i >= S / 7 * 2 && i <= S / 7 * 3))
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->enemyu2->img, ((x) * S), (y - 1) * S + i);
		else if ((i >= S / 7 * 5 && i <= S / 7 * 6) || (i >= S / 7 && i <= S / 7 * 2))
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->enemyu2->img, ((x) * S), (y - 1) * S + i);
		else
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->enemyu1->img, ((x) * S), (y - 1) * S + i);
		i--;
		mlx_do_sync(pms->game);
		usleep(RENDERING);
	}
}
void	ft_render_e_down(params *pms, size_t x, size_t y)
{
	int	i;

	i = S;
	while (i>=0)
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->bckg->img, x * S, y * S);

		if (i >= S / 7 * 3 && i <= S / 7 * 4)
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->enemyd2->img, ((x) * S), (y + 1) * S - i);
		else if ((i >= S / 7 * 4 && i <= S / 7 * 5) || (i >= S / 7 * 2 && i <= S / 7 * 3))
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->enemyd2->img, ((x) * S), (y + 1) * S - i);
		else if ((i >= S / 7 * 5 && i <= S / 7 * 6) || (i >= S / 7 && i <= S / 7 * 2))
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->enemyd2->img, ((x) * S), (y + 1) * S - i);
		else
			mlx_put_image_to_window(pms->game, pms->win, \
			(pms->all)->enemyd1->img, ((x) * S), (y + 1) * S - i);
		i--;
		mlx_do_sync(pms->game);
		usleep(RENDERING);
	}
}
