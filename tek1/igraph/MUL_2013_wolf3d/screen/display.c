/*
** display.c for wolf3d in /home/gicque_p/local/igraph/MUL_2013_wolf3d2
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Jan  5 23:52:02 2014 Pierrick Gicquelais
** Last update Mon Apr 14 12:40:27 2014 Pierrick Gicquelais
*/

#include	"../include/wolf.h"

int		my_pixel_put_to_image(t_numb *numb, t_color *color, char *data)
{
  int		pixel;

  pixel = (numb->x * numb->bpp / 8) + (numb->y * numb->sizeline);
  if (numb->bpp == 0 || numb->sizeline == 0)
    my_error("Bits per pixel or Sizeline null");
  data[pixel] = color->blue_pixel;
  data[pixel + 1] = color->green_pixel;
  data[pixel + 2] = color->red_pixel;
  data[pixel + 3] = 0;
  return (0);
}

void		display_wall(t_wolf *wolf, t_numb *numb)
{
  double	k;

  k = 0;
  numb->x = 0;
  while (numb->x < WIN_LENGHT)
    {
      numb->y = 0;
      k = algo_raycasting(wolf->ptr, wolf->algo, numb);
      numb->wall = abs((int)(WIN_WIDTH / k));
      while (numb->y < WIN_WIDTH)
	{
	  my_color(wolf->color, wolf->algo, numb->wall, numb->y);
	  my_pixel_put_to_image(numb, wolf->color, wolf->ptr->data);
	  numb->y++;
	}
      numb->x++;
    }
}

void		display_minimap(t_wolf *wolf, t_numb *numb)
{
  numb->x = WIN_LENGHT - 240;
  while (numb->x <= WIN_LENGHT - 40)
    {
      numb->y = WIN_WIDTH - 240;
      while (numb->y <= WIN_WIDTH - 40)
	{
	  my_minimap_color(wolf, numb, wolf->color);
	  my_pixel_put_to_image(numb, wolf->color, wolf->ptr->data);
	  numb->y++;
	}
      numb->x++;
    }
}
