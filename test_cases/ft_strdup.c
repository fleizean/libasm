#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/color.h"

extern char* _ft_strdup(char *src);

int main(int ac, char **av)
{
    if (ac != 2)
    {
        printf(BRED "Usage: ./ft_strdup [string]\n" reset);
        return (1);
    }

    char *str = _ft_strdup(av[1]);
    char *str2 = strdup(av[1]);

    if (strcmp(str, str2) == 0)
        printf(BGRN "OK\n" reset);
    else
        printf(RED "KO\n" reset);
}

/*
Kullanım:
# NASM ile _ft_strdup.asm dosyasını derleme
nasm -f elf64 ft_strdup.asm -o ft_strdup.o

# C kodunu GCC kullanarak derleme ve bağlama
gcc -o ft_strdup ft_strdup.o main.c

# Oluşturulan yürütülebilir dosyayı çalıştırma
./ft_strdup "Hello, World!" "Hello, World!"
*/