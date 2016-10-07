rm linked part2.o as.lis asm.o
gcc -c part2.c -o part2.o
nasm -f elf32 assSbr.asm -l as.lis -o asm.o
gcc part2.o asm.o -o linked
./linked input2d.txt
