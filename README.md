corewar
=======

War of processes on memory field, simple compiler and VM

bin/asm - compiler
bin/corewar - Virtual Machine, support big-endian and little-endian systems
champ/fenix.s - example of player program

## options

* corewar [path to player program] [] [] []
* corewar -aff_shell : verbose mode
* corewar -die_msg : show when programs processes die
* corewar -old_style : change mode to old version of project subject  

## example

```
make
cd bin
./asm ../champ/fenix.s
./corewar -aff_shell ../champ/fenix.cor ../champ/fenix.cor
```
