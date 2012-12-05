/*
** cw.h for corewar in /home/sfez_a//Local/projets_local/corewar/asm/include
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Wed Dec  5 12:18:55 2012 arthur sfez
** Last update Wed Dec  5 16:12:07 2012 arthur sfez
*/

struct lab_adr_s
{
  char			*label;
  int			bgn_adr;
  struct lab_adr_s	*next;
};

typedef struct lab_adr_s	lab_adr_t;
