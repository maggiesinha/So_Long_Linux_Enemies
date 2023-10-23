/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:21:43 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/23 12:54:34 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <errno.h>
# include <string.h>
# include <time.h>

#define S 90
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define ENEMY_RATIO 10

typedef struct images_list
{
	void		*img;
	char		*addr;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
	int			width;
	int			height;
} image;

typedef struct pics
{
	image	*bckg;
	image	*btfly_pl;
	image	*btfly_pl2;
	image	*btfly_pl3;
	image	*btfly_pl4;
	image	*btfly_pr;
	image	*btfly_pr2;
	image	*btfly_pr3;
	image	*btfly_pr4;
	image	*btfly_pu;
	image	*btfly_pu2;
	image	*btfly_pu3;
	image	*btfly_pu4;
	image	*btfly_pd;
	image	*btfly_pd2;
	image	*btfly_pd3;
	image	*btfly_pd4;
	image	*mush;
	image	*walls;
	image	*exit;
	image	*dying1;
	image	*dying2;
	image	*dying3;
	image	*dying4;
	image	*dying5;
	image	*dying6;
	image	*dying7;
	image	*dying8;
	image	*dying9;
	image	*dying10;
	image	*moves;
	image	*enemy1;
	image	*enemy2;
} pictures;

typedef struct enemies_info
{
	struct enemies_info	*head;
	struct enemies_info	*next;
	size_t	x;
	size_t	y;
} enemy;

typedef struct parameters
{
	void		*game;
	void		*win;
	char		**map;
	pictures	*all;
	size_t		collectibles;
	size_t		p_x;
	size_t		p_y;
	size_t		m_width;
	size_t		m_height;
	size_t		bckg_n;
	size_t		enemies_n;
	enemy		*enemy_list;
} params;

typedef struct map
{
	size_t	players;
	size_t	exits;
	size_t	collectibles;
	size_t	a;
	size_t	i;
} map_stuff;

// Flood Fill
void	ft_exit_found(char **map_copy, int *exit, size_t x, size_t y);
size_t	ft_count_collectibles(char **map);
char	**ft_map_copy(char **map);
int	ft_floodfill(params *pms);
int	ft_ffalgorithm(char **map_copy, size_t x, size_t y, int *exit);

// Map Check
char		**ft_map_to_array(params *pms, const char *file);
int			ft_map_comp_check(char **map, params *pms);
int			ft_check_walls_around(char **map);
size_t		ft_map_height(char	*map[]);

// Map
void		ft_map_characters(params *pms, pictures *all, char character, size_t *i);
int			ft_map_to_screen(char **map, params *pms);
void		ft_add_enemy(params *pms, enemy *current_enemy, size_t x, size_t y);
void		ft_loop_map(params *pms, size_t *x, size_t *y);
void		ft_build_enemies(params *pms);
void		ft_enemies(params *pms);

// Move Utils
size_t		ft_find_player_x(char **map);
size_t		ft_find_player_y(char **map);

// Move
void		ft_move_left(params *pms);
void		ft_move_up(params *pms);
void		ft_move_right(params *pms);
void		ft_move_down(params *pms);

// Pictures
image		*ft_make_picture_xpm(char *relative_path, params *par);
pictures	*ft_build_all_images(params *par);

// Utils
void	ft_errors(params *pms, char	*message, int i);
void	ft_freeparams(params *pms, int i);
int		ft_key_press(int keycode, params *pms);
int		ft_close_window (params *pms);
void	ft_print_moves(params *pms);

# endif
