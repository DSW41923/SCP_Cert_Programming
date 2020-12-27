#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include "cwalk.h"


int trustfile(char * file)
{
    char full_path[PATH_MAX];
    if (file[0] == '~')
    {
        char cwd[PATH_MAX];
        getcwd(cwd, sizeof(cwd));
        cwk_path_get_absolute(cwd, file, full_path, PATH_MAX);
    }
    else
    {
        strcpy(full_path, file);
    }
    char * tokens[255];
    char * token = strtok(full_path, "/");
    int total_directories = 0;
    int trust_directories = 0;
    while( token != NULL ) {
        tokens[total_directories] = token;
        total_directories++;
        token = strtok(NULL, "/");
    }

    if (total_directories <= 1)
    {
        return 1;
    }

    for (int i = 0; i < total_directories; i++)
    {
        if (trustfile(tokens[i]) != 1){
            return 0;
        }
        trust_directories++;
    }

    if (total_directories == trust_directories)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 0;
}

int main(int argc, char * const argv[], char **envp)
{
    if (argc > 1)
    {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            printf("Suggested Activity of Course Identifying Security Vulnerabilities in C/C++Programming\n");
            printf("Practice cleaning out environments to make them safe for untrusted subprocesses\n");
            return 0;
        }
        else
        {
            printf("%d\n", trustfile(argv[1]));
        }
    }
    return 0;
}