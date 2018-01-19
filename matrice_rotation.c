/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:29:40 by alamy             #+#    #+#             */
/*   Updated: 2018/01/19 11:53:06 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrice *matrice_rotationX(t_pixel *tmp, double alpha)
{
	t_matrice *m_rotationX;
	
	m_rotationX = (t_matrice*)malloc(sizeof(t_matrice));
	m_rotationX->a1 = 1;
	m_rotationX->b2 = cos(alpha);
	m_rotationX->b3 = -sin(alpha);
	m_rotationX->c2 = sin(alpha);
	m_rotationX->c3 = cos(alpha);
	m_rotationX->d4 = 1;
	return(m_rotationX);
}

t_matrice *matrice_rotationY(t_pixel *tmp, double alpha)
{
	t_matrice *m_rotationY;
	
	m_rotationY = (t_matrice*)malloc(sizeof(t_matrice));
	m_rotationY->a1 = cos(alpha);
	m_rotationY->a3 = sin(alpha);
	m_rotationY->b2 = 1;
	m_rotationY->c1 = -sin(alpha);
	m_rotationY->c3 = cos(alpha);
	m_rotationY->d4 = 1;
	return(m_rotationY);
}

t_matrice *matrice_rotationZ(t_pixel *tmp, double alpha)
{
	t_matrice *m_rotationZ;
	
	m_rotationZ = (t_matrice*)malloc(sizeof(t_matrice));
	m_rotationZ->a1 = cos(alpha);
	m_rotationZ->a2 = -sin(alpha);
	m_rotationZ->b1 = sin(alpha);
	m_rotationZ->b2 = cos(alpha);
	m_rotationZ->c3 = 1;
	m_rotationZ->d4 = 1;
	return(m_rotationZ);
}


