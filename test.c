#include "pipex.h"
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
	int i = argc - argc;
	argv[0] = "hello";
	while (envp[i] != NULL)
		printf("%s\n", envp[i++]);
}
