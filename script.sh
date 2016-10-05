rm linked part1.o as.lis asm.o
gcc -c part1.c -o part1.o
nasm -f elf32 assemblySubroutine.asm -l as.lis -o asm.o
gcc part1.o asm.o -o linked
./linked input1d.txt
