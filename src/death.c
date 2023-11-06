/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:29:13 by mvalerio          #+#    #+#             */
/*   Updated: 2023/11/06 11:56:37 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

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
