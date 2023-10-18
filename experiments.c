/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:25:29 by mvalerio          #+#    #+#             */
/*   Updated: 2023/09/29 11:21:37 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "so_long.h"

/* #define WIDTH 1920
#define HEIGHT 1080 */

#define WIDTH 800
#define HEIGHT 800

int		ft_rgb_to_int(int t, int r, int g, int b)
{
	int	colour;

	colour = t << 24 | r << 16 | g << 8 | b;
	return (colour);
}

// Rainbow order might be wrong, not properly tested
int		ft_rainbow_order(int *t, int *r, int *g, int *b)
{
	if (*r == 255 && *g == 0 && *b < 255)
		(*b)++;
	else if (*r > 0 && *g == 0 && *b == 255)
		(*r)--;
	else if (*r == 0 && *g < 255 && *b == 255)
		(*g)++;
	else if (*r == 0 && *g == 255 && *b > 0)
		(*b)--;
	else if (*r < 255 && *g == 255 && *b == 0)
		(*r)++;
	else if (*r == 255 && *g > 0 && *b == 0)
		(*g)--;
	return (ft_rgb_to_int(*t, *r, *g, *b));
}

int		ft_black_to_white(int *t ,int *r, int *g, int *b)
{
	if ((*r != *g || *g != *b || *r != *b) || \
	(*r == 255 && *g == 255 && *b == 255))
	{
		*r = 0;
		*g = 0;
		*b = 0;
	}
	else
	{
	(*r)++;
	(*g)++;
	(*b)++;
	}
	return (ft_rgb_to_int(*t, *r, *g, *b));
}

void	ft_pixel_put(image *img, int x, int y, int color)
{
	char	*place;

	place = img->addr + (x * (img->pixel_bits / 8) + y * img->line_bytes);
	*(unsigned int *)place = color;
}

void	ft_hor_line(image *picture, int colour, int start, int end, int y)
{
	while (start < end)
	{
		ft_pixel_put(picture, start, y, colour);
		start++;
	}
}

void	ft_make_rhombus(image *picture, int colour)
{
	int radius;
	int	x;
	int	y;
	int	line;

	radius = 250;
	line = 0;
	y = HEIGHT / 2 - radius;
	x = WIDTH / 2;
	while (y < (HEIGHT / 2))
	{
		ft_hor_line(picture, colour, x - line, x + line, y);
		line++;
		y++;
	}
	while (y < (HEIGHT / 2 + radius))
	{
		ft_hor_line(picture, colour, x - line, x + line, y);
		line--;
		y++;
	}
}

void	ft_make_circle(image *picture, int colour)
{
	int radius;
	int	x;
	int	angle;
	int	cos_circle;
	int	y_circle;

	radius = 50;
	x = WIDTH / 2;
	angle = -90;
	while (angle <= 90)
	{
		cos_circle = cos(angle*(M_PI/180)) * radius;
		y_circle = HEIGHT / 2 + (sin(angle*(M_PI/180)) * radius);
		ft_hor_line(picture, colour, x - cos_circle, x + cos_circle, y_circle);
		angle++;
	}
}

/* image	*ft_scale_image(params *parameters, image *old_image, int scale_factor)
{
	image	*new_image;
	int		x;

	x = 0;
	new_image = malloc(sizeof(image));
	if (!new_image)
		return (0);
	new_image->width = old_image->width * scale_factor;
	new_image->height = old_image->height * scale_factor;

} */

int	key_press(int keycode, params *parameters)
{
	if (keycode==0xff1b)
	{
		mlx_destroy_window(parameters->game, parameters->window);
		exit(0);
	}
	if (keycode==0x0061)
	{
	image	*square;

			square = malloc(sizeof(image));
	if (!square)
		return (0);
	square->width = WIDTH;
	square->height = HEIGHT;
	square->img = mlx_new_image(parameters->game, square->width, square->height);
	square->addr = mlx_get_data_addr(square->img, &(square->pixel_bits), &(square->line_bytes), &(square->endian));
	ft_make_rhombus(square, ft_rgb_to_int(120, 0, 255, 0));
	mlx_put_image_to_window(parameters->game, parameters->window, square->img, 0, 0);


	}

	if (keycode==0x0073)
	{
	image	*character;
	char	*relative_path = "./Images/background.xpm";


		int		img_width;
		int		img_height;
	character = malloc(sizeof(image));
	if (!character)
		return (0);
	character->img = mlx_xpm_file_to_image(parameters->game, relative_path, &img_width, &img_height);
	character->addr = mlx_get_data_addr(character->img, &(character->pixel_bits), &(character->line_bytes), &(character->endian));
	mlx_put_image_to_window(parameters->game, parameters->window, character->img, 0, 0);
	mlx_put_image_to_window(parameters->game, parameters->window, character->img, 140, 0);
	mlx_put_image_to_window(parameters->game, parameters->window, character->img, 0, 140);
	mlx_put_image_to_window(parameters->game, parameters->window, character->img, 140, 140);
	mlx_put_image_to_window(parameters->game, parameters->window, character->img, 0, 280);
	mlx_put_image_to_window(parameters->game, parameters->window, character->img, 140, 280);
	mlx_put_image_to_window(parameters->game, parameters->window, character->img, 0, 420);
	mlx_put_image_to_window(parameters->game, parameters->window, character->img, 140, 420);
		mlx_put_image_to_window(parameters->game, parameters->window, character->img, 0, 560);
	mlx_put_image_to_window(parameters->game, parameters->window, character->img, 140, 560);


	}




	return (0);
}

int	ft_mouse_press(int button, int x, int y, void *param)
{
	if (button == 1 && x < WIDTH && y < HEIGHT)
		mlx_clear_window(((params *)param)->game, ((params *)param)->window);
	return (0);
}

int	ft_close_window (void *param)
{
	mlx_destroy_window(((params *)param)->game, ((params *)param)->window);
	exit (0);
}

int main()
{
	params *parameters;

	parameters = malloc(sizeof(params));
	if (!parameters)
		return (0);
	parameters->game = mlx_init();
	parameters->window = mlx_new_window(parameters->game, WIDTH, HEIGHT, "Maggieland");
	int	*r;
	r = malloc(sizeof(int *));
	*r = 255;
	int	*g;
	g = malloc(sizeof(int*));
	*g = 0;
	int	*b;
	b = malloc(sizeof(int*));
	*b = 0;
	int	*t;
	t = malloc(sizeof(int*));

	mlx_key_hook(parameters->window, key_press, parameters);
	mlx_mouse_hook(parameters->window, ft_mouse_press, parameters);
	mlx_hook(parameters->window, 17,0, ft_close_window, parameters);


	mlx_loop(parameters->game);
}

// SQUARE MAKER FUNCTION

/* z = HEIGHT/2-HEIGHT/4;

while (z < HEIGHT/2+HEIGHT/4)
{

	a = WIDTH/2-HEIGHT/4;
	while (a < WIDTH/2+HEIGHT/4)
		ft_pixel_put(&square, a++, z, colour));
	z++;
}
} */
