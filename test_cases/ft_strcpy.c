#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/color.h"

extern char *_ft_strcpy(char*dest, char*src);

int main(int ac, char **av)
{
    if (ac != 3)
    {
        printf(BRED "Usage: ./ft_strcpy [string] [string2]\n" reset);
        return 1;
    }
    
    
    if(strcpy(av[1],av[2]) == _ft_strcpy(av[1],av[2]))
        printf(BYEL "OK\n" reset);
    else
        printf(BRED "KO\n" reset);
}

/*
Kullanım:
# NASM ile _ft_strcpy.asm dosyasını derleme
nasm -f elf64 ft_strcpy.asm -o ft_strcpy.o

# C kodunu GCC kullanarak derleme ve bağlama
gcc -o ft_strcpy ft_strcpy.o main.c

# Oluşturulan yürütülebilir dosyayı çalıştırma
./ft_strcpy "Hello, World!" "Hello, World!"
*/