#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/color.h"

extern int _ft_strcmp(char *s1, char *s2);

int main(int ac, char **av)
{
    if (ac != 3)
    {
        printf(BRED "Usage: ./ft_strcmp [string] [string2]\n" reset);
        return 1;
    }
    
    
    if(strcmp(av[1],av[2]) == _ft_strcmp(av[1],av[2]))
        printf(BYEL "OK\n" reset);
    else
        printf(BRED "KO\n" reset);
}

/*
Kullanım:
# NASM ile _ft_strcmp.asm dosyasını derleme
nasm -f elf64 ft_strcmp.asm -o ft_strcmp.o

# C kodunu GCC kullanarak derleme ve bağlama
gcc -o ft_strcmp ft_strcmp.o main.c

# Oluşturulan yürütülebilir dosyayı çalıştırma
./ft_strcmp "Hello, World!" "Hello, World!"
*/