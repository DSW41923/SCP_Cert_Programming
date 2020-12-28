#include <crypt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/stdlib.h>


int main(int argc, char * const argv[], char **envp)
{
    if (argc > 1)
    {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            printf("Suggested Activity of Course Identifying Security Vulnerabilities in C/C++Programming\n");
            printf("Hash a password and then try to guess another one\n");
            return 0;
        }
        else if (strcmp(argv[1], "-a") == 0)
        {
            char pwd[255];
            printf("Enter a password: ");
            scanf("%s", pwd);
            char * salt_char = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";
            char salt[2];
            for (int i = 0; i < 2; ++i)
            {
                int random_digit = arc4random() % strlen(salt_char);
                salt[i] = salt_char[random_digit];
            }
            printf("%s\n", salt);
            char * hash = crypt(pwd, salt);
            printf("%s\n", pwd);
            printf("%s\n", hash);
        }
        else if (strcmp(argv[1], "-b") == 0)
        {
            char * target_hash = "$5$j9tpEQAJ$CPAvrEFShAWz5k2C/e2b1Lsux2VOE0wOQFX4lfu0128";
            char * salt = "$5$j9tpEQAJ$";
            FILE *dict;
            char buff[255];
            dict = fopen("/usr/share/dict/words", "r");
            fgets(buff, 255, (FILE*)dict);
            while(buff != NULL)
            {
                buff[strlen(buff) - 1] = 0;
                char * hash = crypt(buff, salt);
                if (strcmp(hash, target_hash) == 0)
                {
                    printf("%s\n", buff);
                    break;
                }
                else
                {
                    fgets(buff, 255, (FILE*)dict);
                }
            }
            fclose(dict);
        }
    }
    return 0;
}