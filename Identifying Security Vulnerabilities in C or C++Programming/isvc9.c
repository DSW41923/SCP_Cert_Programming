#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>


extern char **environ;


int main(int argc, char * const argv[])
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
            sigset_t mask;
            sigfillset(&mask);
            sigprocmask(SIG_SETMASK, &mask, NULL);
            if (fork() == 0)
            {
                sigprocmask(SIG_UNBLOCK, &mask, NULL);
                char *env_shell = getenv("SHELL");
                if (env_shell == NULL)
                {
                    env_shell = "/bin/sh";
                }
                clearenv();
                char *new_env_path = "PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/bin:/usr/local/sbin:/usr/local/bin";
                char *new_env_ifs = "IFS=$' \t\n'";
                char *new_env_shell = malloc(strlen(env_shell) + 6);
                strcpy( new_env_shell, "SHELL=" );
                new_env_shell = strcat(new_env_shell, env_shell);
                putenv(new_env_path);
                putenv(new_env_ifs);
                putenv(new_env_shell);
                umask(0770);

                if (execve(argv[1], argv + 1, environ) < 0)
                {
                    printf("Error!\n");
                }
                return 0;
            }
            else
            {
                printf("Waited!\n"); 
                int * waitstatus;
                wait(waitstatus);
                sigprocmask(SIG_UNBLOCK, &mask, NULL);
            }
        }
    }
    return 0;
}