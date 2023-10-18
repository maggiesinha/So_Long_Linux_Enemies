/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:31:47 by maggie            #+#    #+#             */
/*   Updated: 2023/09/14 10:41:48 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

void	ft_empty_buffer(char *buffer, size_t *i);
char	*ft_strjoin_nl(char *line, char *buffer, size_t *i);
char	*get_next_line(int fd);

#endif
