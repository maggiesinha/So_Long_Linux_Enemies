/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:12:39 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/11 12:18:32 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

size_t	ft_find_player_x(char **map)
{
	size_t	i[2];

	i[0] = 0;
	while ((map)[i[0]])
	{
		i[1] = 0;
		while ((map)[i[0]][i[1]])
		{
			if ((map)[i[0]][i[1]] == 'P')
				return (i[1]);
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}

size_t	ft_find_player_y(char **map)
{
	size_t	i[2];

	i[0] = 0;
	while ((map)[i[0]])
	{
		i[1] = 0;
		while ((map)[i[0]][i[1]])
		{
			if ((map)[i[0]][i[1]] == 'P')
				return (i[0]);
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}
