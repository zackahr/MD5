#include <string.h>
#include "ft_ssl.h"

static const t_command	g_commands[] = {
	{"md5", cmd_md5},
	{"sha256", cmd_sha256},
	{NULL, NULL},
};

int	dispatch(int argc, char **argv)
{
	int	i;

	i = 0;
	while (g_commands[i].name)
	{
		if (strcmp(g_commands[i].name, argv[1]) == 0)
			return (g_commands[i].run(argc - 1, argv + 1));
		i++;
	}
	return (unknown_command(argv[1]));
}
