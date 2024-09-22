#include "pipex.h"

int	main(void)
{
	char	*string = "awk '{ if (length($0) > max) max = length($0) } END { print max }'";
	char	**cmds;
	int		i = 0;

	cmds = ft_split_adapt(string, ' ');
	while (cmds[i] != NULL)
	{
		printf("cmds[%d]:%s|\n", i, cmds[i]);
		i++;
	}
}