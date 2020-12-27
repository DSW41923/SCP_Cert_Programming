#include <stdio.h>
#include <stdlib.h>
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
        else if (strcmp(argv[1], "-b") == 0 || strcmp(argv[1], "--bad") == 0)
        {
            int * bad_pointer1 = malloc(-2048);
            printf("%ld\n", malloc_usable_size(bad_pointer1));
            int * bad_pointer2 = malloc(0);
            printf("%ld\n", malloc_usable_size(bad_pointer2));
            char * base_string = "string";
            char * copy_string;
            strncpy(copy_string, base_string, -5);
            printf("%s\n", copy_string);
            return 0;
        }
        else if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--string") == 0)
        {
            char * base_string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            char * copy_string;
            strncpy(base_string + 5, base_string, 26);
            printf("%s\n", copy_string);
            return 0;
        }
    }
    return 0;
}