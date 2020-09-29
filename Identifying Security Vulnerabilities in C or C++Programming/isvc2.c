#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char *env_path = getenv("PATH");
	printf("PATH is: %s\n", env_path);
	setenv("PATH", "/usr/local/bin:/sbin:/bin:/usr/bin", 1);
	printf("New PATH is: %s\n", getenv("PATH"));
	setenv("PATH", env_path, 1);
	return 0;
}