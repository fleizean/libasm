#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/color.h"

extern int _ft_strlen(char*dest);

int main(int ac, char **av)
{
    if (ac != 2)
    {
        printf(BRED "Usage: ./ft_strlen \"string\"\n" reset);
        return 1;
    }
    
    if(_ft_strlen(av[1]) == strlen(av[1]))
        printf(BYEL "OK\n" reset);
    else
        printf(BRED "KO\n" reset);
}

/*
Kullanım:
# NASM ile _ft_strlen.asm dosyasını derleme
nasm -f elf64 ft_strlen.asm -o ft_strlen.o

# C kodunu GCC kullanarak derleme ve bağlama
gcc -o ft_strlen ft_strlen.o main.c

# Oluşturulan yürütülebilir dosyayı çalıştırma
./ft_strlen "Hello, World!"
*/