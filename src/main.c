/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:23:45 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/26 13:06:47 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	main(int argc, char *argv[])
{
	params		*pms;

	srand(time(NULL));
	pms = malloc(sizeof(params));
	if (!pms)
		return (1);
	if (argc != 2)
		ft_errors(pms, "Error", 0);
	pms->map = ft_map_to_array(pms, argv[1]);
	if (!ft_map_comp_check(pms->map, pms) || \
		!ft_map_height(pms->map) || !ft_check_walls_around(pms->map) || !ft_floodfill(pms))
		ft_errors(pms, "Error", 1);
	pms->game = mlx_init();
	pms->win = mlx_new_window(pms->game, ft_strlen((pms->map)[0]) * S, \
		ft_arraylen((pms->map)) * S, "Maggieland");
	pms->player_state = RIGHT;
	pms->key_press = 0;
	ft_map_to_screen(pms->map, pms);
	ft_enemies(pms);
	mlx_loop_hook(pms->game, ft_motion, pms);
	mlx_key_hook(pms->win, ft_key_press, pms);
	mlx_hook(pms->win, 17, 0, ft_close_window, pms);
	mlx_loop(pms->game);
}
