/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:20:48 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/25 12:54:40 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"


void	ft_print_map(params *pms)
{
	size_t	y = 0;
	size_t	x = 0;

	while ((pms->map)[y])
	{
		x = 0;
		while ((pms->map)[y][x])
		{
			ft_printf("%c", (pms->map)[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("\n\n\n");
}

void	ft_add_enemy(params *pms, enemy *current_enemy, size_t x, size_t y)
{
	enemy	*current;

	current_enemy->x = x;
	current_enemy->y = y;
	pms->map[y][x] = 'B';
	current = pms->enemy_list->head;
	if (!(pms->enemy_list->head))
	{
		pms->enemy_list->head = current_enemy;
		pms->enemy_list->head->next = NULL;
	}
	else
	{
		while (current->next)
			current = current->next;
		current->next = current_enemy;
		current->next->next = NULL;
	}
	mlx_put_image_to_window(pms->game, \
	pms->win, pms->all->enemy1->img, x * S, y * S);
}

void	ft_loop_map(params *pms, size_t *x, size_t *y)
{
	if (pms->map[*y][(*x) + 1])
		(*x)++;
	else
	{
		(*y)++;
		(*x) = 0;
	}
}

void	ft_build_enemies(params *pms)
{
	enemy	*current_enemy;
	size_t	place;
	size_t	x;
	size_t	y;

	y = 1;
	x = 1;
	current_enemy = malloc(sizeof(enemy));
	if (!current_enemy)
		return ;
	place = rand() % pms->bckg_n;
	while (place > 1)
	{mlx_do_sync(pms->game);
		if (pms->map[y][x] == '0')
		{
			//ft_loop_map(pms, &x, &y);
					if (pms->map[y][(x) + 1])
						(x)++;
					else
					{
						(y)++;
						(x) = 0;
					}
			place--;
		}
		else
			//ft_loop_map(pms, &x, &y);
					if (pms->map[y][(x) + 1])
						(x)++;
					else
					{
						(y)++;
						(x) = 0;
					}
	}
	while (pms->map[y][x] != '0')
	{
			//ft_loop_map(pms, &x, &y);
					if (pms->map[y][(x) + 1])
						(x)++;
					else
					{
						(y)++;
						(x) = 0;
					}
	}
	ft_add_enemy(pms, current_enemy, x, y);
	pms->bckg_n--;
}


int	ft_enemies(params *pms)
{
	size_t			i;

	i = 0;
	pms->enemies_n = (pms->bckg_n) / ENEMY_RATIO;
	if (!(pms->enemies_n))
		return (0);
	pms->enemy_list = malloc(sizeof(enemy));
	if (!(pms->enemy_list))
		return (0);
	pms->enemy_list->head = NULL;
	while (i < pms->enemies_n)
	{
		ft_build_enemies(pms);
		i++;
	}		
	return (1);
}

int		ft_enemy_motion(params *pms)
{
	enemy	*current;
	int		dir;
	size_t	x;
	size_t	y;

	current = pms->enemy_list->head;
	while (current)
	{
		x = current->x;
		y = current->y;
		dir = rand() % 4 + 1;
		if (dir == UP && pms->map[y - 1][x] == '0')
		{
			mlx_put_image_to_window(pms->game, \
			pms->win, pms->all->enemy1->img, x * S, (y - 1) * S);
			ft_map_characters(pms, x, y);
			current->y = y - 1;
			pms->map[y][x] = '0';
			pms->map[y - 1][x] = 'B';
			ft_map_characters(pms, x, y);
		}
		else if (dir == DOWN && pms->map[y + 1][x] == '0')
		{
			mlx_put_image_to_window(pms->game, \
			pms->win, pms->all->enemy1->img, x * S, (y + 1) * S);
			ft_map_characters(pms, x, y);
			current->y = y + 1;
			pms->map[y][x] = '0';
			pms->map[y + 1][x] = 'B';
			ft_map_characters(pms, x, y);
		}
		else if (dir == LEFT && pms->map[current->y][x - 1] == '0')
		{
			mlx_put_image_to_window(pms->game, \
			pms->win, pms->all->enemy1->img, (x - 1) * S, y * S);
			ft_map_characters(pms, x, y);
			current->x = x - 1;
			pms->map[y][x] = '0';
			pms->map[y][x - 1] = 'B';
			ft_map_characters(pms, x, y);
		}
		else if (dir == RIGHT && pms->map[current->y][x + 1] == '0')
		{
			mlx_put_image_to_window(pms->game, \
			pms->win, pms->all->enemy1->img, (x + 1) * S, y * S);
			ft_map_characters(pms, x, y);
			current->x = x + 1;
			pms->map[y][x] = '0';
			pms->map[y][x + 1] = 'B';
			ft_map_characters(pms, x, y);
		}
		current = current->next;
}
	mlx_do_sync(pms->game);
	usleep(300000);
	return (0);
}
