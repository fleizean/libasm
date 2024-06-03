#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "../includes/color.h"

extern int _ft_strcmp(char *s1, char *s2);
extern char *_ft_strcpy(char *dest, char *src);
extern char *_ft_strdup(char *src);
extern int _ft_strlen(char *dest);

void print_help_message() {
    printf("=========================================================================\n");
    printf(BYEL "Usage: ./a.out [Process Number] [1. String] [2. String] [File Path]\n" reset);
    printf(BBLU "[I]: If you write or read, you must enter the file path.\n" reset);
    printf(BYEL "Process Numbers:\n" reset);
    printf(BYEL "1: strlen\n" reset);
    printf(BYEL "2: strcmp\n" reset);
    printf(BYEL "3: strcpy\n" reset);
    printf(BYEL "4: strdup\n" reset);
    printf(BYEL "5: write\n" reset);
    printf(BYEL "6: read\n" reset);
    printf(BYEL "7: all\n" reset);
    printf(BBLU "help: Show this message\n" reset);
    printf("=========================================================================\n");
}

void print_usage_error() {
    printf(BRED "Usage: ./a.out [Process Number or help] [1. String] [2. String]\n" reset);
}

bool checkProcessNumber(int process)
{
    return process >= 1 && process <= 7;
}

void strlenTester(char *str1)
{
    if (strlen(str1) == strlen(str1))
        printf(BGRN "strlen -> OK\n" reset);
    else
        printf(BRED "strlen -> KO\n" reset);
}

void strcmpTester(char *str1, char *str2)
{
    if (strcmp(str1, str2) == strcmp(str1, str2))
        printf(BGRN "strcmp -> OK\n" reset);
    else
        printf(BRED "strcmp -> KO\n" reset);
}

void strcpyTester(char *str1, char *str2)
{
    if (strcmp(strcpy(str1, str2), strcpy(str1, str2)) == 0)
        printf(BGRN "strcpy -> OK\n" reset);
    else
        printf(BRED "strcpy -> KO\n" reset);
}

void strdupTester(char *str1)
{
    if (strcmp(strdup(str1), strdup(str1)) == 0)
        printf(BGRN "strdup -> OK\n" reset);
    else
        printf(BRED "strdup -> KO\n" reset);
}


void writeTester(char *str1, char *file_path)
{
    int fd = open(file_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if ((size_t)write(fd, str1, strlen(str1)) == strlen(str1))
        printf(BGRN "write  -> OK\n" reset);
    else
        printf(BRED "write  -> KO\n" reset);
}

void readTester(char *str1, char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    char *buffer = malloc(sizeof(char) * strlen(str1));
    if ((size_t)read(fd, buffer, strlen(str1)) == strlen(str1)) {
        // printf(BBLU "read result :: %s\n%s", buffer, reset);
        printf(BGRN "read   -> OK\n" reset);
    }
    else
        printf(BRED "read   -> KO\n" reset);
}

int processWork(int process, char *str1, char *str2, char *file_path)
{
    char **processes = (char *[]){"strlen", "strcmp", "strcpy", "strdup", "write", "read", "all"};

    printf("=========================================================================\n");
    printf(BYEL "Testing :: %s\n" reset, processes[process - 1]);
    printf("=========================================================================\n");

    switch (process)
    {
    case 1:
        strlenTester(str1);
        break;
    case 2:
        strcmpTester(str1, str2);
        break;
    case 3:
        strcpyTester(str1, str2);
        break;
    case 4:
        strdupTester(str1);
        break;
    case 5:
        writeTester(str1, file_path);
        break;
    case 6:
        readTester(str1, file_path);
        break;
    case 7:
        strlenTester(str1);
        strcmpTester(str1, str2);
        strcpyTester(str1, str2);
        strdupTester(str1);
        writeTester(str1, file_path);
        readTester(str1, file_path);
        break;
    default:
        print_usage_error();
        return 0;
    }
    printf("=========================================================================\n");
    return 0;
}

/*
    Kullanım:
    # ./a.out <Process Number> <1. String> <2. String>
    # ./a.out <help>
*/
int main(int ac, char **av)
{
    if (ac == 2)
    {
        if (strcmp(av[1], "help") == 0)
        {
            print_help_message();
            return 0;
        }
        else
        {
            print_usage_error();
            return 1;
        }
    }

    if (ac != 5 || !checkProcessNumber(atoi(av[1])))
    {
        print_usage_error();
        return 1;
    }
    int process = atoi(av[1]);
    char *str1 = av[2];
    char *str2 = av[3];
    char *file_path = av[4];
    processWork(process, str1, str2, file_path);
}