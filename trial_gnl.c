/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trial_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:40:54 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/03 12:45:25 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	int fd;

	fd = open("text.txt", O_RDONLY);

	char *line;
	
	line = get_next_line(fd);
	ft_printf("%s", line);

	line = get_next_line(fd);
	ft_printf("%s", line);

	line = get_next_line(fd);
	ft_printf("%s", line);

	line = get_next_line(fd);
	ft_printf("%s", line);

	close(fd);

	ft_printf("BLAAAAAAA");

	
	fd = open("text.txt", O_RDONLY);

	
	line = get_next_line(fd);
	ft_printf("%s", line);

	line = get_next_line(fd);
	ft_printf("%s", line);

	line = get_next_line(fd);
	ft_printf("%s", line);

	line = get_next_line(fd);
	ft_printf("%s", line);

	close(fd);

}