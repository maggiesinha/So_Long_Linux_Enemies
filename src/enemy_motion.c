/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:33:14 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/27 13:28:06 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	ft_set_player_frames(params *pms)
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
	else if (pms->key_press == DOWN)
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
	else if (pms->key_press == LEFT)
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
	else
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

	if (pms->map[pms->p_next_y][pms->p_next_x] == 'E' && pms->collectibles == 0)
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		(pms->all)->bckg->img, pms->p_x * S, pms->p_y * S);
		ft_close_window(pms);
	}
	else if (pms->map[pms->p_next_y][pms->p_next_x] == 'C')
	{
		pms->collectibles--;
		pms->map[pms->p_next_y][pms->p_next_x] = '0';
		pms->map[pms->p_y][pms->p_x] = '0';
		pms->map[pms->p_next_y][pms->p_next_x] = 'P';
	}
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

void	ft_set_enemy_frames(params *pms)
{
	enemy	*current;
	int		dir;
	size_t	x;
	size_t	y;

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
				current->e1_img = pms->all->enemyu1->img;
				current->e2_img = pms->all->enemyu2->img;
				current->e_next_x = current->x;
				current->e_next_y = current->y - 1;
				current->i_xsignal = 0;
				current->i_xsignal = 1;
				current->dir = UP;

				pms->map[y][x] = '0';
				if (pms->map[y - 1][x] == 'P')
					current->kill = 1;
				pms->map[y - 1][x] = 'B';
				ft_map_characters(pms, x, y);
			}
			else if (dir == DOWN && (pms->map[y + 1][x] == '0' || pms->map[y + 1][x] == 'P'))
			{
				current->e1_img = pms->all->enemyd1->img;
				current->e2_img = pms->all->enemyd2->img;
				current->e_next_x = current->x;
				current->e_next_y = current->y + 1;
				current->i_xsignal = 0;
				current->i_xsignal = 1;

				current->dir = DOWN;
				pms->map[y][x] = '0';
				if (pms->map[y + 1][x] == 'P')
					current->kill = 1;
				pms->map[y + 1][x] = 'B';
				ft_map_characters(pms, x, y);
			}
			else if (dir == LEFT && (pms->map[current->y][x - 1] == '0' || pms->map[current->y][x - 1] == 'P'))
			{
				current->e1_img = pms->all->enemyl1->img;
				current->e2_img = pms->all->enemyl2->img;
				current->e_next_x = current->x - 1;
				current->e_next_y = current->y;
				current->i_xsignal = -1;
				current->i_xsignal = 0;

				current->dir = LEFT;
				pms->map[y][x] = '0';
				if (pms->map[y][x - 1] == 'P')
					current->kill = 1;
				pms->map[y][x - 1] = 'B';
				ft_map_characters(pms, x, y);
			}
			else if (dir == RIGHT && (pms->map[current->y][x + 1] == '0' || pms->map[current->y][x + 1] == 'P' ))
			{
				current->e1_img = pms->all->enemyr1->img;
				current->e2_img = pms->all->enemyr2->img;
				current->e_next_x = current->x + 1;
				current->e_next_y = current->y;
				current->i_xsignal = 1;
				current->i_xsignal = 0;

				current->dir = RIGHT;
				pms->map[y][x] = '0';
				if (pms->map[y][x + 1] == 'P')
					current->kill = 1;
				pms->map[y][x + 1] = 'B';
				ft_map_characters(pms, x, y);
			}
			else
			{
				current->e1_img = pms->all->enemyr1->img;
				current->e2_img = pms->all->enemyr2->img;
				current->e_next_x = current->x;
				current->e_next_y = current->y;
				current->i_xsignal = 0;
				current->i_xsignal = 0;
			}
			current = current->next;
		}
	}
}



int		ft_rendering (params *pms)
{
	int	i;
	enemy	*current;

	i = S;
	pms->p_x = ft_find_player_x(pms->map);
	pms->p_y = ft_find_player_y(pms->map);
	ft_set_player_frames(pms);
	ft_set_enemy_frames(pms);
	while (i>=0)
	{
		mlx_put_image_to_window(pms->game, pms->win, \
		pms->all->bckg->img, pms->p_x * S, pms->p_y * S);
		if (i >= S / 7 * 3 && i <= S / 7 * 4)
		{
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
		else if ((i >= S / 7 * 4 && i <= S / 7 * 5) || (i >= S / 7 * 2 && i <= S / 7 * 3))
		{
			mlx_put_image_to_window(pms->game, pms->win, \
			pms->p3_img, (pms->p_next_x * S) + i * pms->p_i_xsignal, pms->p_next_y * S + i * pms->p_i_ysignal);
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
		else if ((i >= S / 7 * 5 && i <= S / 7 * 6) || (i >= S / 7 && i <= S / 7 * 2))
		{
			mlx_put_image_to_window(pms->game, pms->win, \
			pms->p2_img, (pms->p_next_x * S) + i * pms->p_i_xsignal, pms->p_next_y * S + i * pms->p_i_ysignal);
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
		else
		{
			mlx_put_image_to_window(pms->game, pms->win, \
			pms->p1_img, (pms->p_next_x * S) + i * pms->p_i_xsignal, pms->p_next_y * S + i * pms->p_i_ysignal);
			if (pms->enemies_n > 0)
			{
				current = pms->enemy_list->head;
				while (current)
				{
					mlx_put_image_to_window(pms->game, pms->win, \
					(pms->all)->bckg->img, current->x * S, current->y * S);
	
					mlx_put_image_to_window(pms->game, pms->win, \
					current->e1_img, current->e_next_x * S + i * current->i_xsignal, current->e_next_y * S + i * current->i_ysignal);
	
					current = current->next;
				}
			}
		}
		i--;
		mlx_do_sync(pms->game);
		usleep(RENDERING);
	}
	ft_print_moves(pms);
	current = pms->enemy_list->head;
	while (current)
	{
		current->x = current->e_next_x;
		current->y = current->e_next_y;
		if (current->kill)
			ft_death(pms, current);
		current = current->next;
	}
	ft_print_map(pms);
	return (0);
}





























void	ft_death(params *pms, enemy* current)
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
