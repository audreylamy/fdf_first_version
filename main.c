/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:09:40 by alamy             #+#    #+#             */
/*   Updated: 2018/01/18 17:12:40 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

z_list **ft_read_stock(char *line, int index, z_list **begin_list, t_pixel *tmp)
{
	int			i;
    int         z;
	static int  x;
	int			a;
	char		**str;
    
	i = 0;
    z = 0;
	a = 0;
	str = ft_strsplit(line, ' ');
	tmp->lenght = ft_lenght(str);
	*begin_list = (z_list*)malloc(sizeof(z_list));
	(*begin_list)->content = (t_data*)malloc(sizeof(t_data) * tmp->lenght);
    while (str[i] != '\0')
    {
		(*begin_list)->content[i].x = x;
        (*begin_list)->content[i].y = index;
		if (ft_strchr(str[i], ',')) 
		{
			(*begin_list)->content[i].z = ft_getnbr(str[i]);
			a = 0;
			while (str[i][a] != '\0')
			{
				if (str[i][a] == ',')
				{
					(*begin_list)->content[i].color = &str[i][a + 1];
				}
				a++;
			}
		}
	    else
		{
			(*begin_list)->content[i].color = "0xFFFFFF";    
			(*begin_list)->content[i].z = ft_getnbr(str[i]);
		}
		i++;
		x++;
    }
	(*begin_list)->next = NULL;
	begin_list = &(*begin_list)->next;
    return (begin_list);
}

int	main(int argc, char **argv)
{
	char *line;
	z_list *new_list;
	z_list **begin_list;
	t_pixel *tmp;
	int index;
	int fd;

	index = 0;
	if (argc != 2)
		return(0);
	line = NULL;
	tmp = (t_pixel*)malloc(sizeof(t_pixel));
	tmp->nb_line = ft_nb_line(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	begin_list = &new_list;
	while (get_next_line(fd, &line) > 0)
	{	
		if (index == tmp->nb_line)
			break;
		begin_list = ft_read_stock(line, index, begin_list, tmp);
		index++;
	}
	tmp->mlx = mlx_init();
	tmp->win = mlx_new_window(tmp->mlx, WINDOW_L, WINDOW_H, "mlx 42");
	// ft_print_list(new_list, tmp->nb_line);
	ft_draw_point(new_list, tmp);
	// ft_algo(new_list, tmp);
	mlx_key_hook(tmp->win, my_key_funct, 0);
	mlx_loop(tmp->mlx);
	free(line);
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return (1);
	}
	return (0);
}
