#include "pipex.h"

int	main(void)
{
	char	*string = "sed 's/hello/world/'";
	char	**cmds;
	int		i = 0;

	cmds = ft_split(string, ' ');
	while (cmds[i] != NULL)
	{
		printf("cmds[%d]:%s|\n", i, cmds[i]);
		i++;
	}
}