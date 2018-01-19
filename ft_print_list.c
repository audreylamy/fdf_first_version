/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:18:55 by alamy             #+#    #+#             */
/*   Updated: 2018/01/19 10:07:25 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void ft_print_list(z_list *list, int nb_line)
{
	int k;
	z_list *tmp; 

	k = 0;
    tmp = list;
    if (tmp == NULL)
    {
        ft_putstr("erreur");
    }
    while (tmp)
    {
		k = 0;
		while(k < 18)
		{
       		// printf("%d", tmp->content[k].x);
        	printf("%d", tmp->content[k].y);
        	// printf("%d", tmp->content[k].z);
			k++;
		}
        tmp = tmp->next;
    }
}