/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:45:50 by alamy             #+#    #+#             */
/*   Updated: 2018/01/04 14:55:54 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int my_key_funct(int keycode, t_pixel *param)
{
	if (keycode == 53)
	{	
		exit(0);
	}
	// printf("key event %d\n", keycode);
	return(0);
}

int ft_first_block(t_pixel *tmp, int h_max, int l_max)
{
	int x; 
	int y;
	
	x = 25;
	while (x < l_max)
	{
		y = 50;
		while(y < h_max)
		{
			if (y == 50)
				mlx_pixel_put(tmp->mlx, tmp->win, x, y, 0x00FF00FF);
			if (x == 25)
				mlx_pixel_put(tmp->mlx, tmp->win, x, y, 0x000000FF);
			if (y == h_max - 1) // 199
				mlx_pixel_put(tmp->mlx, tmp->win, x, y, 0x000000FF);
			if (x == l_max - 1) // 199
				mlx_pixel_put(tmp->mlx, tmp->win, x, y, 0x00FF00FF);
			// if (y == h_max - 1 && x == l_max - 1)
			// 	return (ft_first_block(tmp, h_max - 5, l_max - 6));
			y++;
		}
		x++;
	}
	return (1);
}

int main(void)
{
	t_pixel *tmp;
	int h_max;
	int l_max;
	
	h_max = 200;
	l_max = 200;
	tmp = (t_pixel*)malloc(sizeof(t_pixel));
	tmp->mlx = mlx_init();
	tmp->win = mlx_new_window(tmp->mlx, 1000, 1000, "mlx 42");

	ft_first_block(tmp, h_max, l_max);
	
	mlx_key_hook(tmp->win, my_key_funct, 0);
	mlx_loop(tmp->mlx);
	return(0);
}
