/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:21:52 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/30 12:26:01 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

char	**ft_map_to_array(params *pms, const char *file)
{
	int		map_fd;
	char	*line;
	char	*map_string;
	char	**map_array;
	char	*temp;

	map_fd = open(file, O_RDONLY);
	if (map_fd == -1)
		ft_errors(pms, strerror(errno), 0);
	line = get_next_line(map_fd);
	if (!line)
	{
		close (map_fd);
		ft_errors(pms, "Error", 0);
	}
	map_string = strdup("\0");
	while (line)
	{
		temp = map_string;
		map_string = ft_strjoin(map_string, line);
		free (temp);
		free (line);
		line = get_next_line(map_fd);
	}
	map_array = ft_split_fail_on_divider(map_string, '\n');
	if (!map_array)
		ft_errors(pms, "Error", 0);
	free(map_string);
	close (map_fd);
	return (map_array);
}

int	ft_map_comp_check(char **map, params *pms)
{
	map_stuff	maps;

	ft_memset(&maps, 0, sizeof(maps));
	while (map[maps.i])
	{
		(maps.a) = 0;
		while (map[maps.i][maps.a])
		{
			if (map[maps.i][maps.a] == 'P')
				(maps.players)++;
			else if (map[maps.i][maps.a] == 'E')
				(maps.exits)++;
			else if (map[maps.i][maps.a] == 'C')
				(maps.collectibles)++;
			else if (map[maps.i][maps.a] != '0' && map[maps.i][maps.a] != '1')
				return (0);
			(maps.a)++;
		}
		(maps.i)++;
	}
	if (maps.players != 1 || maps.collectibles < 1 || maps.exits != 1)
		return (0);
	pms->collectibles = maps.collectibles;
	return (1);
}

int	ft_check_walls_around(char **map)
{
	int i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[ft_arraylen(map) - 1][i])
	{
		if (map[ft_arraylen(map) - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if ((map[i][0] != '1') || (map[i][ft_strlen(map[0]) - 1] != '1'))
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_map_height(char	*map[])
{
	size_t	i;
	size_t	compare;

	i = 0;
	compare = ft_strlen(map[i]);
	while (map[i])
	{
		if	(ft_strlen(map[i]) != compare)
			return (0);
		i++;
	}
	return (i);
}
