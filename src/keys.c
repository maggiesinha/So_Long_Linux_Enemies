/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:59:15 by maggie            #+#    #+#             */
/*   Updated: 2023/11/07 10:47:25 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	ft_key_press(int keycode, t_params *pms)
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

void	ft_key_up(t_params *pms)
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

void	ft_key_down(t_params *pms)
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

void	ft_key_left(t_params *pms)
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

void	ft_key_right(t_params *pms)
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
