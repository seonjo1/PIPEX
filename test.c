#include "pipex.h"

int main(void)
{
	char	*cmd[3];

	cmd[0] = "/bin/ls";
	cmd[1] = "-ld2";
	cmd[2] = NULL;
	execve("/bin/ls", cmd, NULL);
}