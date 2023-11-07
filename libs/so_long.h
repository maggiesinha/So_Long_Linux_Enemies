/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:21:43 by mvalerio          #+#    #+#             */
/*   Updated: 2023/11/07 10:56:51 by mvalerio         ###   ########.fr       */
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

# define S 90
# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4
# define ENEMY_RATIO 15
# define ENEMY_TIME 100000
# define RENDERING 5000

typedef struct images_list
{
	void		*img;
	char		*addr;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
	int			width;
	int			height;
}	t_image;

typedef struct pics
{
	t_image	*bckg;
	t_image	*btfly_pl;
	t_image	*btfly_pl2;
	t_image	*btfly_pl3;
	t_image	*btfly_pl4;
	t_image	*btfly_pr;
	t_image	*btfly_pr2;
	t_image	*btfly_pr3;
	t_image	*btfly_pr4;
	t_image	*btfly_pu;
	t_image	*btfly_pu2;
	t_image	*btfly_pu3;
	t_image	*btfly_pu4;
	t_image	*btfly_pd;
	t_image	*btfly_pd2;
	t_image	*btfly_pd3;
	t_image	*btfly_pd4;
	t_image	*mush;
	t_image	*walls;
	t_image	*exit;
	t_image	*dying1;
	t_image	*dying2;
	t_image	*dying3;
	t_image	*dying4;
	t_image	*dying5;
	t_image	*dying6;
	t_image	*dying7;
	t_image	*dying8;
	t_image	*dying9;
	t_image	*dying10;
	t_image	*moves;
	t_image	*enemyl1;
	t_image	*enemyl2;
	t_image	*enemyr1;
	t_image	*enemyr2;
	t_image	*enemyu1;
	t_image	*enemyu2;
	t_image	*enemyd1;
	t_image	*enemyd2;
	t_image	*enemydeath_u;
	t_image	*enemydeath_d;
	t_image	*enemydeath_l;
	t_image	*enemydeath_r;
}	t_pictures;

typedef struct enemies_info
{
	struct enemies_info	*head;
	struct enemies_info	*next;
	size_t				x;
	size_t				y;
	size_t				dir;
	void				*e1_img;
	void				*e2_img;
	size_t				e_next_x;
	size_t				e_next_y;
	int					i_xsignal;
	int					i_ysignal;
	int					kill;
}	t_enemy;

typedef struct parameters
{
	void		*game;
	void		*win;
	char		**map;
	t_pictures	*all;
	size_t		collectibles;
	size_t		p_x;
	size_t		p_y;
	size_t		m_width;
	size_t		m_height;
	size_t		bckg_n;
	size_t		enemies_n;
	t_enemy		*enemy_list;
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
}	t_params;

typedef struct map
{
	size_t	players;
	size_t	exits;
	size_t	collectibles;
	size_t	a;
	size_t	i;
}	t_map_stuff;

// Enemies

			// 1
void		ft_add_enemy(t_params *pms, t_enemy *current_enemy, \
size_t x, size_t y);
void		ft_build_enemies(t_params *pms);
void		ft_enemies(t_params *pms);

			// 2
void		ft_enemy_not_move(t_params *pms, t_enemy *current);
void		ft_enemy_directions(t_params *pms, int dir, t_enemy \
*current, size_t xy[2]);
void		ft_set_enemy_frames(t_params *pms);

			// Set Directions
void		ft_set_frames(t_params *pms);
void		ft_set_enemy_up(t_params *pms, t_enemy *current, \
			size_t x, size_t y);
void		ft_set_enemy_down(t_params *pms, t_enemy *current, \
			size_t x, size_t y);
void		ft_set_enemy_left(t_params *pms, t_enemy *current, \
			size_t x, size_t y);
void		ft_set_enemy_right(t_params *pms, t_enemy *current, \
			size_t x, size_t y);

// Keys
int			ft_key_press(int keycode, t_params *pms);
void		ft_key_up(t_params *pms);
void		ft_key_down(t_params *pms);
void		ft_key_left(t_params *pms);
void		ft_key_right(t_params *pms);

// Rendering
			// 1
void		ft_render1(t_params *pms, int i);
void		ft_render2(t_params *pms, int i);
void		ft_render3(t_params *pms, int i);
void		ft_render4(t_params *pms, int i);
void		ft_render_pixel(t_params *pms, int i);

			// 2
int			ft_rendering(t_params *pms);
void		ft_render_p_left(t_params *pms);
void		ft_render_p_right(t_params *pms);
void		ft_render_p_up(t_params *pms);
void		ft_render_p_down(t_params *pms);

// Death
void		ft_death_animation_up(t_params *pms, t_enemy *current);
void		ft_death_animation_down(t_params *pms, t_enemy *current);
void		ft_death_animation_left(t_params *pms, t_enemy *current);
void		ft_death_animation_right(t_params *pms, t_enemy *current);
void		ft_death(t_params *pms, t_enemy *current);

// Map

			// 1
void		ft_print_map(t_params *pms);
void		ft_loop_map(t_params *pms, size_t *x, size_t *y);
char		*ft_map_to_string(char *line, char *temp, \
			char *map_string, int map_fd);
char		**ft_map_to_array(t_params *pms, const char *file);
int			ft_map_comp_check(char **map, t_params *pms);

			// 2
int			ft_check_walls_around(char **map);
size_t		ft_map_height(char *map[]);
void		ft_map_characters(t_params *pms, size_t x, size_t y);
int			ft_map_to_screen(char **map, t_params *pms);

// Flood Fill
char		**ft_map_copy(char **map);
int			ft_floodfill(t_params *pms);
void		ft_exit_found(char **map_copy, int *exit, size_t x, size_t y);
int			ft_ffalgorithm(char **map_copy, size_t x, size_t y, int *exit);
size_t		ft_count_collectibles(char **map);

// Pictures
t_image		*ft_make_picture_xpm(char *relative_path, t_params *par);
void		ft_build_all_images_player(t_params *pms, t_pictures *comps);
void		ft_build_all_images_enemy(t_params *pms, t_pictures *comps);
t_pictures	*ft_build_all_images(t_params *pms);

// Player
			// 1
void		ft_eat_collectible(t_params *pms);
void		ft_set_player_frames(t_params *pms);
void		ft_keys(t_params *pms);
void		ft_put_player(t_params *pms, size_t x, size_t y);

			// 2
size_t		ft_find_player_x(char **map);
size_t		ft_find_player_y(char **map);
void		ft_print_moves(t_params *pms);

// End Program

			// 1
void		ft_win(t_params *pms, size_t x, size_t y);
void		ft_win2(t_params *pms, size_t x, size_t y);
void		ft_errors(t_params *pms, char *message, int i);
void		ft_free_enemies(t_params *pms);
void		ft_freeparams_enemies(t_params *pms);

			// 2
void		ft_freeparams_dying(t_params *pms);
void		ft_freeparams_player2(t_params *pms);
void		ft_freeparams_player(t_params *pms);
void		ft_freeparams(t_params *pms, int i);
int			ft_close_window(t_params *pms);

#endif
