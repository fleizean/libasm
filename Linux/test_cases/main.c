#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../includes/color.h"

extern int errno;

extern int _ft_strcmp(char *s1, char *s2);
extern char *_ft_strcpy(char *dest, char *src);
extern char *_ft_strdup(const char *s);
extern size_t _ft_strlen(const char *dest);
extern ssize_t _ft_write(int fd, const void *buf, size_t count);
extern ssize_t _ft_read(int fd, void *buf, size_t count);

void print_help_message() {
    printf("=========================================================================\n");
    printf(BYEL "Usage: ./a.out [Process Number] [1. String] [2. String] [File Path]\n" reset);
    printf(BBLU "[I]: If you use write or read, you must enter the file path.\n" reset);
    printf(BYEL "Process Numbers:\n" reset);
    printf(BYEL "1: strlen -> [Process Number] [1. String] [2. String]\n" reset);
    printf(BYEL "2: strcmp -> [Process Number] [1. String] [2. String]\n" reset);
    printf(BYEL "3: strcpy -> [Process Number] [1. String] [2. String]\n" reset);
    printf(BYEL "4: strdup -> [Process Number] [1. String] [2. String]\n" reset);
    printf(BYEL "5: write  -> [Process Number] [1. String] [2. String] [File Path]\n" reset);
    printf(BYEL "6: read   -> [Process Number] [1. String] [2. String] [File Path]\n" reset);
    printf(BYEL "7: all    -> [Process Number] [1. String] [2. String] [File Path]\n" reset);
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

void strlenTester(char *str1, char *str2)
{
    size_t len = strlen(str1);
    size_t len2 = _ft_strlen(str2);
    if (len == len2) {
        printf(BGRN "strlen -> OK\n" reset);
        printf(BBLU "[INF_TEST]:: strlen - %ld %s\n", len, reset);
        printf(BBLU "[INF_TEST]:: _ft_strlen - %ld %s\n", len2, reset);
    }
    else {
        printf(BRED "strlen -> KO\n" reset);
        printf(BRED "[INF_TEST]:: strlen - %ld %s\n", len, reset);
        printf(BRED "[INF_TEST]:: _ft_strlen - %ld %s\n", len2, reset);
    }
}

void strcpyTester(char *str1, char *str2)
{
    char *result = _ft_strcpy(str1, str2);
    char *result2 = strcpy(str1,str2);
    printf("ft_strcpy: %s\n", result);
    printf("strcpy: %s\n", result2);
    if (strcmp(strcpy(str1, str2), _ft_strcpy(str1, str2)) == 0)
        printf(BGRN "strcpy -> OK\n" reset);
    else
        printf(BRED "strcpy -> KO\n" reset);
}

void strdupTester(const char *str1, const char *str2)
{
    if (strcmp(strdup(str1), _ft_strdup(str2)) == 0) {
        printf(BGRN "strdup -> OK\n" reset);
    }
    else
        printf(BRED "strdup -> KO\n" reset);
}

void strcmpTester(char *str1, char *str2)
{
    if (strcmp(str1, str2) == strcmp(str1, str2))
        printf(BGRN "strcmp -> OK\n" reset);
    else
        printf(BRED "strcmp -> KO\n" reset);
}

void writeTester(char *str1, char *file_path)
{
    // Test 1: stdout ile yazma
    ssize_t result1 = write(STDOUT_FILENO, str1, strlen(str1));
    ssize_t ft_result1 = _ft_write(STDOUT_FILENO, str1, strlen(str1));
    if (result1 != -1 && ft_result1 != -1 && result1 == ft_result1) {
        printf(BGRN "\nwrite [write - stdout test]  -> OK\n" reset);
        printf(BBLU "[INF_TEST]:: write - %ld %s\n", result1, reset);
        printf(BBLU "[INF_TEST]:: _ft_write - %ld %s\n", ft_result1, reset);
    } else {
        printf(BRED "\nwrite [write - stdout test]  -> KO: %s%s\n", strerror(errno), reset);
    }
    errno = 0;
    // Test 2: Dosya tanımlayıcısı ile yazma
    int fd = open(file_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd != -1) {
        bool result = ((size_t)write(fd, str1, strlen(str1)) == strlen(str1)) && ((size_t)_ft_write(fd, str1, strlen(str1)) == strlen(str1));
        if (result == true)
            printf(BGRN "write [open and write test]  -> OK\n" reset);
        else
            printf(BRED "write [open and write test]  -> KO: %s%s\n", strerror(errno), reset);
        close(fd);
    } else {
        printf(BRED "[open and write test] Failed to open file: %s%s\n", strerror(errno), reset);
    }
    errno = 0;
    // Test 3: Yanlış dosya tanımlayıcısı ile yazma
    int wrong_fd = open("pqweqwe.txt", O_RDONLY);; // Yanlış dosya tanımlayıcısı

    ssize_t val5 = write(wrong_fd, str1, 40);
    ssize_t val6 = _ft_write(wrong_fd, str1, 40);
    
    if (val5 == val6) {
        printf(BGRN "write [wrong_fd test]        -> OK %s%s\n", strerror(errno), reset);
        printf(BBLU "[INF_TEST]:: write - %ld %s\n", val5, reset);
        printf(BBLU "[INF_TEST]:: _ft_write - %ld %s\n", val6, reset);
    }
    else
        printf(BRED "write [wrong_fd test]        -> KO: %s%s\n", strerror(errno), reset);
}

void readTester(char *file_path) {
    char buf1[50], buf2[50];
    ssize_t val1 = read(STDIN_FILENO, buf1, 40);
    ssize_t val2 = _ft_read(STDIN_FILENO, buf2, 40);

    if (val1 == val2) {
        printf(BGRN "read  [read - stdin test]  -> OK\n" reset);
    } else {
        printf(BRED "read [read - stdin test]   -> KO: %s\n" reset, strerror(errno));
        printf(BBLU "[INF_TEST]:: read - %ld\n" reset, val1);
        printf(BBLU "[INF_TEST]:: _ft_read - %ld\n" reset, val2);
    }

    // Test 2: Dosya tanımlayıcısı ile okuma
    int fd = open(file_path, O_RDONLY);
    int fd2 = open(file_path, O_RDONLY);
    char *buf3 = malloc(sizeof(char) * 50);
    char *buf4 = malloc(sizeof(char) * 50);
    ssize_t val3 = read(fd, buf3, 40);
    ssize_t val4 = _ft_read(fd2, buf4, 40);
    if (val3 == val4) {
        printf(BGRN "read [open and read test]   -> OK\n" reset);
    } else {
        printf(BRED "read [open and read test]   -> KO: %s\n" reset, strerror(errno));
        printf(BBLU "[INF_TEST]:: read - %ld\n" reset, val3);
        printf(BBLU "[INF_TEST]:: _ft_read - %ld\n" reset, val4);
    }
    free(buf3);
    free(buf4);
    close(fd);
    close(fd2);

    // Test 3: Yanlış dosya tanımlayıcısı ile okuma
    int wrong_fd = open("", O_RDONLY); // Yanlış dosya tanımlayıcısı
    char *buf5 = malloc(sizeof(char) * 50);
	char *buf6 = malloc(sizeof(char) * 50);
    ssize_t val5 = read(wrong_fd, buf5, 40);
    ssize_t val6 = _ft_read(wrong_fd, buf6, 40);
    if (val5 == val6) {
        printf(BGRN "read [wrong_fd test]   -> OK: %s\n" reset, strerror(errno));
    } else {
        printf(BRED "read [wrong_fd test]   -> KO: %s\n" reset, strerror(errno));
        printf(BBLU "[INF_TEST]:: read - %ld\n" reset, val5);
        printf(BBLU "[INF_TEST]:: _ft_read - %ld\n" reset, val6);
    }
    free(buf5);
	free(buf6);
}

int processWork(int process, char *str1, char *str2, char *file_path)
{
    char *processes[] = {"strlen", "strcmp", "strcpy", "strdup", "write", "read", "all"};

    printf("=========================================================================\n");
    printf(BYEL "Testing :: %s\n" reset, processes[process - 1]);
    printf("=========================================================================\n");

    switch (process)
    {
    case 1:
        strlenTester(str1, str2);
        break;
    case 2:
        strcmpTester(str1, str2);
        break;
    case 3:
        strcpyTester(str1, str2);
        break;
    case 4:
        strdupTester(str1, str2);
        break;
    case 5:
        writeTester(str1, file_path);
        break;
    case 6:
        readTester(file_path);
        break;
    case 7:
        strlenTester(str1, str2);
        strcmpTester(str1, str2);
        strcpyTester(str1, str2);
        strdupTester(str1, str2);
        writeTester(str1, file_path);
        readTester(file_path);
        break;
    default:
        print_usage_error();
        return 0;
    }
    printf("=========================================================================\n");
    return 0;
}

/*
    Usage:
    # ./a.out <Process Number> <1. String> <2. String> <File Path>
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

    int process = atoi(av[1]);
    if (!checkProcessNumber(process))
    {
        print_usage_error();
        return 1;
    }

    if ((process >= 5 && process <= 7 && ac != 5) || (process < 5 && ac != 4))
    {
        print_usage_error();
        return 1;
    }
    
    char *str1 = av[2];
    char *str2 = av[3];
    char *file_path = av[4];

    processWork(process, str1, str2, file_path);

    return 0;
}
