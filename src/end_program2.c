/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:29:13 by mvalerio          #+#    #+#             */
/*   Updated: 2023/11/07 10:44:00 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	ft_freeparams_dying(t_params *pms)
{
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
}

void	ft_freeparams_player2(t_params *pms)
{
	mlx_destroy_image(pms->game, pms->all->btfly_pr->img);
	free(pms->all->btfly_pr);
	mlx_destroy_image(pms->game, pms->all->btfly_pr2->img);
	free(pms->all->btfly_pr2);
	mlx_destroy_image(pms->game, pms->all->btfly_pr3->img);
	free(pms->all->btfly_pr3);
	mlx_destroy_image(pms->game, pms->all->btfly_pr4->img);
	free(pms->all->btfly_pr4);
}

void	ft_freeparams_player(t_params *pms)
{
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
	ft_freeparams_player2(pms);
}

void	ft_freeparams(t_params *pms, int i)
{
	if (i == 2)
	{
		mlx_destroy_image(pms->game, pms->all->bckg->img);
		free(pms->all->bckg);
		ft_freeparams_player(pms);
		mlx_destroy_image(pms->game, pms->all->mush->img);
		free(pms->all->mush);
		mlx_destroy_image(pms->game, pms->all->exit->img);
		free(pms->all->exit);
		mlx_destroy_image(pms->game, pms->all->walls->img);
		free(pms->all->walls);
		ft_freeparams_dying(pms);
		mlx_destroy_image(pms->game, pms->all->moves->img);
		free(pms->all->moves);
		ft_freeparams_enemies(pms);
		free (pms->all);
		ft_free_enemies(pms);
	}
	if (i == 1 || i == 2)
		ft_free_arraystring(pms->map);
}

int	ft_close_window(t_params *pms)
{
	ft_freeparams(pms, 2);
	mlx_destroy_window((pms)->game, (pms)->win);
	mlx_destroy_display(pms->game);
	free(pms->game);
	free(pms);
	exit (0);
}
