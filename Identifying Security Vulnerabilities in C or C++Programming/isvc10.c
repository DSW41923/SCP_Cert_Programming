#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

int natol_errno = 0;

int natoi(char *str)
{
    int value = 0;
    bool accept_space = true;
    bool accept_plus = true, accept_minus = true;
    bool minus = false;
    for (int i = 0; i < strlen(str); ++i)
    {
        if (isdigit(str[i]) > 0)
        {
            
            if (accept_space && value > 0)
            {
                natol_errno = 1;
                break;
            }
            else{
                accept_space = false;
                accept_plus = false;
                accept_minus = false;
                if (value > 10000)
                {
                    if (minus){
                        if (INT_MIN / -value < 10 || ((INT_MIN / -value == 10) && (INT_MIN + value * 10 > -str[i])))
                        {
                            natol_errno = 3;
                        }
                    }
                    else
                    {
                        if (INT_MAX / value < 10 || ((INT_MAX / value == 10) && (INT_MAX - value * 10 < str[i])))
                        {
                            natol_errno = 2;
                        }
                    }
                }
                value = value * 10 + (str[i] - 48);
            }
        }
        else{
            if (str[i] == ' ')
            {
                if (!accept_space)
                {
                    accept_space = true;
                }
            }
            else if ((str[i] == '+') && accept_plus)
            {
                accept_plus = false;
            }
            else if ((str[i] == '-') && accept_minus)
            {
                accept_minus = false;
                minus = true;
            }
            else
            {
                natol_errno = 1;
                break;
            }
        }
    }
    if (minus)
    {
        value = value * -1;
    }
    return value;
}


int main(int argc, char * const argv[], char **envp)
{
    if (argc > 1)
    {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            printf("Suggested Activity of Course Identifying Security Vulnerabilities in C/C++Programming\n");
            printf("Cleaning out environments to make them safe for untrusted subprocesses\n");
            return 0;
        }
        else 
        {
            printf("%d\n", natoi(argv[1]));
            printf("%d\n", natol_errno);
        }
    }
    return 0;
}