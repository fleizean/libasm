#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../includes/color.h"

extern int _ft_strcmp(char *s1, char *s2);
extern char *_ft_strcpy(char *dest, char *src);
extern char *_ft_strdup(char *src);
extern int _ft_strlen(char *dest);



char* strcmpTester(char *str1, char *str2)
{
    if (strcmp(str1, str2) == _ft_strcmp(str1, str2))
        return BGRN "strcmp -> OK\n" reset;
    return BRED "strcmp -> KO\n" reset;
}

char* strcpyTester(char *str1, char *str2)
{
    if (strcmp(strcpy(str1, str2), _ft_strcpy(str1, str2)) == 0)
        return BGRN "strcpy -> OK\n" reset;
    return BRED "strcpy -> KO\n" reset;
}

char* strdupTester(char *str1)
{
    if (strcmp(strdup(str1), _ft_strdup(str1)) == 0)
        return BGRN "strdup -> OK\n" reset;
    return BRED "strdup -> KO\n" reset;
}

char* strlenTester(char *str1)
{
    if (strlen(str1) == _ft_strlen(str1))
        return BGRN "strlen -> OK\n" reset;
    return BRED "strlen -> KO\n" reset;
}

char* writeTester(char *str1)
{
    return BRED "write -> KO" reset;
}

char* readTester(char *str1)
{
    return BRED "read -> KO" reset;
}

int processWork(int process, char *str1, char *str2)
{
    char **processes = (char *[]){"strlen", "strcmp", "strcpy", "strdup", "write", "read"};
    printf("=======================================================================\n");
    printf(BYEL "Testing :: %s\n" reset, processes[process - 1]);
    printf("=======================================================================\n");

    char *result;
    switch (process)
    {
        case 1:
            result = strlenTester(str1);
            printf("%s", result);
            break;
        case 2:
            result = strcmpTester(str1, str2);
            printf("%s", result);
            break;
        case 3:
            result = strcpyTester(str1, str2);
            printf("%s", result);
            break;
        case 4:
            result = strdupTester(str1);
            printf("%s", result);
            break;
        case 5:
            printf(BRED "write -> KO\n" reset);
            break;
        case 6:
            printf(BRED "read -> KO\n" reset);
            break;
        case 7:
            printf("%s", strlenTester(str1));
            printf("%s", strcmpTester(str1, str2));
            printf("%s", strcpyTester(str1, str2));
            printf("%s", strdupTester(str1));
            printf(BRED "write -> KO\n" reset);
            printf(BRED "read -> KO\n" reset);
            break;
        default:
            printf(BRED "Usage: ./a.out [Process Number or help] [1. String] [2. String]\n" reset);
            return 1;
    }
    printf("=======================================================================\n");
    return 0;
}

/*
    Kullanım:
    # ./a.out <Process Number> <1. String> <2. String>
    # ./a.out <help>
*/
int main(int ac, char **av) 
{
    if (ac == 2) {
        if (strcmp(av[1], "help") == 0)
        {
            printf("=======================================================================\n");
            printf(BYEL "Usage: ./a.out [Process Number] [1. String] [2. String]\n" reset);
            printf(BYEL "Process Numbers:\n" reset);
            printf(BYEL "1: strlen\n" reset);
            printf(BYEL "2: strcmp\n" reset);
            printf(BYEL "3: strcpy\n" reset);
            printf(BYEL "4: strdup\n" reset);
            printf(BYEL "5: write\n" reset);
            printf(BYEL "6: read\n" reset);
            printf(BYEL "7: all\n" reset);
            printf(BBLU "help: Show this message\n" reset);
            printf("=======================================================================\n");
            return 0;
        }
        else 
        {
            printf(BRED "Usage: ./a.out [Process Number or help] [1. String] [2. String]\n" reset);
            return 1;
        }
    }

    if (ac != 4)
    {
        printf(BRED "Usage: ./a.out [Process Number or help] [1. String] [2. String]\n" reset);
        return 1;
    }

    int process = atoi(av[1]);
    char *str1 = av[2];
    char *str2 = av[3];
    processWork(process, str1, str2);
}
