/*
** my_endian_convert.c for cwlib in /home/ignati_i//projects/corewar/corewar-2016ed-2015s-2017si-liu_q/lib
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Fri Dec  7 16:53:25 2012 ivan ignatiev
** Last update Fri Dec  7 17:28:06 2012 ivan ignatiev
*/

#include	<sys/types.h>
#include	"cwlib.h"

/*
 * Example of usign:
 * int b;
 * b = 1010000000000000000000000000000000000000000000000000000000000000b
 * b = (int)conv_to_platform(&b, sizeof(b));
 * printf("%d\n", b);
 * Output: 5
 */

char 		*my_conv_to_platform(char *buf, size_t sz)
{
  if (is_big_endian())
    return (buf);
  else
    {
      
      return (buf);
    }
}
