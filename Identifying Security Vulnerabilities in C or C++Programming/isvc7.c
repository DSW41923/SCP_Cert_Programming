#include <stdio.h>
#include <bsd/stdlib.h>
#include <malloc.h>
#include <string.h>


int main(int argc, char * const argv[], char **envp)
{
    if (argc > 1)
    {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            printf("Suggested Activity of Course Identifying Security Vulnerabilities in C/C++Programming\n");
            printf("See what happens when calling functions with parameters that cause overflows\n");
            return 0;
        }
        else if (strcmp(argv[1], "--arc4random") == 0)
        {
            int digit_count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (int i = 0; i < 100000; ++i)
            {
                int random_digit = arc4random() % 10;
                digit_count[random_digit]++;
            }
            for (int i = 0; i < 10; ++i)
            {
                printf("%d: %d\n", i, digit_count[i]);
            }
        }
        else if (strcmp(argv[1], "--rand") == 0)
        {
            int digit_count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (int i = 0; i < 100000; ++i)
            {
                int random_digit = rand() % 10;
                digit_count[random_digit]++;
            }
            for (int i = 0; i < 10; ++i)
            {
                printf("%d: %d\n", i, digit_count[i]);
            }
        }
        else if (strcmp(argv[1], "--random") == 0)
        {
            int digit_count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (int i = 0; i < 100000; ++i)
            {
                int random_digit = random() % 10;
                digit_count[random_digit]++;
            }
            for (int i = 0; i < 10; ++i)
            {
                printf("%d: %d\n", i, digit_count[i]);
            }
        }else if (strcmp(argv[1], "--lrand48") == 0)
        {
            int digit_count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (int i = 0; i < 100000; ++i)
            {
                int random_digit = lrand48() % 10;
                digit_count[random_digit]++;
            }
            for (int i = 0; i < 10; ++i)
            {
                printf("%d: %d\n", i, digit_count[i]);
            }
        }
    }
    return 0;
}