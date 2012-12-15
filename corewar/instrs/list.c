/*
** list.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Dec 15 01:39:36 2012 ivan ignatiev
** Last update Sat Dec 15 02:48:07 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"op.h"
#include	"corewar.h"

static void	cw_memr_instrs(t_prog_instr *instrs)
{
  instrs[2].func = cw_instr_ld;
  instrs[2].enc_byte = 1;
  instrs[3].func = cw_instr_st;
  instrs[3].enc_byte = 1;
  instrs[10].func = cw_instr_ldi;
  instrs[10].enc_byte = 1;
  instrs[11].func = cw_instr_sti;
  instrs[11].enc_byte = 1;
  instrs[13].func = cw_instr_lld;
  instrs[13].enc_byte = 1;
  instrs[14].func = cw_instr_lldi;
  instrs[14].enc_byte = 1;
}

static void	cw_flow_instrs(t_prog_instr *instrs)
{
  instrs[1].func = cw_instr_live;
  instrs[1].enc_byte = 0;
  instrs[9].func = cw_instr_zjmp;
  instrs[9].enc_byte = 0;
  instrs[12].func = cw_instr_fork;
  instrs[12].enc_byte = 0;
  instrs[15].func = cw_instr_lfork;
  instrs[15].enc_byte = 0;
  instrs[16].func = cw_instr_aff;
  instrs[16].enc_byte = 1;
}

static void	cw_math_instrs(t_prog_instr *instrs)
{
  instrs[4].func = cw_instr_add;
  instrs[4].enc_byte = 1;
  instrs[5].func = cw_instr_sub;
  instrs[5].enc_byte = 1;
}

static void	cw_binr_instrs(t_prog_instr *instrs)
{
  instrs[6].func = cw_instr_and;
  instrs[6].enc_byte = 1;
  instrs[7].func = cw_instr_or;
  instrs[7].enc_byte = 1;
  instrs[8].func = cw_instr_xor;
  instrs[8].enc_byte = 1;
}

t_prog_instr	*cw_instrs_list()
{
  t_prog_instr	*instrs;

  if ((instrs = (t_prog_instr*)malloc(sizeof(t_prog_instr) * 17)) != NULL)
    {
      instrs[0].func = NULL;
      instrs[0].enc_byte = 0;
      cw_memr_instrs(instrs);
      cw_flow_instrs(instrs);
      cw_math_instrs(instrs);
      cw_binr_instrs(instrs);
    }
  return (instrs);
}
