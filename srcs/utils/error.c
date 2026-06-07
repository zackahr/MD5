#include <stdio.h>
#include "ft_ssl.h"

int	usage(void)
{
	fprintf(stderr, "usage: ft_ssl command [flags] [file/string]\n");
	return (1);
}

int	unknown_command(const char *name)
{
	fprintf(stderr, "ft_ssl: Error: '%s' is an invalid command.\n", name);
	return (1);
}
