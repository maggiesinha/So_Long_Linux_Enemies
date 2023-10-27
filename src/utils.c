/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:30:59 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/27 09:35:39 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	ft_errors(params *pms, char	*message, int i)
{
	ft_printf("%s\n", message);
	ft_freeparams(pms, i);
	free(pms);
	exit (1);
}

void	ft_freeparams(params *pms, int i)
{
	if (i == 2)
	{
		mlx_destroy_image(pms->game, pms->all->bckg->img);
		free(pms->all->bckg);
		mlx_destroy_image(pms->game, pms->all->btfly_pu->img);
		free(pms->all->btfly_pu);
		mlx_destroy_image(pms->game, pms->all->btfly_pu2->img);
		free(pms->all->btfly_pu2);
		mlx_destroy_image(pms->game, pms->all->btfly_pu3->img);
		free(pms->all->btfly_pu3);
		mlx_destroy_image(pms->game, pms->all->btfly_pu4->img);
		free(pms->all->btfly_pu4);
		mlx_destroy_image(pms->game, pms->all->btfly_pd->img);
		free(pms->all->btfly_pd);
		mlx_destroy_image(pms->game, pms->all->btfly_pd2->img);
		free(pms->all->btfly_pd2);
		mlx_destroy_image(pms->game, pms->all->btfly_pd3->img);
		free(pms->all->btfly_pd3);
		mlx_destroy_image(pms->game, pms->all->btfly_pd4->img);
		free(pms->all->btfly_pd4);
		mlx_destroy_image(pms->game, pms->all->btfly_pl->img);
		free(pms->all->btfly_pl);
		mlx_destroy_image(pms->game, pms->all->btfly_pl2->img);
		free(pms->all->btfly_pl2);
		mlx_destroy_image(pms->game, pms->all->btfly_pl3->img);
		free(pms->all->btfly_pl3);
		mlx_destroy_image(pms->game, pms->all->btfly_pl4->img);
		free(pms->all->btfly_pl4);
		mlx_destroy_image(pms->game, pms->all->btfly_pr->img);
		free(pms->all->btfly_pr);
		mlx_destroy_image(pms->game, pms->all->btfly_pr2->img);
		free(pms->all->btfly_pr2);
		mlx_destroy_image(pms->game, pms->all->btfly_pr3->img);
		free(pms->all->btfly_pr3);
		mlx_destroy_image(pms->game, pms->all->btfly_pr4->img);
		free(pms->all->btfly_pr4);
		mlx_destroy_image(pms->game, pms->all->mush->img);
		free(pms->all->mush);
		mlx_destroy_image(pms->game, pms->all->exit->img);
		free(pms->all->exit);
		mlx_destroy_image(pms->game, pms->all->walls->img);
		free(pms->all->walls);
		mlx_destroy_image(pms->game, pms->all->dying1->img);
		free(pms->all->dying1);
		mlx_destroy_image(pms->game, pms->all->dying2->img);
		free(pms->all->dying2);
		mlx_destroy_image(pms->game, pms->all->dying3->img);
		free(pms->all->dying3);
		mlx_destroy_image(pms->game, pms->all->dying4->img);
		free(pms->all->dying4);
		mlx_destroy_image(pms->game, pms->all->dying5->img);
		free(pms->all->dying5);
		mlx_destroy_image(pms->game, pms->all->dying6->img);
		free(pms->all->dying6);
		mlx_destroy_image(pms->game, pms->all->dying7->img);
		free(pms->all->dying7);
		mlx_destroy_image(pms->game, pms->all->dying8->img);
		free(pms->all->dying8);
		mlx_destroy_image(pms->game, pms->all->dying9->img);
		free(pms->all->dying9);
		mlx_destroy_image(pms->game, pms->all->dying10->img);
		free(pms->all->dying10);
		mlx_destroy_image(pms->game, pms->all->moves->img);
		free(pms->all->moves);
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
		free (pms->all);
	}
	if (i == 1 || i == 2)
		ft_free_arraystring(pms->map);
}

int	ft_key_press(int keycode, params *pms)
{
	if (keycode == 0xff1b)
		ft_close_window(pms);
	else if (keycode == 0xff51)
		pms->key_press = LEFT;
	else if (keycode == 0xff52)
		pms->key_press = UP;
	else if (keycode == 0xff53)
		pms->key_press = RIGHT;
	else if (keycode == 0xff54)
		pms->key_press = DOWN;
	return (0);
}

int	ft_close_window(params *pms)
{
	ft_freeparams(pms, 2);
	mlx_destroy_window((pms)->game, (pms)->win);
	mlx_destroy_display(pms->game);
	free(pms->game);
	free(pms);
	exit (0);
}

void	ft_print_moves(params *pms)
{
	static int	moves = 0;
	char		*move_count;

	mlx_put_image_to_window(pms->game, pms->win, \
	(pms->all)->moves->img, 15, 15);
	moves++;
	move_count = ft_itoa(moves);
	mlx_string_put(pms->game, pms->win, 35, 45, 0xffffff, move_count);
	free (move_count);
}
