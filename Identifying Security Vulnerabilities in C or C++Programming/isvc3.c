#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char * const argv[], char **envp)
{
    char *env_path = getenv("PATH");
    if (env_path != NULL)
    {
        printf("Current PATH is: %s\n", env_path);
    }
    else{
        printf("Error!\n");
    }
    putenv("PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin\nPATH=/usr/local/bin:/sbin:/bin:/usr/bin");
    printf("\n");
    for (char **env = envp; *env != 0; env++)
    {
        char *thisEnv = *env;
        printf("%s\n", thisEnv);    
    }
    printf("\n");
    char line[200];
    FILE* output = popen("/bin/sh -c printenv", "r");
    while ( fgets(line, 199, output) )
    {
        printf("%s", line);
    }
    printf("\n");
    if (execve("/usr/bin/printenv", argv, envp) < 0)
    {
        printf("Error!\n");
    }
    return 0;
}

