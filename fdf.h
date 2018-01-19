/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:49:43 by alamy             #+#    #+#             */
/*   Updated: 2018/01/19 11:39:37 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 32
# define WINDOW_L 1000
# define WINDOW_H 800
# define TILE_WIDTH 30
# define TILE_HEIGHT 30
# include "minilibx/mlx.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"

typedef struct matrice
  {
	float a1;
	float a2;
	float a3;
	float a4;
	float b1;
	float b2;
	float b3;
	float b4;
	float c1;
	float c2;
	float c3;
	float c4;
	float d1;
	float d2;
	float d3;
	float d4;
  } 			t_matrice;

typedef struct s_data
{
	int x;
	int y; 
	int z;
	char *color;
}				t_data;

typedef struct p_list
{
	t_data *content;
	struct p_list *next;
}				z_list;

typedef struct	s_pixel
{
	void *mlx;
	void *win;
	void *img;
	int nb_line;
	int lenght;
}				t_pixel;

int ft_nb_line(char **argv);
int	ft_getnbr(char *str);
int ft_lenght(char **str);
void ft_print_list(z_list *list, int nb_line);
void ft_draw_point(z_list *list, t_pixel *tmp);
int my_key_funct(int keycode, t_pixel *param);
int main(int argc, char **argv);

/*MATRICE*/
// t_matrice matrice_base(void);
t_matrice matrice_base(void);
t_matrice *matrice_translation(t_pixel *tmp);
t_matrice *matrice_rotationX(t_pixel *tmp, double alpha);
t_matrice *matrice_rotationY(t_pixel *tmp, double alpha);
t_matrice *matrice_rotationZ(t_pixel *tmp, double alpha);
int translationX_center(int x, int y, int z, t_matrice *m_translation);
int translationY_center(int x, int y, int z, t_matrice *m_translation);

#endif