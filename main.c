/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:00:33 by bgerda            #+#    #+#             */
/*   Updated: 2019/11/23 18:02:02 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	upload_line(t_point *half, int x, int y)
{
	t_pix start;
	t_pix end;

	if (x < half->max_x - 1)
	{
		start = complect_t_pix(half, x, y);
		end = complect_t_pix(half, x + 1, y);
		charge_draw(&start, half);
		charge_draw(&end, half);
		drawline(start, end, half);
	}
	if (y < half->max_y - 1)
	{
		start = complect_t_pix(half, x, y);
		end = complect_t_pix(half, x, y + 1);
		charge_draw(&start, half);
		charge_draw(&end, half);
		drawline(start, end, half);
	}
}

int		draw_point(t_point *half)
{
	int x;
	int y;

	y = 0;
	while (half->axis[y])
	{
		x = 0;
		while (half->axis[y][x])
		{
			upload_line(half, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	open_window(t_point *half)
{
	draw_point(half);
	mlx_put_image_to_window(half->mlx_ptr, half->window, half->map, 0, 0);
	set_hooks(half);
	mlx_loop(half->mlx_ptr);
}

int		main(int ac, char **av)
{
	char	*input;
	int		fd;
	t_point half;

	if (ac != 2)
	{
		ft_putstr("usage: ./fdf source_file\n");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putstr("Unreadable file!\n");
		return (0);
	}
	input = ft_undin(fd);
	close(fd);
	zero_to_half(&half, input);
	free(input);
	open_window(&half);
	return (0);
}
