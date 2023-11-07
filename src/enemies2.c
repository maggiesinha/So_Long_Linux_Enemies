/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:20:48 by mvalerio          #+#    #+#             */
/*   Updated: 2023/11/07 10:46:33 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	ft_enemy_not_move(t_params *pms, t_enemy *current)
{
	current->e1_img = pms->all->enemyr1->img;
	current->e2_img = pms->all->enemyr2->img;
	current->e_next_x = current->x;
	current->e_next_y = current->y;
	current->i_xsignal = 0;
	current->i_ysignal = 0;
}

void	ft_enemy_directions(t_params *pms, int dir, \
t_enemy *current, size_t xy[2])
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

void	ft_set_enemy_frames(t_params *pms)
{
	t_enemy	*current;
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
