#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>


char *fixpath(char *path){

    char cwd[PATH_MAX];
    char * can_path = malloc(PATH_MAX);
    memset(can_path, '\0', PATH_MAX);
    int ignore = 0;
    char * token = strtok(path, "/");
    while( token != NULL ) {

        if (strcmp(token, ".") == 0)
        {
            if (getcwd(cwd, sizeof(cwd)) != NULL)
            {
                can_path = strcat(can_path, cwd);
                can_path = strcat(can_path, "/");
            }
        }
        else if (strcmp(token, "..") == 0)
        {
            ignore++;
        }
        else if (token[0] == '~')
        {
            char * account_name = token + 1;
            char * account_path = malloc(PATH_MAX);
            strcpy( account_path, "/home/" );
            account_path = strcat(account_path, account_name);
            can_path = strcat(can_path, account_path);
            can_path = strcat(can_path, "/");
        }
        else
        {
            if (ignore > 0)
            {
                ignore--;
            }
            else
            {
                can_path = strcat(can_path, token);
                can_path = strcat(can_path, "/");
            }
        }
    
        token = strtok(NULL, "/");
    }
    if (can_path[0] != '/')
    {
        char * can_path_prefix = malloc(PATH_MAX);
        strcpy(can_path_prefix, "/" );
        can_path = strcat(can_path_prefix, can_path);
    }
    return can_path;
}

int main(int argc, char * const argv[], char **envp)
{
    if (argc > 1)
    {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            printf("Suggested Activity of Course Identifying Security Vulnerabilities in C/C++Programming\n");
            printf("Translate the given path into a fully canonicalized path name\n");
            return 0;
        }
        else{
            char * path = fixpath(argv[1]);
            printf("%s\n", path);
        }
    }
    return 0;
}