/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:20:48 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/23 13:21:19 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

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
	{
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


void	ft_enemies(params *pms)
{
	size_t			i;

	i = 0;
	pms->enemies_n = (pms->bckg_n) / ENEMY_RATIO;
	if (!(pms->enemies_n))
		return ;
	pms->enemy_list = malloc(sizeof(enemy));
	if (!(pms->enemy_list))
		return ;
	pms->enemy_list->head = NULL;
	while (i < pms->enemies_n)
	{
		ft_build_enemies(pms);
		i++;
	}

}
