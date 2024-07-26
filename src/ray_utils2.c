/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils2.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:47:37 by okrahl            #+#    #+#             */
/*   Updated: 2024/07/16 16:22:50 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cubed3D.h"

int	check_real_wall_x(char **map, t_point point, t_data *data)
{
	char	tile1;
	char	tile2;

	printf("test x\n");
	printf( "point x %f\n",point.x );
	printf( "point y %f\n",point.y );
	printf("result_x t1%i\n", (int)point.x / data->settings->tile_size);
	printf("result_y t1%i\n", (int)point.y / data->settings->tile_size);
	// printf("%c\n", map[(int)point.x / data->settings->tile_size][(int)point.y / data->settings->tile_size]);
	printf("%c\n", map[4][24]);

	printf("result_x t2%i\n", (int)point.x / data->settings->tile_size - 1);
	printf("result_y t2%i\n", (int)point.y / data->settings->tile_size);

	printf("test after  xxxx\n");
	tile1 = map[(int)point.x / data->settings->tile_size][(int)point.y / data->settings->tile_size];
	tile1 = 'c';

	tile2 = map[(int)point.x / data->settings->tile_size - 1][(int)point.y / data->settings->tile_size];
	printf("test after\n");
	if( tile1 == '1' || tile2 == '1')
		return (1);
	return (0);
}


int	check_real_wall_y(char **map, t_point point, t_data *data)
{
	char	tile1;
	char	tile2;

	printf("result_x t1%i\n", (int)point.x / data->settings->tile_size);
	printf("result_y t1%i\n", (int)point.y / data->settings->tile_size);

	printf("result_x t2%i\n", (int)point.x / data->settings->tile_size);
	printf("result_y t2%i\n", (int)point.y / data->settings->tile_size - 1);
	printf("test after yyyy\n");
	tile1 = data->map[(int)point.x / data->settings->tile_size][(int)point.y / data->settings->tile_size];
	printf("test after\n");
	tile2 = map[(int)point.x / data->settings->tile_size][(int)point.y / data->settings->tile_size -1];
	if( tile1 == '1' || tile2 == '1')
		return (1);
	return (1);
}

int	check_real_corner(char **map, t_point point, t_data *data)
{
	// char	tile1;
	// char	tile2;
	// char	tile3;
	// char	tile4;

	printf("test corner\n");
	printf("char: %c\n", map[4][4]);
	printf("tile1 %d %d\n", (int)point.x / data->settings->tile_size, (int)point.y / data->settings->tile_size);
	// tile1 = map[(int)point.x / data->settings->tile_size][(int)point.y / data->settings->tile_size];
	// printf("char: %c\n", tile1);
	// printf("tile2 %d %d \n", (int)point.x / data->settings->tile_size- 1, (int)point.y / data->settings->tile_size);
	// tile2 = map[(int)point.x / data->settings->tile_size - 1][(int)point.y / data->settings->tile_size];
	// printf("char: %c\n", tile2);
	// printf("tile3  %d %d \n", (int)point.x / data->settings->tile_size,(int)point.y / data->settings->tile_size- 1);
	// tile3 = map[(int)point.x / data->settings->tile_size][(int)point.y / data->settings->tile_size- 1];
	// printf("char: %c\n", tile3);
	// printf("tile4  %d %d \n", (int)point.x / data->settings->tile_size - 1,(int)point.y / data->settings->tile_size- 1);
	// tile4 = map[(int)point.x / data->settings->tile_size- 1][(int)point.y / data->settings->tile_size- 1];
	// printf("char: %c\n", tile4);
	// if( tile1 == '1' || tile2 == '1' || tile3 == '1' || tile4 == '1' )
	// 	return(1);
	return (1);
}

int	is_grid(float f, t_data *data)
{
	if ((int)f % data->settings->tile_size == 0)
	{
		return (1);
	}
	return (0);
}

t_point	*check_real_intersections(t_point *var_sects, t_point *true_sect, t_data *data)
{
	int		i;

	i = 0;
	// printf("ts x: %f\n",true_sect->x);
	// printf("ts y: %f\n",true_sect->y);
	printf("test\n");
	while (var_sects[i].x != -1.0f || var_sects[i].y != -1.0f)
	{
		// if (is_grid(var_sects[i].x, data) && is_grid(var_sects[i].y, data) && check_real_corner(data->row_grid, var_sects[i], data))
		// {
		// 	true_sect->x = var_sects[i].x; // true_sect = check_real_corner(data->map, &var_sects[i], true_sect);
		// 	true_sect->y = var_sects[i].y;
		// 	printf("grid c\n");
		// }
		if ( is_grid(var_sects[i].y, data) && check_real_wall_y(data->map, var_sects[i], data))
		{
			true_sect->x = var_sects[i].x; // true_sect = check_real_wall(data->map, &var_sects[i], true_sect);
			true_sect->y = var_sects[i].y;
			printf("grid y\n");
		}
		if ( is_grid(var_sects[i].x, data) && check_real_wall_x(data->map, var_sects[i], data))
		{
			true_sect->x = var_sects[i].x; // true_sect = check_real_wall(data->map, &var_sects[i], true_sect);
			true_sect->y = var_sects[i].y;
			printf("grid x\n");
		}
		i++;
		printf("ts x: %f\n",true_sect->x);
		printf("ts y: %f\n",true_sect->y);
	}

	return (true_sect);
}