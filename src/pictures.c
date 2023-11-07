/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pictures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:27:37 by mvalerio          #+#    #+#             */
/*   Updated: 2023/11/07 10:58:26 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

t_image	*ft_make_picture_xpm(char *relative_path, t_params *par)
{
	t_image	*pic;
	int		img_width;
	int		img_height;

	pic = malloc(sizeof(t_image));
	if (!pic)
		return (0);
	pic->img = mlx_xpm_file_to_image(par->game, relative_path, &img_width, \
	&img_height);
	pic->addr = mlx_get_data_addr(pic->img, &(pic->pixel_bits), \
	&(pic->line_bytes), &(pic->endian));
	return (pic);
}

void	ft_build_all_images_player(t_params *pms, t_pictures *comps)
{
	comps->btfly_pu = ft_make_picture_xpm("Images/btfly_pu.xpm", pms);
	comps->btfly_pu2 = ft_make_picture_xpm("Images/btfly_pu2.xpm", pms);
	comps->btfly_pu3 = ft_make_picture_xpm("Images/btfly_pu3.xpm", pms);
	comps->btfly_pu4 = ft_make_picture_xpm("Images/btfly_pu4.xpm", pms);
	comps->btfly_pd = ft_make_picture_xpm("Images/btfly_pd.xpm", pms);
	comps->btfly_pd2 = ft_make_picture_xpm("Images/btfly_pd2.xpm", pms);
	comps->btfly_pd3 = ft_make_picture_xpm("Images/btfly_pd3.xpm", pms);
	comps->btfly_pd4 = ft_make_picture_xpm("Images/btfly_pd4.xpm", pms);
	comps->btfly_pl = ft_make_picture_xpm("Images/btfly_pl.xpm", pms);
	comps->btfly_pl2 = ft_make_picture_xpm("Images/btfly_pl2.xpm", pms);
	comps->btfly_pl3 = ft_make_picture_xpm("Images/btfly_pl3.xpm", pms);
	comps->btfly_pl4 = ft_make_picture_xpm("Images/btfly_pl4.xpm", pms);
	comps->btfly_pr = ft_make_picture_xpm("Images/btfly_pr.xpm", pms);
	comps->btfly_pr2 = ft_make_picture_xpm("Images/btfly_pr2.xpm", pms);
	comps->btfly_pr3 = ft_make_picture_xpm("Images/btfly_pr3.xpm", pms);
	comps->btfly_pr4 = ft_make_picture_xpm("Images/btfly_pr4.xpm", pms);
}

void	ft_build_all_images_enemy(t_params *pms, t_pictures *comps)
{
	comps->enemyl1 = ft_make_picture_xpm("Images/enemy_l1.xpm", pms);
	comps->enemyl2 = ft_make_picture_xpm("Images/enemy_l2.xpm", pms);
	comps->enemyr1 = ft_make_picture_xpm("Images/enemy_r1.xpm", pms);
	comps->enemyr2 = ft_make_picture_xpm("Images/enemy_r2.xpm", pms);
	comps->enemyu1 = ft_make_picture_xpm("Images/enemy_u1.xpm", pms);
	comps->enemyu2 = ft_make_picture_xpm("Images/enemy_u2.xpm", pms);
	comps->enemyd1 = ft_make_picture_xpm("Images/enemy_d1.xpm", pms);
	comps->enemyd2 = ft_make_picture_xpm("Images/enemy_d2.xpm", pms);
	comps->enemydeath_u = ft_make_picture_xpm("Images/enemydeath_u.xpm", pms);
	comps->enemydeath_d = ft_make_picture_xpm("Images/enemydeath_d.xpm", pms);
	comps->enemydeath_l = ft_make_picture_xpm("Images/enemydeath_l.xpm", pms);
	comps->enemydeath_r = ft_make_picture_xpm("Images/enemydeath_r.xpm", pms);
}

t_pictures	*ft_build_all_images(t_params *pms)
{
	t_pictures	*comps;

	comps = malloc(sizeof(t_pictures));
	if (!comps)
		return (0);
	comps->bckg = ft_make_picture_xpm("Images/bckg.xpm", pms);
	comps->walls = ft_make_picture_xpm("Images/walls.xpm", pms);
	comps->exit = ft_make_picture_xpm("Images/exit.xpm", pms);
	comps->mush = ft_make_picture_xpm("Images/mush.xpm", pms);
	ft_build_all_images_player(pms, comps);
	comps->dying1 = ft_make_picture_xpm("Images/dying1.xpm", pms);
	comps->dying2 = ft_make_picture_xpm("Images/dying2.xpm", pms);
	comps->dying3 = ft_make_picture_xpm("Images/dying3.xpm", pms);
	comps->dying4 = ft_make_picture_xpm("Images/dying4.xpm", pms);
	comps->dying5 = ft_make_picture_xpm("Images/dying5.xpm", pms);
	comps->dying6 = ft_make_picture_xpm("Images/dying6.xpm", pms);
	comps->dying7 = ft_make_picture_xpm("Images/dying7.xpm", pms);
	comps->dying8 = ft_make_picture_xpm("Images/dying8.xpm", pms);
	comps->dying9 = ft_make_picture_xpm("Images/dying9.xpm", pms);
	comps->dying10 = ft_make_picture_xpm("Images/dying10.xpm", pms);
	comps->moves = ft_make_picture_xpm("Images/moves.xpm", pms);
	ft_build_all_images_enemy(pms, comps);
	return (comps);
}
