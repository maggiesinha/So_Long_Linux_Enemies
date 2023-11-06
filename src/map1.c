/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:21:52 by mvalerio          #+#    #+#             */
/*   Updated: 2023/11/06 11:46:11 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	ft_print_map(params *pms)
{
	size_t	y = 0;
	size_t	x = 0;

	while ((pms->map)[y])
	{
		x = 0;
		while ((pms->map)[y][x])
		{
			ft_printf("%c", (pms->map)[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("\n\n\n");
}
void	ft_loop_map(params *pms, size_t *x, size_t *y)
{
	if (pms->map[*y][(*x) + 1])
		(*x)++;
	else
	{
		(*y)++;
		(*x) = 0;
	}
}
char	*ft_map_to_string(char *line, char *temp, char* map_string, int map_fd)
{
	while (line)
	{
		temp = map_string;
		map_string = ft_strjoin(map_string, line);
		free (temp);
		free (line);
		line = get_next_line(map_fd);
	}
	return (map_string);
}

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
	temp = (NULL);
	map_string = ft_map_to_string(line, temp, map_string, map_fd);
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
