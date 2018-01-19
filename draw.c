/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:58:12 by alamy             #+#    #+#             */
/*   Updated: 2018/01/19 12:17:50 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int my_key_funct(int keycode, t_pixel *param)
{
	if (keycode == 53)
	{	
		exit(0);
	}
	return(0);
}

void ft_draw_point(z_list *list, t_pixel *tmp)
{
	int i;
	int j;
	int x;
	int y;
	int z;

	int x1;
	int y1;
	t_matrice *m_translation;

	i = 0;
	m_translation = matrice_translation(tmp);
	while (list != NULL && i < tmp->nb_line)
	{
		while (j < tmp->lenght)
		{
			x = list->content[j].x;
			y = list->content[j].y;
			z = list->content[j].z;

			x = j * (TILE_WIDTH / 2); 
			y = i * (TILE_HEIGHT / 2);
			x1 = (translationX_center(x, y, z, m_translation));
			y1 = (translationY_center(x, y, z, m_translation));
			mlx_pixel_put(tmp->mlx, tmp->win, x / (z + 1) + x1, 
							y / (z + 1) + y1, 0x00FF00FF);
			j++;
		}
		j = 0;
		i++;
		list = list->next;
	}
}
