/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:30:59 by mvalerio          #+#    #+#             */
/*   Updated: 2023/11/07 10:57:09 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	ft_win2(t_params *pms, size_t x, size_t y)
{
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
	ft_close_window(pms);
}

void	ft_win(t_params *pms, size_t x, size_t y)
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
	ft_win2(pms, x, y);
}

void	ft_errors(t_params *pms, char	*message, int i)
{
	ft_printf("%s\n", message);
	ft_freeparams(pms, i);
	free(pms);
	exit (1);
}

void	ft_free_enemies(t_params *pms)
{
	t_enemy	*current;
	t_enemy	*next;

	if (!pms->enemies_n)
		return ;
	next = pms->enemy_list->head;
	while (next)
	{
		current = next;
		next = current->next;
		free (current);
	}
	free (pms->enemy_list);
	return ;
}

void	ft_freeparams_enemies(t_params *pms)
{
	mlx_destroy_image(pms->game, pms->all->enemyl1->img);
	free(pms->all->enemyl1);
	mlx_destroy_image(pms->game, pms->all->enemyl2->img);
	free(pms->all->enemyl2);
	mlx_destroy_image(pms->game, pms->all->enemyr1->img);
	free(pms->all->enemyr1);
	mlx_destroy_image(pms->game, pms->all->enemyr2->img);
	free(pms->all->enemyr2);
	mlx_destroy_image(pms->game, pms->all->enemyu1->img);
	free(pms->all->enemyu1);
	mlx_destroy_image(pms->game, pms->all->enemyu2->img);
	free(pms->all->enemyu2);
	mlx_destroy_image(pms->game, pms->all->enemyd1->img);
	free(pms->all->enemyd1);
	mlx_destroy_image(pms->game, pms->all->enemyd2->img);
	free(pms->all->enemyd2);
	mlx_destroy_image(pms->game, pms->all->enemydeath_u->img);
	free(pms->all->enemydeath_u);
	mlx_destroy_image(pms->game, pms->all->enemydeath_d->img);
	free(pms->all->enemydeath_d);
	mlx_destroy_image(pms->game, pms->all->enemydeath_l->img);
	free(pms->all->enemydeath_l);
	mlx_destroy_image(pms->game, pms->all->enemydeath_r->img);
	free(pms->all->enemydeath_r);
}
