/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:33:14 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/30 12:19:43 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	ft_key_up(params *pms)
{
	if (pms->key_press == UP)
	{
		pms->p1_img = pms->all->btfly_pu->img;
		pms->p2_img = pms->all->btfly_pu2->img;
		pms->p3_img = pms->all->btfly_pu3->img;
		pms->p4_img = pms->all->btfly_pu4->img;
		pms->p_next_x = pms->p_x;
		pms->p_next_y = pms->p_y - 1;
		pms->p_i_xsignal = 0;
		pms->p_i_ysignal = 1;
	}
}

void	ft_key_down(params *pms)
{
	if (pms->key_press == DOWN)
	{
		pms->p1_img = pms->all->btfly_pd->img;
		pms->p2_img = pms->all->btfly_pd2->img;
		pms->p3_img = pms->all->btfly_pd3->img;
		pms->p4_img = pms->all->btfly_pd4->img;
		pms->p_next_x = pms->p_x;
		pms->p_next_y = pms->p_y + 1;
		pms->p_i_xsignal = 0;
		pms->p_i_ysignal = -1;
	}
}

void	ft_key_left(params *pms)
{
	if (pms->key_press == LEFT)
	{
		pms->p1_img = pms->all->btfly_pl->img;
		pms->p2_img = pms->all->btfly_pl2->img;
		pms->p3_img = pms->all->btfly_pl3->img;
		pms->p4_img = pms->all->btfly_pl4->img;
		pms->p_next_x = pms->p_x - 1;
		pms->p_next_y = pms->p_y;
		pms->p_i_xsignal = 1;
		pms->p_i_ysignal = 0;
	}
}

void	ft_key_right(params *pms)
{
	if (pms->key_press == RIGHT)
	{
		pms->p1_img = pms->all->btfly_pr->img;
		pms->p2_img = pms->all->btfly_pr2->img;
		pms->p3_img = pms->all->btfly_pr3->img;
		pms->p4_img = pms->all->btfly_pr4->img;
		pms->p_next_x = pms->p_x + 1;
		pms->p_next_y = pms->p_y;
		pms->p_i_xsignal = -1;
		pms->p_i_ysignal = 0;
	}
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

void	ft_set_enemy_up(params *pms, enemy *current, size_t x, size_t y)
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

void	ft_set_enemy_down(params *pms, enemy *current, size_t x, size_t y)
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

void	ft_set_enemy_left(params *pms, enemy *current, size_t x, size_t y)
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

void	ft_set_enemy_right(params *pms, enemy *current, size_t x, size_t y)
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

void	ft_enemy_not_move(params *pms, enemy *current)
{
	current->e1_img = pms->all->enemyr1->img;
	current->e2_img = pms->all->enemyr2->img;
	current->e_next_x = current->x;
	current->e_next_y = current->y;
	current->i_xsignal = 0;
	current->i_ysignal = 0;
}

void	ft_enemy_directions(params *pms, int dir, enemy *current, size_t xy[2])
{
	if (dir == UP && (pms->map[xy[1] - 1][xy[0]] == '0' || \
		pms->map[xy[1] - 1][xy[0]] == 'P'))
		ft_set_enemy_up(pms, current, xy[0], xy[1]);
	else if (dir == DOWN && (pms->map[xy[1] + 1][xy[0]] == '0' \
		|| pms->map[xy[1] + 1][xy[0]] == 'P'))
		ft_set_enemy_down(pms, current, xy[0], xy[1]);
	else if (dir == LEFT && (pms->map[current->y][xy[0] - 1] == '0' \
		|| pms->map[current->y][xy[0] - 1] == 'P'))
		ft_set_enemy_left(pms, current, xy[0], xy[1]);
	else if (dir == RIGHT && (pms->map[current->y][xy[0] + 1] == '0' \
		|| pms->map[current->y][xy[0] + 1] == 'P' ))
		ft_set_enemy_right(pms, current, xy[0], xy[1]);
	else
		ft_enemy_not_move(pms, current);
}

void	ft_set_enemy_frames(params *pms)
{
	enemy	*current;
	int		dir;
	size_t	xy[2];

	if (pms->enemies_n > 0)
	{
		current = pms->enemy_list->head;
		while (current)
		{
			xy[0] = current->x;
			xy[1] = current->y;
			dir = rand() % 4 + 1;
			ft_enemy_directions(pms, dir, current, xy);
			current = current->next;
		}
	}
}

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
}
void	ft_render_pixel(params *pms, int i)
{
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
	ft_print_moves(pms);
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
	return (0);
}

void	ft_death_animation_up(params *pms, enemy *current)
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

void	ft_death_animation_down(params *pms, enemy *current)
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

void	ft_death_animation_left(params *pms, enemy *current)
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

void	ft_death_animation_right(params *pms, enemy *current)
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

void	ft_death(params *pms, enemy* current)
{
		if (current->dir == UP)
			ft_death_animation_up(pms, current);
		if (current->dir == DOWN)
			ft_death_animation_down(pms, current);
		if (current->dir == LEFT)
			ft_death_animation_left(pms, current);
		if (current->dir == RIGHT)
			ft_death_animation_right(pms, current);
		ft_close_window(pms);
}

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

