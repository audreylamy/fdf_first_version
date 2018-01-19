/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_translation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:55:35 by alamy             #+#    #+#             */
/*   Updated: 2018/01/19 11:50:34 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrice *matrice_translation(t_pixel *tmp)
{
	t_matrice *m_translation;
	
	m_translation = (t_matrice*)malloc(sizeof(t_matrice));
	m_translation->a1 = 1;
	m_translation->a2 = 0;
	m_translation->a3 = 0;
	m_translation->a4 = (WINDOW_L / 2) - ((tmp->lenght * TILE_WIDTH) / 2);
	m_translation->b1 = 0;
	m_translation->b2 = 1;
	m_translation->b3 = 0;
	m_translation->b4 = (WINDOW_H / 2) - ((tmp->nb_line * TILE_HEIGHT) / 2);
	return(m_translation);
}

int translationX_center(int x, int y, int z, t_matrice *m_translation)
{
	int x1;
	int w;

	w = 1;
	x1 = (m_translation->a1 * x) + (m_translation->a2 * y) + 
		(m_translation->a3 * z) + (m_translation->a4 * w);
	return(x1);
}

int translationY_center(int x, int y, int z, t_matrice *m_translation)
{
	int y1;
	int w;

	y1 = (m_translation->b1 * x) + (m_translation->b2 * y) + 
		(m_translation->b3 * z) + (m_translation->b4 * w);
		ft_putnbr(y1);
		ft_putchar(' ');
	return(y1);
}


	// ft_putstr("m_translation.a1 * x = ");
		// ft_putnbr(m_translation.a1 * x);
		// ft_putchar('\n');
		// ft_putstr("m_translation.a2 * y = ");
		// ft_putnbr(m_translation.a2 * y);
		// ft_putchar('\n');
		// ft_putstr("m_translation.a3 * z = ");
		// ft_putnbr(m_translation.a3 * z);
		// ft_putchar('\n');
		// ft_putstr("m_translation.a4 * w = ");
		// ft_putnbr(m_translation.a4 * w);
		// ft_putchar('\n');
		// ft_putnbr(x1);
		// ft_putchar(' ');


// t_matrice matrice_base(void)
// {
// 	t_matrice m_model_view;
	
// 	m_model_view.a1 = '1';
// 	m_model_view.a2 = '0';
// 	m_model_view.a3 = '0';
// 	m_model_view.a4 = '0';
// 	m_model_view.b1 = '0';
// 	m_model_view.b2 = '1';
// 	m_model_view.b3 = '0';
// 	m_model_view.b4 = '0';
// 	m_model_view.c1 = '0';
// 	m_model_view.c2 = '1';
// 	m_model_view.c3 = '0';
// 	m_model_view.c4 = '0';
// 	m_model_view.b1 = '0';
// 	m_model_view.b2 = '0';
// 	m_model_view.b3 = '0';
// 	m_model_view.b4 = '1';
// 	return(m_model_view);
// }
