/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:59:15 by maggie            #+#    #+#             */
/*   Updated: 2023/10/23 12:01:01 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"


size_t	ft_count_collectibles(char **map)
{
	size_t	collectibles;
	size_t	i;
	size_t	a;

	collectibles = 0;
	i = 0;
	while (map[i])
	{
		a = 0;
		while (map[i][a])
		{
			if (map[i][a] == 'C')
				collectibles++;
			a++;
		}
		i++;
	}
	return (collectibles);
}
char	**ft_map_copy(char **map)
{
	char **map_copy;
	size_t	i;

	i = 0;
	map_copy = malloc(sizeof(char *) * (ft_arraylen(map) + 1));
	if (!map_copy)
		return (NULL);
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = (NULL);
	return (map_copy);
}

int	ft_floodfill(params *pms)
{
	char	**map_copy;
	int		*exit;
	size_t	p_x;
	size_t	p_y;
	int		valid;

	exit = malloc(sizeof(int));
	if (!exit)
		return (0);
	*exit = 0;
	map_copy = ft_map_copy(pms->map);
	p_x = ft_find_player_x(map_copy);
	p_y = ft_find_player_y(map_copy);
	if (ft_ffalgorithm(map_copy, p_x, p_y, exit))
		valid = 1;
	else
		valid = 0;
	ft_free_arraystring(map_copy);
	free (exit);
	return (valid);
}

void	ft_exit_found(char **map_copy, int *exit, size_t x, size_t y)
{
	if (map_copy[y][x] == 'E' || map_copy[y][x - 1] == 'E' || \
	map_copy[y + 1][x] == 'E' || map_copy[y - 1][x] == 'E' || \
	map_copy[y][x + 1] == 'E')
		*exit = 1;
}

int	ft_ffalgorithm(char **map_copy, size_t x, size_t y, int *exit)
{
	ft_exit_found(map_copy, exit, x, y);
	if (map_copy[y][x + 1] == '0' || map_copy[y][x + 1] == 'C')
	{
		map_copy[y][x + 1] = 'V';
		ft_ffalgorithm(map_copy, x + 1, y, exit);
	}
	if (map_copy[y][x - 1] == '0' || map_copy[y][x - 1] == 'C')
	{
		map_copy[y][x - 1] = 'V';
		ft_ffalgorithm(map_copy, x - 1, y, exit);
	}
	if (map_copy[y + 1][x] == '0' || map_copy[y + 1][x] == 'C')
	{
		map_copy[y + 1][x] = 'V';
		ft_ffalgorithm(map_copy, x, y + 1, exit);
	}
	if (map_copy[y - 1][x] == '0' || map_copy[y - 1][x] == 'C')
	{
		map_copy[y - 1][x] = 'V';
		ft_ffalgorithm(map_copy, x, y - 1, exit);
	}
	if (*exit == 1 && ft_count_collectibles(map_copy) == 0)
		return (1);
	return (0);
}
