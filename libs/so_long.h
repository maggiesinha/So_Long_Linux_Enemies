/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:21:43 by mvalerio          #+#    #+#             */
/*   Updated: 2023/11/06 12:19:56 by mvalerio         ###   ########.fr       */
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
#define ENEMY_RATIO 15
#define ENEMY_TIME 100000
#define RENDERING 5000


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
	image	*enemyl1;
	image	*enemyl2;
	image	*enemyr1;
	image	*enemyr2;
	image	*enemyu1;
	image	*enemyu2;
	image	*enemyd1;
	image	*enemyd2;
	image	*enemydeath_u;
	image	*enemydeath_d;
	image	*enemydeath_l;
	image	*enemydeath_r;
} pictures;

typedef struct enemies_info
{
	struct enemies_info	*head;
	struct enemies_info	*next;
	size_t	x;
	size_t	y;
	size_t	dir;
	void	*e1_img;
	void	*e2_img;
	size_t	e_next_x;
	size_t	e_next_y;
	int		i_xsignal;
	int		i_ysignal;
	int		kill;
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
	int			player_state;
	int			key_press;
	void		*p1_img;
	void		*p2_img;
	void		*p3_img;
	void		*p4_img;
	size_t		p_next_x;
	size_t		p_next_y;
	int			p_i_xsignal;
	int			p_i_ysignal;
	int			moved;
} params;

typedef struct map
{
	size_t	players;
	size_t	exits;
	size_t	collectibles;
	size_t	a;
	size_t	i;
} map_stuff;

// Enemies

			// 1
void		ft_add_enemy(params *pms, enemy *current_enemy, size_t x, size_t y);
void		ft_build_enemies(params *pms);
void		ft_enemies(params *pms);

			// 2
void		ft_enemy_not_move(params *pms, enemy *current);
void		ft_enemy_directions(params *pms, int dir, enemy *current, size_t xy[2]);
void		ft_set_enemy_frames(params *pms);

			// Set Directions
void		ft_set_enemy_up(params *pms, enemy *current, size_t x, size_t y);
void		ft_set_enemy_down(params *pms, enemy *current, size_t x, size_t y);
void		ft_set_enemy_left(params *pms, enemy *current, size_t x, size_t y);
void		ft_set_enemy_right(params *pms, enemy *current, size_t x, size_t y);

// Keys
int			ft_key_press(int keycode, params *pms);
void		ft_key_up(params *pms);
void		ft_key_down(params *pms);
void		ft_key_left(params *pms);
void		ft_key_right(params *pms);

// Rendering
			// 1
void		ft_render1(params *pms, int i);
void		ft_render2(params *pms, int i);
void		ft_render3(params *pms, int i);
void		ft_render4(params *pms, int i);
void		ft_render_pixel(params *pms, int i);

			// 2
int			ft_rendering (params *pms);
void		ft_render_p_left(params *pms);
void		ft_render_p_right(params *pms);
void		ft_render_p_up(params *pms);
void		ft_render_p_down(params *pms);

// Death
void		ft_death_animation_up(params *pms, enemy *current);
void		ft_death_animation_down(params *pms, enemy *current);
void		ft_death_animation_left(params *pms, enemy *current);
void		ft_death_animation_right(params *pms, enemy *current);
void		ft_death(params *pms, enemy* current);

// Map

			// 1
void		ft_print_map(params *pms);
void		ft_loop_map(params *pms, size_t *x, size_t *y);
char		*ft_map_to_string(char *line, char *temp, char* map_string, int map_fd);
char		**ft_map_to_array(params *pms, const char *file);
int			ft_map_comp_check(char **map, params *pms);

			// 2
int			ft_check_walls_around(char **map);
size_t		ft_map_height(char *map[]);
void		ft_map_characters(params *pms, size_t x, size_t y);
int			ft_map_to_screen(char **map, params *pms);

// Flood Fill
char		**ft_map_copy(char **map);
int			ft_floodfill(params *pms);
void		ft_exit_found(char **map_copy, int *exit, size_t x, size_t y);
int			ft_ffalgorithm(char **map_copy, size_t x, size_t y, int *exit);
size_t		ft_count_collectibles(char **map);

// Pictures
image		*ft_make_picture_xpm(char *relative_path, params *par);
void		ft_build_all_images_player(params *pms, pictures *comps);
void		ft_build_all_images_enemy(params *pms, pictures *comps);
pictures	*ft_build_all_images(params *pms);

// Player
			// 1
void		ft_eat_collectible(params *pms);
void		ft_set_player_frames(params *pms);
void		ft_put_player(params *pms, size_t x, size_t y);

			// 2
size_t		ft_find_player_x(char **map);
size_t		ft_find_player_y(char **map);
void		ft_print_moves(params *pms);

// End Program

			// 1
void		ft_win(params *pms, size_t x, size_t y);
void		ft_win2(params *pms, size_t x, size_t y);
void		ft_errors(params *pms, char *message, int i);
void		ft_free_enemies(params *pms);
void		ft_freeparams_enemies(params *pms);

			// 2
void		ft_freeparams_dying(params *pms);
void		ft_freeparams_player2(params *pms);
void		ft_freeparams_player(params *pms);
void		ft_freeparams(params *pms, int i);
int			ft_close_window(params *pms);

# endif
